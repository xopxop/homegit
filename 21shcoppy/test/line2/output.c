#include "line_edition.h"

char *pre_command_line(void)
{
	return (E.scrolled_lines_above == 0) ? E.prompt.str : NULL;
}

// char *command_line(void)
// {
// 	int start;
// 	int end;

// 	start = findind_start_char(E.line.len);
// 	end =  finding_end_char(E.line.len, start);
// 	return (ft_strndup(&E.line.str[start], end - start + 1));
// }

void command_line(void)
{
	int start;
	int end;

	start = findind_start_char(E.line.len);
	end =  finding_end_char(E.line.len, start);
	while(start < end)
		write(STDOUT_FILENO, &E.line.str[start++], 1);
}


// void refreshLineEditor(void)
// {
// 	char *temp;

// 	t_buffer appendingBuffer  = ABUF_INIT;
// 	abAppend(&appendingBuffer, "\x1b[?25l");

// 	char buf[32]; // reposition to the starting point of cursor into the terminal
// 	ft_bzero(buf, 32);
// 	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cursor.startPos.cy, 1);
// 	abAppend(&appendingBuffer, buf);
// 	abAppend(&appendingBuffer, "\x1b[0J");

// 	if ((temp = pre_command_line()) != NULL)
// 	{
// 		abAppend(&appendingBuffer, temp);
// 		free(temp);
// 	}
// 	abAppend(&appendingBuffer, temp = command_line());
// 	free(temp);

// 	// for temporary
// 	char buf2[32]; // reposition to the starting point of cursor into the terminal
// 	ft_bzero(buf2, 32);
// 	snprintf(buf2, sizeof(buf2), "\x1b[%d;%dH", E.cursor.startPos.cy, 1);
// 	abAppend(&appendingBuffer, buf2);
// 	// we dont need this yet
// 	// char buf2[32];
// 	// ft_bzero(buf2, 32);
// 	// snprintf(buf2, sizeof(buf2), "\x1b[%d;%dH", E.cursor.currentPos.cy, E.cursor.currentPos.cx);
// 	// abAppend(&appendingBuffer, buf2);

// 	abAppend(&appendingBuffer, "\x1b[?25h");
// 	write(STDOUT_FILENO, appendingBuffer.str, appendingBuffer.len);
// 	abFree(&appendingBuffer);
// }

//debug
void refreshLineEditor(void)
{
	char *temp;

	// t_buffer appendingBuffer  = ABUF_INIT;
	char buf[32]; // reposition to the starting point of cursor into the terminal
	ft_bzero(buf, 32);
	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.startrows, 1);
	ft_putstr(buf);
	ft_putstr("\x1b[0J");

	if ((temp = pre_command_line()) != NULL)
		ft_putstr(temp);
	command_line();
	// ft_putstr(temp = command_line());
	// free(temp);
	// if (E.startrows != 1 && prev_cursor_position_bottom_right(E.line.len))
	// 	ft_putstr(" ");
	// for temporary
	locate_cursor();


	// char buf2[32]; // reposition to the starting point of cursor into the terminal
	// ft_bzero(buf2, 32);
	// snprintf(buf2, sizeof(buf2), "\x1b[%d;%dH", E.startrows, 1);
	// ft_putstr(buf2);
	// we dont need this yet
	// char buf2[32];
	// ft_bzero(buf2, 32);
	// snprintf(buf2, sizeof(buf2), "\x1b[%d;%dH", E.cursor.currentPos.cy, E.cursor.currentPos.cx);
	// abAppend(&appendingBuffer, buf2);
}