#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <ctype.h>
#include <term.h>
#include <sys/ioctl.h>
#define CTRL_KEY(k) ((k) & 0x1f)

enum key {
	BACKSPACE = 127,
	ARROW_LEFT = 1000,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	DEL_KEY,
	HOME_KEY,
	END_KEY,
	PAGE_UP,
	PAGE_DOWN
};


typedef struct s_term {
	size_t	TerminalRow;
	size_t	TerminalCol;
	size_t	startRow;
	size_t  startCol;
	struct termios orig;
}				t_term;

t_term terminal;

typedef struct s_line
{
	size_t length;
	size_t cursor;
}				t_line;;

int		charToTerm(int c)
{
	return (write(0, &c, 1));
}

void	disableRawMode(struct termios orig)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);
}

struct termios enableRawMode()
{
	struct termios orig;
	struct termios raw;

	tcgetattr(STDIN_FILENO, &orig);
	raw = orig;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	return (orig);
}

int arrowKey(char c)
{
	if (c == 'A')
		return (ARROW_UP);
	else if (c == 'B')
		return (ARROW_DOWN);
	else if (c == 'C')
		return (ARROW_RIGHT);
	else if (c == 'D')
		return (ARROW_LEFT);
	return (0);
}

int getKey(void)
{
	int nread;
	char c;
	char seq[3];

	while ((nread = read(STDIN_FILENO, &c, 1) != 1))
		;
	if (c == '\x1b')
	{
		if (read(STDIN_FILENO, &seq[0], 1) != 1)
			return ('\x1b');
		if (read(STDIN_FILENO, &seq[1], 1) != 1)
			return ('\x1b');
		if (seq[0] == '[')
		{
			if (seq[1] >= '0' && seq[1] <= '9')
			{
				if (read(STDIN_FILENO, &seq[1], 1) != 1)
					return ('\x1b');
			}
			else if (arrowKey(seq[1]))
				return (arrowKey(seq[1]));
		}
		// else if (seq[0] == '0')
		return '\x1b';
	}
	else
		return (c);
}

void moveCursor(int c, t_line *line)
{
	if (c == ARROW_UP)
	{
		; //todo
	}
	else if (c == ARROW_DOWN)
	{
		; //todo
	}
	else if (c == ARROW_LEFT)
	{
		if (line->cursor == 0)
			return;
		line->cursor--;
		int x;
		int y;
		x = terminal.startCol + line->cursor % terminal.TerminalCol;
		y = terminal.startRow + line->cursor / terminal.TerminalCol;
		tputs(tgoto(tgetstr("cm", NULL), 1, 10), 0, charToTerm);
	}
	else if (c == ARROW_RIGHT)
	{
		if (line->cursor == line->length)
			return;
		line->cursor++;
		int x;
		int y;
		x = terminal.startCol + line->cursor % terminal.TerminalCol;
		y = terminal.startRow + line->cursor / terminal.TerminalCol;
		tputs(tgoto(tgetstr("cm", NULL), x, y), 0, charToTerm);
	}
}

void insertChar(int c, t_line *line)
{
	tputs(tgetstr("im", NULL), 1, charToTerm);
	write(STDIN_FILENO, &c, 1);
	tputs(tgetstr("ei", NULL), 1, charToTerm);
	line->length++;
	line->cursor++;
}

void ProcessKeyPress(t_line *line)
{
	int c = getKey();

	if (c == CTRL_KEY('q'))
	{	
		disableRawMode(terminal.orig);
		exit(0);
	}
	else if (c == ARROW_UP || c == ARROW_DOWN || c == ARROW_LEFT || c == ARROW_RIGHT)
		moveCursor(c, line);
	else if (isprint(c))
		insertChar(c, line);
}

void getTermSize(size_t *terminalCol, size_t *terminalRow)
{
	struct winsize w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	*terminalCol = w.ws_col;
	*terminalRow = w.ws_row;
}

void getCursorPos(size_t *col, size_t *row)
{
	char buf[30];
	int i;

	bzero(buf, 30);
	write(STDOUT_FILENO, "\e[6n", 4);
	read(STDIN_FILENO, buf, 30);
	*row = atoi(&buf[2]);
	i = 2;
	while (isdigit(buf[i]))
		i++;
	*col = atoi(&buf[i + 1]);
}

// void getCursorPos(size_t *col, size_t *row)
// {
// 	char	answer[20];
// 	int		i;

// 	write(STDOUT_FILENO, "\x1b[6n", 4);
// 	bzero(answer, 20);
// 	i = read(0, answer, 20);
// 	answer[i] = 0;
// 	i = 2;
// 	*row = atoi(answer + i);
// 	while (isdigit(answer[i]))
// 		i++;
// 	*col = atoi(answer + i + 1);
// }

void initTerminal()
{
	getTermSize(&terminal.TerminalCol, &terminal.TerminalRow);
	getCursorPos(&terminal.startCol, &terminal.startRow);
}

char *lineEditing(void)
{
	t_line line;

	terminal.orig = enableRawMode();
	initTerminal();
	line.length = 0;
	line.cursor = 0;
	while (1)
	{
		getTermSize(&terminal.TerminalCol, &terminal.TerminalRow);
		ProcessKeyPress(&line);
	}
	disableRawMode(terminal.orig);
}

int main(void)
{
	char *str;

	while (1) {
		str = NULL;
		write(STDOUT_FILENO, "Promt > ", 8);
		str = lineEditing();
		write(STDOUT_FILENO, str, strlen(str));
		write(STDOUT_FILENO, "\n", 1);
		free(str);
	}
}