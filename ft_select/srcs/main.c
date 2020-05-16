/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 01:13:54 by dthan             #+#    #+#             */
/*   Updated: 2020/05/16 10:52:31 by dthan            ###   ########.fr       */
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

void	ft_display(char **input)
{
	struct winsize w;
	int input_size;
	int col;
	int row;
	int width_col;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	input_size = ft_arrayct(input);
	width_col = (ft_finding_longest_input(input) + 1);
	col = w.ws_col / width_col;
	row = (input_size == col) ? 1 : (input_size / col) + 1;
	char ***board = ft_board_generator(input, col, row);
	ft_display_board(board, col, row, width_col - 1);
}

char	*init_terminal_data()
{
	char	*termtype;
	char	*term_buffer;
	int		ret;

	if ((termtype = getenv("TERM")) == 0)
	{
		ft_putstr_fd("Specify a terminal type with `setenv TERM <yourtype>`.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	term_buffer = ft_strnew(2048);
	ret = tgetent(term_buffer, termtype);
	if (ret < 0)
	{
		ft_putstr_fd("Could not access the termcap database.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (ret == 0)
	{
		ft_putstr_fd("Terminal type ", STDERR_FILENO);
		ft_putstr_fd(termtype, STDERR_FILENO);
		ft_putstr_fd(" is not defined.\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (term_buffer);
}

void	ft_select(char **av)
{
	//first look up the description of the terminal type in use
	char *term_buffer = init_terminal_data();
	(void)term_buffer;
	(void)av;

	// display av
	// NOTE: (not sure how to use) ft_display(av);
	// init
	// input in a loop
	// free
}

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_select(&av[1]);
	else
		ft_putstr("Print usage!\n"); //print usage
	return (EXIT_SUCCESS);
}