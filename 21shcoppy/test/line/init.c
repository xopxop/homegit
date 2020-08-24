#include "line_edition.h"

void initLineEditor(void) {
	E.prompt.str = ft_strdup(PROMT);
	E.prompt.str_replace = ft_strdup(OFF_SCREEN);
	E.prompt.len = ft_strlen(E.prompt.str);
	get_current_cursor(&E.cursor.startPos.cx, &E.cursor.startPos.cy);
	E.cursor.currentPos.cy = E.cursor.startPos.cy;
	E.cursor.currentPos.cx = E.cursor.startPos.cx;
	E.cursor.atLine = 0;
	getWindowSize(&E.screenrows, &E.screencols);
	E.screencells = E.screenrows * E.screencols;
	E.line.str = ft_strdup("");
	E.line.len = 0;
	E.pinned = -1;
}
