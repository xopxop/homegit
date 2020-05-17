/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 01:13:54 by dthan             #+#    #+#             */
/*   Updated: 2020/05/17 06:18:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <term.h>

int		ft_finding_longest_input(char **input)
{
	int maxsize;
	int size;

	maxsize = 0;
	while (*input)
	{
		size = (int)ft_strlen(*input);
		if (maxsize < size)
			maxsize = size;
		input++;
	}
	return (maxsize);
}

char	***ft_empty_board_generator(int const col, int const row)
{
	char	***empty_board;
	int		i;
	int		j;

	i = -1;
	empty_board = (char***)malloc(sizeof(char***));
	while (++i < row)
	{
		j = -1;
		empty_board[i] = (char**)malloc(sizeof(char**));
		while (++j < col)
		{
			empty_board[i][j] = (char*)malloc(sizeof(char*));
			empty_board[i][j] = NULL;
		}
	}
	return (empty_board);
}

char	***ft_board_generator(char **input, int const col, int const row)
{
	char ***board;
	int i;
	int j;

	board = ft_empty_board_generator(col, row);
	i = -1;
	while (++i < row && *input != NULL)
	{
		j = -1;
		while (++j < col && *input != NULL)
		{
			board[i][j] = *input;
			input++;
		}
	}
	return (board);
}

void	ft_display_board(char ***board, int const col, int const row, int width_col)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < row && board[i][j] != NULL)
	{
		j = -1;
		while (++j < col && board[i][j] != NULL)
			ft_printf("%-*s ", width_col, board[i][j]);
	}
	ft_putchar('\n');
}

int		char_to_term(int c)
{
	return (write(1, &c, 1));
}

void	ft_display(char **input)
{
	struct winsize w;
	int input_size;
	int col;
	int row;
	int width_col;

	// tputs(tgetstr("cl", NULL), 1, char_to_term); 
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	input_size = ft_arrayct(input);
	width_col = (ft_finding_longest_input(input) + 1);
	col = w.ws_col / width_col;
	row = (input_size == col) ? 1 : (input_size / col) + 1;
	char ***board = ft_board_generator(input, col, row);
	ft_display_board(board, col, row, width_col - 1);
}

void	init_custom_config(t_terminal *term)
{
	int		ret;

	term->termtype = getenv("TERM");
	tgetent(term->term_buffer, term->termtype);
	tcgetattr(STDOUT_FILENO, &term->term_attributes);
	term->term_attributes.c_lflag &= ~(ICANON | ECHO);
	term->term_attributes.c_cc[VMIN] = 1;
	term->term_attributes.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term->term_attributes);
	// tputs(tgetstr("ti", NULL), 1, char_to_term);
	// tputs(tgetstr("vi", NULL), 1, char_to_term);
}

void	on_key_press(char **av)
{
	char	buf[10];

	while (true)
	{
		ft_bzero(buf, 10);
		ft_display(av);
		read(STDIN_FILENO, buf, 100);
		if (buf[0] == 32 && buf[1] == 0 && buf[2] == 0)
			ft_printf("SPACE KEY PRESSED\n");
		else if (buf[0] == 27 && buf[1] == 0 && buf[2] == 0)
			ft_printf("ESCAPE KEY PRESSED\n");
		else if (buf[0] == 27 && buf[1] == '[' && buf[2] == 'A')
			ft_printf("UPWARDS_ARROW PRESS\n");
		else if (buf[0] == 27 && buf[1] == '[' && buf[2] == 'B')
			ft_printf("DOWNWARDS_ARROW PRESS\n");
		else if (buf[0] == 27 && buf[1] == '[' && buf[2] == 'C')
			ft_printf("RIGHTWARDS_ARROW PRESS\n");
		else if (buf[0] == 27 && buf[1] == '[' && buf[2] == 'D')
			ft_printf("LEFTWARDS_ARROW PRESS\n");
		else
			ft_printf("NOT DETECTED\n");
	}
}

void	ft_select(char **av)
{
	t_terminal	term;
	init_custom_config(&term);
	on_key_press(av);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_select(&av[1]);
	else
		ft_putstr("Print usage!\n"); //print usage
	return (EXIT_SUCCESS);
}