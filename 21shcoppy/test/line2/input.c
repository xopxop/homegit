#include "line_edition.h"

// int readKey(void) {
// 	int nread;
// 	char c;
// 	while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
// 		;
// 		// if (nread == -1 && errno != EAGAIN) die("read");
// 	}

// 	if (c == '\x1b') {
// 		char seq[3];

// 		if (read(STDOUT_FILENO, &seq[0], 1) != 1) return '\x1b';
// 		if (read(STDOUT_FILENO, &seq[1], 1) != 1) return '\x1b';

// 		if (seq[0] == '[') {
// 			if (seq[1] >= '0' && seq[1] <= '9') {
// 				if (read(STDIN_FILENO, &seq[2], 1) != 1) return '\x1b';
// 				if (seq[2] == '~') {
// 					switch (seq[1]) {
// 						case '3': return DEL_KEY;
// 						//.... for more
// 					}
// 				}
// 			} else {
// 				switch (seq[1]) {
// 					case 'A' : return ARROW_UP;
// 					case 'B' : return ARROW_DOWN;
// 					case 'C' : return ARROW_RIGHT;
// 					case 'D' : return ARROW_LEFT;
// 				}
// 			}
// 		}
// 		return '\x1b';
// 	} else {
// 		return c;
// 	}


// 	return c;
// }

int readKey(void) {
	int nread;
	char c;
	while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
		;
		// if (nread == -1 && errno != EAGAIN) die("read");
	}

	if (c == '\x1b') {
		char seq[6];
		ft_bzero(seq, 6);
		read(STDIN_FILENO, seq, 6);
		if (ft_strequ(seq, "[D")) return ARROW_LEFT;
		if (ft_strequ(seq, "[C")) return ARROW_RIGHT;
		if (ft_strequ(seq, "[H")) return HOME_KEY; //need to check home and end key again because there maybe another value
		if (ft_strequ(seq, "[F")) return END_KEY;
		if (ft_strequ(seq, "[3~")) return DEL_KEY;
		if (ft_strequ(seq, "[1;5A")) return CTRL_UP;
		if (ft_strequ(seq, "[1;5B")) return CTRL_DOWN;
		if (ft_strequ(seq, "[1;5D")) return CTRL_LEFT;
		if (ft_strequ(seq, "[1;5C")) return CTRL_RIGHT;
		return '\x1b';
	}
	else
		return c;
}



int processKeyPress(t_line *line) {
	int c = readKey();

	switch (c) {
		case CTRL_KEY('q'):
			disableRawMode();
			exit(0);
			break;
		case BACKSPACE: // need to protect
		case DEL_KEY:
		// if (c == DEL_KEY) editorMoveCursor(ARROW_RIGHT);
			delChar(line);
			break;
		case ARROW_UP:
		case ARROW_DOWN:
		case ARROW_LEFT:
		case ARROW_RIGHT:
		case CTRL_LEFT:
		case CTRL_RIGHT:
		case CTRL_UP:
		case CTRL_DOWN:
		case HOME_KEY:
		case END_KEY:
			editorMoveCursor(c);
			break;
		// case CTRL_RIGHT:
		case '\r':
			return 1;
		default:
			insertChar(line, c);
			break;
	}
	return (0);
}
