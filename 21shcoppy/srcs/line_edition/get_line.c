/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:18:39 by dthan             #+#    #+#             */
/*   Updated: 2020/07/22 04:39:04 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line_edition.h"

/*** terminal ***/

void die(const char *s) {
	perror(s);
	exit(1);
}

void disableRawMode() {
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios);
}

void enableRawMode() {
	if (tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) die("tcgetattr");
	struct termios raw = E.orig_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

int editorReadKey() {
	int nread;
	char c;
	while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
		if (nread == -1 && errno != EAGAIN) die("read");
	}

	if (c == '\x1b') {
		char seq[3];

		if (read(STDOUT_FILENO, &seq[0], 1) != 1) return '\x1b';
		if (read(STDOUT_FILENO, &seq[1], 1) != 1) return '\x1b';

		if (seq[0] == '[') {
			if (seq[1] >= '0' && seq[1] <= '9') {
				if (read(STDIN_FILENO, &seq[2], 1) != 1) return '\x1b';
				if (seq[2] == '~') {
					switch (seq[1]) {
						case '3': return DEL_KEY;
						//.... for more
					}
				}
			} else {
				switch (seq[1]) {
					case 'A' : return ARROW_UP;
					case 'B' : return ARROW_DOWN;
					case 'C' : return ARROW_RIGHT;
					case 'D' : return ARROW_LEFT;
				}
			}
		}
		return '\x1b';
	} else {
		return c;
	}


	return c;
}

int getWindowSize(int *rows, int *cols) {
	struct winsize ws;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
		return -1;
	} else {
	*cols = ws.ws_col;
	*rows = ws.ws_row;
	return 0;
	}
}

/*** append buffer ***/

void abAppend(struct abuf *ab, const char *s, int len) {
	char *new = realloc(ab->b, ab->len + len);

	if (new == NULL) return ;
	memcpy(&new[ab->len], s, len);
	ab->b = new;
	ab->len += len;
}

void abFree(struct abuf *ab) {
	free(ab->b);
}

/*** output ***/

void editorRefreshScreen() {
	struct abuf ab = ABUF_INIT;

	abAppend(&ab, "\x1b[?25l", 6);
	
	char buf[32];
	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cy0, E.cx0);
	abAppend(&ab, buf, strlen(buf));

	abAppend(&ab, "\x1b[0J", 4); // clear from cursor to end of screen
	abAppend(&ab, E.row.chars, E.row.size);

	char buf2[32];
	snprintf(buf2, sizeof(buf), "\x1b[%d;%dH", E.cy, E.cx);
	abAppend(&ab, buf2, strlen(buf));

	abAppend(&ab, "\x1b[?25h", 6);
	
	write(STDOUT_FILENO, ab.b, ab.len);
	abFree(&ab);
}

/*** input ***/

void editorInsertChar(erow *row, int at, int c)
{
	if (!row->chars)
		row->chars = ft_strdup("");
	if (at < 0 || at > row->size) at = E.row.size;
	row->chars = realloc(row->chars, row->size + 2);
	memmove(&row->chars[at + 1], &row->chars[at], row->size - at + 1);
	row->size++;
	row->chars[at] = c;
	if (E.cx < E.screencols) {
		E.cx++;
	} else {
		E.cx = 1;
		E.cy++;
	}
	if (E.cy > E.screenrows) {
		E.cy0--;
		E.cy--;
	}
}

void editorDelChar(erow *row, int at)
{
	if (at > 0) {
	if (at < 0 || at > row->size) return ;
	memmove(&row->chars[at - 1], &row->chars[at], row->size - at + 1);
	row->size--;
	E.cx--;
	} // there must be else
}

void editorMoveCursor(int key) {
	switch (key) {
		case ARROW_LEFT:
			if (E.cx != E.cx0) {
				E.cx--;
			}
			break;
		case ARROW_RIGHT:
			if (E.cx != E.screencols - 1) {
				E.cx++;
			} else {
				E.cx = 0;
				E.cy++;
			}
			break;
		case ARROW_UP:
			if (E.cy != E.cy0) {
				E.cy--;
			}
			break;
		case ARROW_DOWN:
			if (E.cy != E.screenrows - 1) {
				E.cy++;
			}
			break;
	}
}

int editorProcessKeyPress() {
	int c = editorReadKey();

	switch (c) {
		case CTRL_KEY('q'):
			printf("ctrl-q"); // need to change or fix
			break;
		case BACKSPACE:
		case DEL_KEY:
		if (c == DEL_KEY) editorMoveCursor(ARROW_RIGHT);
			editorDelChar(&E.row, E.cx - E.cx0);
			break;
		case ARROW_UP:
		case ARROW_DOWN:
		case ARROW_LEFT:
		case ARROW_RIGHT:
			editorMoveCursor(c);
			break;
		case '\r':
			return 1;
		default:
			editorInsertChar(&E.row ,E.cx - E.cx0, c);
			break;
	}
	return (0);
}

/*** init ***/

void get_current_cursor(int *cx, int *cy)
{
	int i, pow;
	char ch;
	char buf[30] = {0};

	*cx = 0;
	*cy = 0;
	write(1, "\033[6n", 4);
	for( i = 0, ch = 0; ch != 'R'; i++ )
	{
		fflush(STDIN_FILENO);
		read(0, &ch, 1);
		buf[i] = ch;
	}
	for( i -= 2, pow = 1; buf[i] != ';'; i--, pow *= 10)
		*cx = *cx + ( buf[i] - '0' ) * pow;

	for( i-- , pow = 1; buf[i] != '['; i--, pow *= 10)
		*cy = *cy + ( buf[i] - '0' ) * pow;
}

void initEditor() {

	get_current_cursor(&E.cx0, &E.cy0);
	E.cx = E.cx0;
	E.cy = E.cy0;
	E.rowoff = 0;
	E.row.chars = NULL;
	E.row.size = 0;
	E.numrows = 0;
	if (getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
	if (E.cx0 > E.screencols)
		E.cx0--;
}

char	*ft_getline(void)
{	
	enableRawMode();
	initEditor();
	while (1) {
		// updateEditor();
		editorRefreshScreen();
		if (editorProcessKeyPress())
			break;
	}
	disableRawMode();
	write(1, "\n", 1);
	return (E.row.chars);
}
