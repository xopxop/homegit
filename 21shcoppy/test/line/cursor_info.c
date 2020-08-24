#include "line_edition.h"

// void updateCursorPos(int *cx, int *cy)
// {
// 	int how_many_chars_already_on_terminal;
// 	int how_many_chars_needed_to_print;
// 	int how_many_chars_was_offscreen;
// 	int total_chars;

// 	how_many_chars_already_on_terminal = E.screencols * (E.screenrows - 1);
// 	how_many_chars_needed_to_print = E.prompt.len + E.line.len;
// 	total_chars = how_many_chars_already_on_terminal + how_many_chars_needed_to_print;
// 	if (total_chars >= E.screencells && how_many_chars_already_on_terminal != 0)
// 		// push row
// 	else if (total_chars >= E.screencells && how_many_chars_already_on_terminal == 0)
// 		// off screen
		
	
// 	// *cx = E.cursor.startPos.cx + E.cursor.atLine % E.screencols;
// 	// *cy = E.cursor.startPos.cy + E.cursor.atLine / E.screencols;
// 	// if (*cx > E.screencols)
// 	// {
// 	// 	*cx %= E.screencols;
// 	// 	if (*cy < E.screenrows)
// 	// 		(*cy)++;
// 	// 	else
// 	// 		*cy = E.screenrows;
// 	// }

// 	*cx = (E.cursor.startPos.cx + E.cursor.atLine) % E.screencols;
// 	if (*cx == 0)
// 		*cx = E.screencols;
// 	*cy = E.cursor.startPos.cy + ((E.cursor.startPos.cx + E.cursor.atLine - 1) / E.screencols);
// 	// if off-screen
// }

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
