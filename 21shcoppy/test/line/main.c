#include "line_edition.h"

// 3 cases:
// case 1: in the middle of the terminal -> the line will start filling till it reach the bottom
// 			right conner
// case 2: when it hits the bottom right conner, if it row is not the first line in terminal
//			it will push till the position of the prompt to the first line in the terminal
// case 3: when the first row is the first line in the terminal and the line keep writing, in this
//			case, the cursor probably at the bottom right of the terminal, the the off-screen action
//			will take place => the first line will be replace with <...>

void updateEditor(void)
{
	getWindowSize(&E.screenrows, &E.screencols);
	E.screencells = E.screenrows * E.screencols;
	// updateCursorPos(&E.cursor.currentPos.cx, &E.cursor.currentPos.cy);
}

void	line_edition(void)
{
	// write(1, "\x1b[2J", 4);
	// write(1, "\x1b[1;1H", 6);
	enableRawMode();
	get_current_cursor(&E.startcols, &E.startrows); // get start_position
	ft_putstr(PROMT);
	initLineEditor();
	while (1) {
		updateEditor();
		refreshLineEditor();
		if (processKeyPress(&E.line))
			break;
	}
	disableRawMode();
	write(1, "\n", 1);
	ft_putstr(E.line.str);
	write(1, "\n", 1);
	free(E.line.str);
}

int main(void)
{
	while (1)
		line_edition();
	return (0);
}