#include "line_edition.h"

void initLineEditor(void) {
	E.prompt.str = ft_strdup(PROMT);
	E.prompt.len = ft_strlen(E.prompt.str);
	get_current_cursor(&E.cursor.startPos.cx, &E.cursor.startPos.cy);
	E.cursor.currentPos.cy = E.cursor.startPos.cy;
	E.cursor.currentPos.cx = E.cursor.startPos.cx;
	E.cursor.prevPos.cy = E.cursor.startPos.cy;
	E.cursor.prevPos.cx = E.cursor.startPos.cx;
	E.cursor.atLine = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &E.ws);
	E.screencells = E.ws.ws_col * E.ws.ws_row;
	E.line.str = ft_strdup("");
	E.line.len = 0;
	E.scrolled_lines_above = 0;
	E.scrolled_lines_below = 0;
}
