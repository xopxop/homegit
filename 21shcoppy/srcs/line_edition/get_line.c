/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:18:39 by dthan             #+#    #+#             */
/*   Updated: 2020/07/16 03:23:37 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/line_edition.h"

int			char_to_term(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

void	init_custom_config()
{	
	g_term.termtype = getenv("TERM");  // need to change or check because we cant use getenv function
	tgetent(g_term.term_buffer, g_term.termtype);
	tcgetattr(STDOUT_FILENO, &g_term.new_attributes);
	tcgetattr(STDOUT_FILENO, &g_term.old_attributes);
	g_term.new_attributes.c_lflag &= ~(ICANON | ECHO);
	g_term.new_attributes.c_cc[VMIN] = 1;
	g_term.new_attributes.c_cc[VTIME] = 0;
	tcsetattr(STDOUT_FILENO, TCSANOW, &g_term.new_attributes);
	tputs(tgetstr("ti", NULL), 1, char_to_term);
}

void	move_left(void)
{
	tputs(tgetstr("le", NULL), 1 ,char_to_term);
}

void	move_right(void)
{
	tputs(tgetstr("nd", NULL), 1 ,char_to_term);
}

void	move_up(void)
{
	tputs(tgetstr("up", NULL), 1 ,char_to_term);
}

void	move_down(void)
{
	tputs(tgetstr("do", NULL), 1 ,char_to_term);
}

void	ft_move_cusor(char *buf)
{
	if (RIGHTWARDS_ARROW(buf))
		move_right();
	else if (LEFTWARDS_ARROW(buf))
		move_left();
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
	char	*line;

	line = NULL;
	g_term.cursor_pos = 0;
	while (true)
	{
		ft_bzero(buf, 5);
		read(STDERR_FILENO, buf, 5);
		if (ENTER_KEY(buf))
		{
			tputs(tgetstr("do", NULL), 1 ,char_to_term);
			return(line);
		}
		else if (LEFTWARDS_ARROW(buf) || RIGHTWARDS_ARROW(buf) \
				|| DOWNWARDS_ARROW(buf) || UPWARDS_ARROW(buf))
			ft_move_cusor(buf);
		else if (ft_isprint(buf[0]))
			line = add_key_into_line(line, buf[0]);
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
	
	init_custom_config();
	line = on_key_press();
	reset_old_term_config();
	return (line);
}
