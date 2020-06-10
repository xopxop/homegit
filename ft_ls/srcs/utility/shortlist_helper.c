/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortlist_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:20:19 by dthan             #+#    #+#             */
/*   Updated: 2020/06/11 00:45:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int		ft_get_terminal_width(void)
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int		ft_get_max_file_name(t_node *node, int options)
{
	int max;

	max = 0;
	while (node)
	{
		if (!(options & LIST_HIDDEN) && node->status.is_hidden == YES)
			;
		else if (max < (int)ft_strlen(node->status.name))
			max = ft_strlen(node->status.name);
		node = node->next;
	}
	return (max);
}

void	ft_skip_hidden_node(t_node **node, int options)
{
	if (!(options & LIST_HIDDEN))
		while (*node && (*node)->status.is_hidden == YES)
			*node = (*node)->next;
}

int		ft_get_list_size(t_node *node, int options)
{
	int ct;

	ct = 0;
	while (node)
	{
		if (!(options & LIST_HIDDEN) && node->status.is_hidden == YES)
			;
		else
			ct++;
		node = node->next;
	}
	return (ct);
}

char	***ft_creat_table(int row, int col)
{
	char	***table;
	int		i;
	int		j;

	i = 0;
	table = (char***)ft_memalloc(sizeof(char**) * row);
	while (i < row)
	{
		table[i] = (char**)malloc(sizeof(char*) * col);
		j = 0;
		while (j < col)
		{
			table[i][j] = NULL;
			j++;
		}
		i++;
	}
	return (table);
}

void	ft_putlist_into_table(char ***table, t_node *node, int row, int col,\
			int options)
{
	int row2;
	int col2;

	col2 = 0;
	while (col2 < col && node != NULL)
	{
		row2 = 0;
		while (row2 < row && node != NULL)
		{
			// ft_skip_hidden_node(&node, options);
			if (!(options & LIST_HIDDEN) && node->status.is_hidden == YES)
			{
				node = node->next;
				continue;
			}
			table[row2][col2] = node->status.name;
			node = node->next;
			row2++;
		}
		col2++;
	}
}

void	ft_print_short_list(char ***table, int width, int row, int col)
{
	int row2;
	int col2;

	row2 = 0;
	col2 = 0;
	while (row2 < row && table[row2][col2] != NULL)
	{
		while (col2 < col && table[row2][col2] != NULL)
		{
			ft_printf("%-*s", width, table[row2][col2]);
			col2++;
		}
		write(1, "\n", 1);
		row2++;
		col2 = 0;
	}
}
