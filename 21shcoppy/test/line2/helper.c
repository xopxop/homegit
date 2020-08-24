#include "line_edition.h"

/*	findint the position of visible starting char will be display from the string:
**	CONDITION: if there is the scrolled_lines_above else return 0
**	it will return the start char in the line based on
**		the len of the string - the invisible_char(from the scrolled_line_above)
**	meanwhile, the invisible_char was calculated by:
**		invisible_chars = screen's column nbr * nbr of off line (above) - prompt's length
*/

int findind_start_char(int strlen)
{
	int invisible_chars;

	(void)strlen; // we dont need strlen
	if (E.scrolled_lines_above == 0)
		return (0);
	invisible_chars = E.ws.ws_col * E.scrolled_lines_above - ft_strlen(E.prompt.str);
	return (invisible_chars);
}

/*
**	findind the position of the last char which will be display from the string
** 	required parameter: the visible starting char will be displayed
**	CASE 1: scrolled_lines_bellow == 0
**		return the difference of the length of the str and the start_char position
**	CASE 2: scrolled_lines_bellow != 0
**		SUB-CASE 1: scrolled_lines_above != 0 ==> there is prompt string
**		SUB-CASE 2: scrolled_lines_above != 0
*/

int finding_end_char(int strlen, int start)
{
	if (E.scrolled_lines_below == 0)
		return (strlen);
	if (E.scrolled_lines_above)
		return (start + (E.ws.ws_col * E.ws.ws_row));
	return (start + (E.ws.ws_col * E.ws.ws_row) - ft_strlen(E.prompt.str));
}
