/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:18:39 by dthan             #+#    #+#             */
/*   Updated: 2020/07/18 07:41:56 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line_edition.h"

int			char_to_term(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/*** terminal ***/

void	enable_raw_mode()
{	
	// g_term.termtype = getenv("TERM");  // need to change or check because we cant use getenv function
	
	/***new **/
	tcgetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios); // need to check if return -1;
	
	struct termios raw = orig_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); // need to check if return -1

	/*******/
	// tgetent(g_term.term_buffer, g_term.termtype);
	// tcgetattr(STDOUT_FILENO, &g_term.new_attributes);
	// tcgetattr(STDOUT_FILENO, &g_term.old_attributes);
	// g_term.new_attributes.c_lflag &= ~(ICANON | ECHO);
	// g_term.new_attributes.c_cc[VMIN] = 1;
	// g_term.new_attributes.c_cc[VTIME] = 0;
	// tcsetattr(STDOUT_FILENO, TCSANOW, &g_term.new_attributes);
	// tputs(tgetstr("ti", NULL), 1, char_to_term);
}

void	move_left(int *cursor_pos)
{
	if (*cursor_pos > 1)
	{
		tputs(tgoto(tgetstr("cm", NULL), 10 , 10), 1, char_to_term);
		// tputs(tgetstr("le", ,NULL), 1 ,char_to_term);
		(*cursor_pos)--;
	}
}

void	move_right(int length, int *cursor_pos)
{
	if (*cursor_pos <= length)
	{
		tputs(tgoto(tgetstr("cm", NULL), 10 , 20), 1, char_to_term);
		tputs(tgetstr("nd", NULL), 1 ,char_to_term);
		(*cursor_pos)++;
	}
}

void	move_up(void)
{
	tputs(tgetstr("ch", NULL), 1 ,char_to_term);
}

void	move_down(void)
{
	tputs(tgetstr("DO", NULL), 1 ,char_to_term);
}

void	ft_move_cusor(char *buf, int length, int *cursor_pos)
{
	if (RIGHTWARDS_ARROW(buf))
		move_right(length, cursor_pos);
	else if (LEFTWARDS_ARROW(buf))
		move_left(cursor_pos);
	else if (UPWARDS_ARROW(buf))
		move_up();
	else if (DOWNWARDS_ARROW(buf))
		move_down();	
}

char	*add_key_into_line(char *line, char chr)
{
	char *inserted_line;
	int	size;

	size = (line) ? ft_strlen(line) : 0;
	inserted_line =  ft_strnew(size + 1);
	(line) ? ft_strcpy(inserted_line, line) : 0;
	(line) ? free(line) : 0;
	inserted_line[size] = chr;
	ft_putchar(chr);
	return (inserted_line);
}

char	*on_key_press(void)
{
	char	buf[5];
	t_line_info	line;

	line.returned_line = NULL;
	line.line_length = 0;
	line.cusor_pos = 1;
	while (true)
	{
		ft_bzero(buf, 5);
		read(STDERR_FILENO, buf, 5);
		if (ENTER_KEY(buf))
		{
			tputs(tgetstr("do", NULL), 1 ,char_to_term);
			return(line.returned_line);
		}
		else if (LEFTWARDS_ARROW(buf) || RIGHTWARDS_ARROW(buf) \
				|| DOWNWARDS_ARROW(buf) || UPWARDS_ARROW(buf))
			ft_move_cusor(buf, line.line_length, &line.cusor_pos);
		else if (ft_isprint(buf[0]))
		{
			line.returned_line = add_key_into_line(line.returned_line, buf[0]);
			line.line_length++;
			line.cusor_pos++;
		}
	}
}

void	reset_old_term_config(void)
{
	tcsetattr(STDOUT_FILENO, TCSANOW, &g_term.old_attributes);
	tputs(tgetstr("ve", NULL), 1, char_to_term);
}

char	*ft_getline(void)
{
	char *line;
	
	line = NULL; //leave it NULL for now
	enable_raw_mode();
	on_key_press();
	reset_old_term_config();
	return (line);
}
