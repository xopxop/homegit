#include "line_edition.h"

int prev_cursor_position_bottom_right(int prev_strlen)
{
	int start;
	int end;
	int used_space;

	start = findind_start_char(prev_strlen);
	end = finding_end_char(prev_strlen, start);
	used_space = (E.startrows == 1) ? 0 : (E.startrows - 1) * E.ws.ws_col;
	used_space = (E.scrolled_lines_above) ? (end - start ) : (end - start + E.prompt.len);

	return ((used_space == E.screencells) ? 1 : 0);
}

int prev_cursor_position_top_left(int prev_strlen, int prev_cursor_pos)
{
	int start;

	start = findind_start_char(prev_strlen);
	return ((prev_cursor_pos == start) ? 1 : 0);
}

int prev_cursor_position_bottom_line(int prev_strlen)
{
	int start;
	int end;

	start = findind_start_char(prev_strlen);
	end = finding_end_char(prev_strlen, start);
	return (((end - start) > E.ws.ws_col * (E.ws.ws_row - 1)) ? 1 : 0);
}
