#include "line_edition.h"

char *pre_command_line(void)
{
	if (E.offline && E.screencols <= 2)
		return (E.prompt.str_replace);
	if (E.offline == 0)
		return (E.prompt.str);
	else // check section sthing
		return (E.prompt.str_replace);
}

void populate_min_max_selection(int *min, int *max)
{
	// pinned index?
	if (E.pinned < E.cursor.atLine)
	{
		*min = E.pinned;
		*max = E.cursor.atLine;
	}
	else
	{
		*min = E.cursor.atLine;
		*max = E.pinned;
	}
	
}

int	get_command_line_starting_index()
{
	return (E.offline * E.screencols);
}

void process_coppy_char(char *str, t_selection *c)
{
	ft_strncpy(&str[c->j], &E.line.str[c->i], 1);
	c->len--;
	c->i++;
	c->j++;
	c->nb_chars++;
}

void coppy_last_part_of_command_line(t_selection *c, char *str)
{
	if (ft_strlen(&E.line.str[c->i]) <= ft_strlen(E.prompt.str_replace))
		while (E.line.str[c->i])
			process_coppy_char(str, c);
	else
	{
		ft_strcpy(&str[c->j], E.prompt.str_replace);
		c->j += ft_strlen(E.prompt.str_replace);
	}
	str[c->j] = '\0';
}

char *process_print_command_line(int empty_space)
{
	char *selected_str;
	t_selection selected_part;
	int		index;

	populate_min_max_selection(&selected_part.min, &selected_part.max);
	selected_str = ft_strnew(4 * E.screencols * E.screenrows);
	index = get_command_line_starting_index();
	selected_part.i = index;
	selected_part.nb_chars = 0;
	selected_part.len = ft_strlen(&E.line.str[index]);
	selected_part.j = 0;
	while (E.line.str[selected_part.i] && selected_part.nb_chars < empty_space - (int)ft_strlen(E.prompt.str_replace))
		process_coppy_char(selected_str, &selected_part);
	coppy_last_part_of_command_line(&selected_part, selected_str);
	return (selected_str);
}

char *command_line(void)
{
	int empty_space;
	int promt_len;

	promt_len = (E.offline) ? ft_strlen(E.prompt.str_replace) : ft_strlen(E.prompt.str);
	empty_space = (E.screencols * E.screenrows) - promt_len - 1; // why -1 here? i think it it for the cursor
	return (process_print_command_line(empty_space));
}

int get_research_nb_lines()
{
	return (0);
}

int get_true_cursor_pos_prev_prompt(int cursor)
{
	if (E.offline)
		return (cursor + ft_strlen(E.prompt.str_replace));
	else
		return (cursor + ft_strlen(E.prompt.str));
}

int get_command_line_starting_index2(int offline)
{
	return (E.screencols * offline);
}

int get_command_line_prefix_len(void)
{
	return ((E.offline) ? ft_strlen(E.prompt.str_replace) : ft_strlen(E.prompt.str));
}

int should_elipse_end(int offline)
{
	int index;
	int add;

	index = get_command_line_starting_index2(offline);
	add = get_command_line_prefix_len();
	if (add + (int)ft_strlen(&E.line.str[index]) > E.screenrows * E.screencols - 1)
		return (1);
	else
		return (0);
}

int get_scroll_to_add(int target_screen_line, int research_nb_lines)
{
	if (target_screen_line < 1)
	{
		if (E.offline + target_screen_line > 0)
			return (target_screen_line - 1);
		else
			return target_screen_line;
	}
	else if (target_screen_line >= E.screenrows - 1 - research_nb_lines)
	{
		if (should_elipse_end(E.offline + target_screen_line - E.screenrows + 1 + research_nb_lines))
			return (target_screen_line - E.screenrows + research_nb_lines + 2);
		else
			return (target_screen_line - E.screenrows + research_nb_lines + 1);
	}
	return (0);
}

int ft_min(int a, int b)
{
	return (a <= b) ? a : b;
}

int command_line_nb_row(void)
{
	if (E.offline)
	{
		return (ft_min(E.screenrows - get_research_nb_lines(), \
		((ft_strlen(E.line.str) + ft_strlen(E.prompt.str_replace)) / E.screencols + 1) - E.offline));
	}
	return (ft_strlen(E.line.str) + ft_strlen(E.prompt.str)) / E.screencols + 1;
}

int sh_scroll_command_line(int cursor, int cursor_inc)
{
	int true_cursor;
	int target_screen_line;
	int ret;
	int research_nb_lines;

	research_nb_lines = get_research_nb_lines();
	true_cursor = get_true_cursor_pos_prev_prompt(cursor);
	while (!should_elipse_end(E.offline) && E.offline && E.screenrows - research_nb_lines > command_line_nb_row())
		E.offline--;
	target_screen_line = (true_cursor + cursor_inc) / E.screencols - E.offline;
	ret = get_scroll_to_add(target_screen_line, research_nb_lines);
	E.offline += ret;
	return (ret);
}

int		putchar_int(int i)
{
	ft_putchar_fd(i, STDOUT_FILENO);
	return (0);
}

int		go_up_to_prompt(int width, int cursor)
{
	char		*str;
	int			val;
	int			i;

	str = tgetstr("up", NULL);
	i = 0;
	val = ((get_true_cursor_pos_prev_prompt(cursor)) / width)
		- E.offline;
	while (i < val && i < E.screenrows - 1 - get_research_nb_lines())
	{
		tputs(str, 1, putchar_int);
		i++;
	}
	str = tgetstr("cr", NULL);
	tputs(str, 1, putchar_int);
	return (i);
}

void refreshLineEditor(void)
{
	char *temp;

	t_buffer appendingBuffer  = ABUF_INIT;
	abAppend(&appendingBuffer, "\x1b[?25l");

	
	go_up_to_prompt(E.screencols, E.cursor.atLine);


	// char buf[32]; // reposition to the starting point of cursor into the terminal
	// ft_bzero(buf, 32);
	// snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cursor.startPos.cy, 1);
	// abAppend(&appendingBuffer, buf);
	// abAppend(&appendingBuffer, "\x1b[0J");

	char	*str;
	str = tgetstr("cd", NULL);
	tputs(str, 1, putchar_int);

	sh_scroll_command_line(E.cursor.atLine, 1);


	temp = pre_command_line();
	abAppend(&appendingBuffer, temp);
	temp = command_line();
	abAppend(&appendingBuffer, temp);

	char buf2[32];
	ft_bzero(buf2, 32);
	snprintf(buf2, sizeof(buf2), "\x1b[%d;%dH", E.cursor.currentPos.cy, E.cursor.currentPos.cx);
	abAppend(&appendingBuffer, buf2);

	abAppend(&appendingBuffer, "\x1b[?25h");
	write(STDOUT_FILENO, appendingBuffer.str, appendingBuffer.len);
	abFree(&appendingBuffer);
}