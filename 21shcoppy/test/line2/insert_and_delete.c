#include "line_edition.h"

// NOTICE: work with insert first cause del char will have more problem
// with the difference of backspace and delete key

void push_one_line_up(void)
{
	char buf[32];

	ft_bzero(buf, 32);
	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.ws.ws_col, E.ws.ws_row); // need to change in the future
	ft_putstr(buf);
	ft_putstr("\r\n");
}

/* need to decrease startrow to 1:
** when ofc, start row is not 1, it means start row > 1
** first it check, if the unused space, un-printed spaces
** counting from the start line < the length of the total string
** which is included the len of prompt and the total len of the string
** if total len < the unused space => no need to decrease the start_row
** else : there will be 2 cases
** 			+ first: it is still printing in the same line
**					from the position 2 to the end of ws_col
**			+ second: this case it need to return 1 which is valid for
**					decreasing the startrow by 1
**					it means the modulus of total / ws_col == 1
*/

int need_to_decrease_startrows_to_1()
{
	int unused_space;
	int total_char;

	unused_space = (E.ws.ws_row - E.startrows + 1) * E.ws.ws_col;
	total_char = ft_strlen(E.prompt.str) + ft_strlen(E.line.str);
	if (total_char < unused_space)
		return (0);
	return ((total_char % E.ws.ws_col == 0) ? 1 : 0);
}

int need_to_increase_scrolled_line_bellow(int prev_strlen)
{
	int total;

	total = prev_strlen + E.prompt.len;
	return ((total % E.ws.ws_col == 0) ? 1 : 0);
}

/*
**	In the appendCase
**	There will be no scrolled lines bellow
**	Therfore, if the previous char position is at the bottom right
**	position of the terminal => scrolled line above will inceased
**	by 1
*/

static void appendCase(void)
{
	if (prev_cursor_position_bottom_right(E.line.len))
		E.scrolled_lines_above++;
}

/*
**	In the Insert case:
**	Both scrolled lines Above and Bellow will be affected
**	For Scrolled line bellow: the value will be always + 1 or - 1
**		and by the end of the day, the value seems unchanged
**		+ Increased by one when:
**			++	the ranged should be some where in at last line of the terminal
**			++	the total char behind the cursor or a simple way is
**				if the total char at the % the screen's col nbr == 0
**	For scrolled line above: the value of this variable will be
**		increased by 1 whenever, the previous char position
**		is at the bottom right conner
*/

static void insertCase(void)
{
	if (prev_cursor_position_bottom_line(E.line.len))
	{
		if (prev_cursor_position_bottom_right(E.line.len))
		{
			E.scrolled_lines_above++;
			E.scrolled_lines_below--;
		}
		if (need_to_increase_scrolled_line_bellow(E.line.len))
			E.scrolled_lines_below++;
	}
}

/*
**	when inserting or deleting the character in the string
**	the scrolled_lines_variables will be affected no matter what
**	NOTE: in the future, need to regconized when it is edit or delete mode?
*/

static void handle_scrolled_lines_variables(void)
{
	if (E.cursor.atLine == E.line.len)
		appendCase();
	else
		insertCase();
}

/*
**	Insert char: insert the key character into the string
**	Scrolled_line_variables will be activated when the line which will
**	start printing is == 1
**	When the starting line is != 1
**	It means for sure that the string probably is not long enough and
**	smaller than total cells from the terminal
**	The CONDITION to decrease the start printing line is:
**		+ Start printing line is bigger than one or not == 1
**		+ All the cells in the terminal was occupied
*/

void insertChar(t_line *line, int c)
{
	char *new;

	new = ft_strnew(ft_strlen(line->str) + 1);
	new = ft_strcpy(new, line->str);
	ft_memmove(&new[E.cursor.atLine + 1], &new[E.cursor.atLine], line->len - E.cursor.atLine + 1);
	new[E.cursor.atLine] = c;
	free(line->str);
	line->str = new;
	line->len++;
	E.cursor.atLine++;
	if (E.startrows == 1)
		handle_scrolled_lines_variables();
	else if (E.startrows != 1 && need_to_decrease_startrows_to_1())
	{
		E.startrows--;
		push_one_line_up();
	}
}

void delChar(t_line *line)
{
	char *new;

	if (line->len == 0)
		return ;
	new = ft_strnew(line->len - 1);
	

	// ft_memmove(&line->str[E.cursor.atLine - 1], &line->str[E.cursor.atLine], line->len - E.cursor.atLine + 1);
	// new = ft_strdup(line->str);
	// free(line->str);
	// line->str = new;
	// line->len--;
	// do i need to decrease scrolled line or not?
}
