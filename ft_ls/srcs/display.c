/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:15:40 by dthan             #+#    #+#             */
/*   Updated: 2020/06/09 23:31:44 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	display(t_node *parent_dir, t_node *parent_file, int *ret, \
		t_node *lchild, int options)
{
	if (parent_file && !parent_dir)
	{
		if (options & LONG_LIST_FORMAT)
			ft_long_list(parent_file, lchild, options);
		else
			ft_printf("%s\n", parent_file->status.name);
	}
	else if (parent_dir)
	{
		if (options & LIST_SUBDIR_RECUSIVELY && lchild != NULL)
			ft_printf("%s:\n", parent_dir->status.path);
		else if (parent_file || *ret == MINOR_PROBLEMS)
			ft_printf("\n%s:\n", parent_dir->status.path);
		if (options & LONG_LIST_FORMAT)
			ft_long_list(parent_dir, lchild, options);
		else
			ft_short_list(lchild, options);
	}
}

void	ft_short_list(t_node *lchild, int options)
{
	int		win_size;
	int		max_name_len;
	int		col;
	int		row;
	int		lst_size;
	char	***table;

	lst_size = ft_get_list_size(lchild, options);
	if (lst_size > 0)
	{
		win_size = ft_get_terminal_width();
		max_name_len = ft_get_max_file_name(lchild, options);
		col = win_size / (max_name_len + 7);
		row = (lst_size == col) ? 1 : (lst_size / col) + 1;
		table = ft_creat_table(row, col);
		table = ft_putlist_into_table(table, lchild, row, col, options);
		ft_print_short_list(table, max_name_len, row, col);
	}
}

void	ft_long_list(t_node *parent, t_node *lchild, int options)
{
	int		total_block;
	t_max	max;

	ft_init_struct_max(&max);
	if (lchild)
	{
		total_block = ft_blockct(lchild, options);
		ft_printf("total %d\n", total_block, options);
		ft_get_max(&max, lchild, options);
		while (lchild)
		{
			if (!(options & LIST_HIDDEN) && lchild->status.is_hidden == YES)
				;
			else
				ft_print_long_list(lchild, max);
			lchild = lchild->next;
		}
	}
	else
		ft_print_long_list(parent, max);
}
