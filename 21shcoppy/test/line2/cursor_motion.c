#include "line_edition.h"

/*
**	Left arrow Key
**	CONDITION: the cursor at the line should > 1
**	In the present of scrolled lines, left key arrow only deals
**	with scrolled_line_above, then the sub-condition to change values
**	of the scrolled lines is the previous cursor has to be at the
**	top-left corner of the terminal
*/

void leftArrowKey(void)
{
	if (E.cursor.atLine > 0)
	{
		if (E.scrolled_lines_above && E.cursor.prevPos.cx == 1 && E.cursor.prevPos.cy == 1)
		{
			E.scrolled_lines_below++;
			E.scrolled_lines_above--;
		}
		E.cursor.atLine--;
	}
}

/*
**	Right Arrow Key:
**	CONDITION:	for right key arrow, the condition must be smaller than
**				the string length
**	For SCROLLED LINES: The right key only need to hanle the scrolled lines
**						from bellow, if previous cursor position is at the
**						at the bottom right conner of the terminal, it will
**						trigger changing scrolled line variables, both from
**						above and bellow
*/

void rightArrowKey(void)
{
	if (E.cursor.atLine < E.line.len)
	{
		if (E.scrolled_lines_below && E.cursor.prevPos.cy == E.ws.ws_row && E.cursor.prevPos.cx == E.ws.ws_col)
		{
			E.scrolled_lines_below--;
			E.scrolled_lines_above++;
		}
		E.cursor.atLine++;
	}
}

void home_key(void)
{
	if (E.cursor.atLine > 0)
	{
		while (E.scrolled_lines_above)
		{
			E.scrolled_lines_above--;
			E.scrolled_lines_below++;
		}
		E.cursor.atLine = 0;
	}
}

void end_key(void)
{
	if (E.cursor.atLine < E.line.len)
	{
		while (E.scrolled_lines_below)
		{
			E.scrolled_lines_above++;
			E.scrolled_lines_below--;
		}
		E.cursor.atLine = E.line.len;
	}
}
void locate_cursor2(void)
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
	E.cursor.prevPos.cx = x;
	E.cursor.prevPos.cy = y;
}

int finding_char1(int start_char_pos)
{
	int cursor_pos;
	char *s = E.line.str;

	cursor_pos = start_char_pos;
	cursor_pos -= (s[start_char_pos] == '\0') ? 1 : 0;

	if (ft_isalnum(s[cursor_pos]))
		// return the first char of the word
	{
		if (ft_isalnum(s[cursor_pos - 1]))
		{
			while (s[cursor_pos - 1] && ft_isalnum(s[cursor_pos - 1]))
				cursor_pos--; // can be replace with += step
		}
		else if (ft_isspace(s[cursor_pos - 1]))
		{
			while (s[cursor_pos - 1] && !ft_isalnum(s[cursor_pos - 1]))
				cursor_pos--;
			while (s[cursor_pos - 1] && ft_isalnum(s[cursor_pos - 1]))
				cursor_pos--;
		}
		return (cursor_pos);
	}
	// it will move the the next space then last char -> char
	while (s[cursor_pos - 1] && !ft_isalnum(s[cursor_pos - 1]))
		cursor_pos--;
	while (s[cursor_pos - 1] && ft_isalnum(s[cursor_pos - 1]))
		cursor_pos--;
	return (cursor_pos);
}

int finding_char2(int start_char_pos)
{
	int cursor_pos = start_char_pos;
	char *s = E.line.str;

	while (s[cursor_pos] && ft_isalnum(s[cursor_pos]))
		cursor_pos++; // can be replace with += step
	while (s[cursor_pos] && !ft_isalnum(s[cursor_pos]))
		cursor_pos++;
	return (cursor_pos);
}

void ctrl_left(void)
{
	if (E.cursor.atLine > 0)
	{
		int end_char_pos;

		end_char_pos = finding_char1(E.cursor.atLine);
		while (E.cursor.atLine > end_char_pos)
		{
			locate_cursor2();
			leftArrowKey();
		}
	}
}

void ctrl_right(void)
{
	if (E.cursor.atLine < E.line.len)
	{
		int end_char_pos;

		end_char_pos = finding_char2(E.cursor.atLine);
		while (E.cursor.atLine < end_char_pos)
		{
			locate_cursor2();
			rightArrowKey();
		}
	}
}

int finding_char3(int start_char_pos)
{
	if(start_char_pos <= E.ws.ws_col - 1)
		return (0);
	return (start_char_pos - E.ws.ws_col);
}

void ctrl_up(void)
{
	if (E.cursor.atLine > 0)
	{
		int end_char_pos;

		end_char_pos = finding_char3(E.cursor.atLine);
		while (E.cursor.atLine > end_char_pos)
		{
			locate_cursor2();
			leftArrowKey();
		}
	}
}

int finding_char4(int start_char_pos)
{
	if(E.line.len - start_char_pos <= E.ws.ws_col - 1)
		return (E.line.len);
	return (start_char_pos + E.ws.ws_col);
}

void ctrl_down(void)
{
	if (E.cursor.atLine < E.line.len)
	{
		int end_char_pos;

		end_char_pos = finding_char4(E.cursor.atLine);
		while (E.cursor.atLine < end_char_pos)
		{
			locate_cursor2();
			rightArrowKey();
		}
	}
}

void editorMoveCursor(int key) {
	switch (key) {
		case ARROW_LEFT:
			leftArrowKey();
			break;
		case ARROW_RIGHT:
			rightArrowKey();
			break;
		case HOME_KEY:
			home_key();
			break;
		case END_KEY:
			end_key();
			break;
		case CTRL_RIGHT:
			ctrl_right();
			break;
		case CTRL_LEFT:
			ctrl_left();
			break;
		case CTRL_UP:
			ctrl_up();
			break;
		case CTRL_DOWN:
			ctrl_down();
			break;
	}
}