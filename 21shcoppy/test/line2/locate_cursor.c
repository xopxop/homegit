#include "line_edition.h"

void locate_cursor(void)
{
	int start;
	int len_from_start_line_to_cursor;
	int x,y;

	start = findind_start_char(E.line.len);
	if (E.scrolled_lines_above == 0) // this will include the prompt
	{
		len_from_start_line_to_cursor = E.cursor.atLine - start + 1 + E.prompt.len;
		x = len_from_start_line_to_cursor % E.ws.ws_col;
		if (x == 0)
			x = E.ws.ws_col;
		y = E.startrows + (len_from_start_line_to_cursor - 1) / (E.ws.ws_col);
	}
	else
	{
		len_from_start_line_to_cursor = E.cursor.atLine - start + 1;
		x = len_from_start_line_to_cursor % E.ws.ws_col;
		if (x == 0)
			x = E.ws.ws_col;
		y = E.startrows + (len_from_start_line_to_cursor - 1) / (E.ws.ws_col);
	}
	char buf[32];
	ft_bzero(buf, 32);
	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", y, x);
	ft_putstr(buf);
	E.cursor.prevPos.cx = x;
	E.cursor.prevPos.cy = y;
}
