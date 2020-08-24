/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:18:39 by dthan             #+#    #+#             */
/*   Updated: 2020/07/27 18:42:36 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line_edition.h"

/*** terminal ***/

void disableRawMode() {
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios);
}

void enableRawMode() {
	struct termios raw;

	tcgetattr(STDIN_FILENO, &E.orig_termios);
	raw = E.orig_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

/*******************/

int readKey() {
	int nread;
	char c;
	while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
		;
		// if (nread == -1 && errno != EAGAIN) die("read");
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

void abAppend(t_buffer *ab, char *s) {
	ab->str = ft_strjoin_and_free_string1(ab->str, s);
	ab->len = ft_strlen(ab->str);
}

void abFree(t_buffer *ab) {
	free(ab->str);
}

/*** output ***/

/** under construction
void findTempStr(char **tempStr, int *tempSize)
{
	if (E.rowoff == 0){
		*tempStr = E.row.chars;
		*tempSize = E.row.size;
	}
	else {
		int tempRowOff = E.rowoff;
		int i = E.screencols - E.cx0;
		while (tempRowOff > 1)
		{
			// line with promt
			tempRowOff--;
			i += E.screencols;
		}
		*tempStr = &E.row.chars[i - 1];
		*tempSize = E.row.size - i;
	}
}
*/

void refreshLineEditor(t_line line) {
	t_buffer appendingBuffer  = ABUF_INIT;

	// hinding the cursor
	abAppend(&appendingBuffer, "\x1b[?25l");
	// reposition to the starting point of cursor into the terminal
	char buf[32];
	ft_bzero(buf, 32);
	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cursor.startPos.cy, E.cursor.startPos.cx);
	abAppend(&appendingBuffer, buf);
	// clear from the cursor position to the end of screen
	abAppend(&appendingBuffer, "\x1b[0J");
	
	/**under construction
	need to find the position of the string to print
	t_tempstr temp;
	temp.tempStr = NULL;
	temp.tempStr = 0;
	findTempStr(&temp.tempStr, &temp.tempSize);
	abAppend(&ab, temp.tempStr, temp.tempSize);
	*/

	// writing the line into the buffer
	abAppend(&appendingBuffer, line.str);
	if (E.cursor.currentPos.cx == E.screencols && E.cursor.currentPos.cy == E.screenrows) //at the right bottom corner
		abAppend(&appendingBuffer, "\r\n");
	// repositioning the cursor into the terminal corespoding to the line
	char buf2[32];
	ft_bzero(buf2, 32);
	snprintf(buf2, sizeof(buf), "\x1b[%d;%dH", E.cursor.currentPos.cy, E.cursor.currentPos.cx);
	abAppend(&appendingBuffer, buf2);
	// turn on the visibility of the cursor
	abAppend(&appendingBuffer, "\x1b[?25h");
	// write the appending buffer to the terminal
	write(STDOUT_FILENO, appendingBuffer.str, appendingBuffer.len);
	// free the appending buffer
	abFree(&appendingBuffer);
}

/*** input ***/

void updateCursorPos(int *cx, int *cy)
{
	// *cx = E.cursor.startPos.cx + E.cursor.atLine % E.screencols;
	// *cy = E.cursor.startPos.cy + E.cursor.atLine / E.screencols;
	// if (*cx > E.screencols)
	// {
	// 	*cx %= E.screencols;
	// 	if (*cy < E.screenrows)
	// 		(*cy)++;
	// 	else
	// 		*cy = E.screenrows;
	// }

	*cx = (E.cursor.startPos.cx + E.cursor.atLine) % E.screencols;
	if (*cx == 0)
		*cx = E.screencols;
	*cy = E.cursor.startPos.cy + ((E.cursor.startPos.cx + E.cursor.atLine - 1) / E.screencols);
	// if off-screen
}

void insertChar(t_line *line, int c)
{
	char *new;

	new = ft_strnew(ft_strlen(line->str) + 1);
	new = ft_strcpy(new, line->str);
	ft_memmove(&new[E.cursor.atLine + 1], &new[E.cursor.atLine], line->len - E.cursor.atLine + 1);
	new[E.cursor.atLine] = c;
	free(line->str);
	line->str = new;
	line->len++;
	E.cursor.atLine++;
	updateCursorPos(&E.cursor.currentPos.cx, &E.cursor.currentPos.cy);
}

void delChar(t_line *line)
{
	char *new;

	ft_memmove(&line->str[E.cursor.atLine - 1], &line->str[E.cursor.atLine], line->len - E.cursor.atLine + 1);
	new = ft_strdup(line->str);
	free(line->str);
	line->str = new;
	line->len--;
}

// void editorMoveCursor(int key) {
// 	switch (key) {
// 		case ARROW_LEFT:
// 			if (E.cx != E.cx0) {
// 				E.cx--;
// 			}
// 			break;
// 		case ARROW_RIGHT:
// 			if (E.cx != E.screencols - 1) {
// 				E.cx++;
// 			} else {
// 				E.cx = 0;
// 				E.cy++;
// 			}
// 			break;
// 		case ARROW_UP:
// 			if (E.cy != E.cy0) {
// 				E.cy--;
// 			}
// 			break;
// 		case ARROW_DOWN:
// 			if (E.cy != E.screenrows - 1) {
// 				E.cy++;
// 			}
// 			break;
// 	}
// }

int processKeyPress(t_line *line) {
	int c = readKey();

	switch (c) {
		// case BACKSPACE:
		// case DEL_KEY:
		// if (c == DEL_KEY) editorMoveCursor(ARROW_RIGHT);
		// 	editorDelChar(&E.row, E.cx - E.cx0);
		// 	break;
		// case ARROW_UP:
		// case ARROW_DOWN:
		// case ARROW_LEFT:
		// case ARROW_RIGHT:
		// 	editorMoveCursor(c);
		// 	break;
		case '\r':
			return 1;
		default:
			insertChar(line, c);
			break;
	}
	return (0);
}


/**** init ******/

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

void initLineEditor() {

	get_current_cursor(&E.cursor.startPos.cx, &E.cursor.startPos.cy);
	E.cursor.currentPos.cx = E.cursor.startPos.cx;
	E.cursor.currentPos.cy = E.cursor.startPos.cy;
	E.cursor.atLine = 0;
	getWindowSize(&E.screenrows, &E.screencols);
}

/*********************/

char	*ft_getline(void)
{
	t_line	line;

	line.str = ft_strdup("");
	line.len = 0;
	enableRawMode(); //enable for orig_termios
	initLineEditor();
	while (1) {
		// updateEditor();
		refreshLineEditor(line);
		if (processKeyPress(&line))
			break;
	}
	disableRawMode();
	write(1, "\n", 1);
	return (line.str);
}
