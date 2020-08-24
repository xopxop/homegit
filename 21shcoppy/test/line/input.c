#include "line_edition.h"

int readKey(void) {
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

int processKeyPress(t_line *line) {
	int c = readKey();

	switch (c) {
		case CTRL_KEY('q'):
			disableRawMode();
			exit(0);
			break;
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
