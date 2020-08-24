#include "line_edition.h"

void enableRawMode(void) {
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

void disableRawMode(void) {
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios);
}
