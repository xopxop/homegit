/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:01:27 by dthan             #+#    #+#             */
/*   Updated: 2020/06/09 23:22:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// will improve later

void	ft_swap_stat(t_stat *file1, t_stat *file2)
{
	t_stat temp;

	temp.name = file1->name;
	temp.path = file1->path;
	temp.user_name = file1->user_name;
	temp.group_name = file1->group_name;
	temp.time = file1->time;
	temp.file_permission = file1->file_permission;
	temp.type = file1->type;
	temp.is_hidden = file1->is_hidden;
	temp.allow_open = file1->allow_open;
	temp.stats = file1->stats;
	temp.min_of = file1->min_of;
	temp.path_sym_link = file1->path_sym_link;

	file1->name = file2->name;
	file1->path = file2->path;
	file1->user_name = file2->user_name;
	file1->group_name = file2->group_name;
	file1->time = file2->time;
	file1->file_permission = file2->file_permission;
	file1->type = file2->type;
	file1->is_hidden = file2->is_hidden;
	file1->allow_open = file2->allow_open;
	file1->stats = file2->stats;
	file1->min_of = file2->min_of;
	file1->path_sym_link = file2->path_sym_link;

	file2->name = temp.name;
	file2->path = temp.path;
	file2->user_name = temp.user_name;
	file2->group_name = temp.group_name;
	file2->time = temp.time;
	file2->file_permission = temp.file_permission;
	file2->type = temp.type;
	file2->is_hidden = temp.is_hidden;
	file2->allow_open = temp.allow_open;
	file2->stats = temp.stats;
	file2->min_of = temp.min_of;
	file2->path_sym_link = temp.path_sym_link;
}

// void	ft_sort_alphabet(t_node *lst)
// {
// 	t_node	*ptr;
// 	int		is_in_order;

// 	is_in_order = NO;
// 	while (is_in_order == NO && (lst))
// 	{
// 		ptr = lst;
// 		is_in_order = YES;
// 		while (ptr->next)
// 		{
// 			if (ft_cmp_name(ptr->status, ptr->next->status))
// 			{
// 				ft_swap_stat(&ptr->status, &ptr->next->status);
// 				is_in_order = NO;
// 			}
// 			ptr = ptr->next;
// 		}
// 	}
// }

void	ft_separate_hidden_and_non_hidden(t_node *lst)
{
	t_node *ptr;
	int		is_in_order;

	is_in_order = NO;
	while (is_in_order == NO && (lst))
	{
		ptr = lst;
		is_in_order = YES;
		while (ptr->next)
		{
			if (!ptr->status.is_hidden && ptr->next->status.is_hidden)
			{
				ft_swap_stat(&ptr->status, &ptr->next->status);
				is_in_order = NO;
			}
			ptr = ptr->next;
		}
	}
}

void	ft_sort_hidden(t_node *lst)
{
	t_node *ptr;
	int		is_in_order;

	is_in_order = NO;
	while (is_in_order == NO && (lst))
	{
		ptr = lst;
		is_in_order = YES;
		while (ptr->next)
		{
			if (ptr->status.is_hidden && ptr->next->status.is_hidden \
			&& (ft_strcmp(ptr->status.name, ptr->next->status.name) > 0))
			{
				ft_swap_stat(&ptr->status, &ptr->next->status);
				is_in_order = NO;
			}
			ptr = ptr->next;
		}
	}
}

void	ft_sort_non_hidden(t_node *lst)
{
	t_node *ptr;
	int		is_in_order;

	is_in_order = NO;
	while (is_in_order == NO && (lst))
	{
		ptr = lst;
		is_in_order = YES;
		while (ptr->next)
		{
			if (!ptr->status.is_hidden && !ptr->status.is_hidden \
			&& (ft_strcmp(ptr->status.name, ptr->next->status.name) > 0))
			{
				ft_swap_stat(&ptr->status, &ptr->next->status);
				is_in_order = NO;
			}
			ptr = ptr->next;
		}
	}
}

void	ft_sort_alphabet(t_node *lst)
{
	ft_separate_hidden_and_non_hidden(lst);
	ft_sort_hidden(lst);
	ft_sort_non_hidden(lst);
}

void	ft_sort_reverse_alphabet(t_node **lst)
{
	t_node	*cur;
	t_node	*pre;
	t_node	*next;

	cur = *lst;
	pre = NULL;
	next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	if (pre != NULL)
		*lst = pre;
}

void	ft_sort_time(t_node *lst)
{
	int		is_in_order;
	t_node	*ptr;

	is_in_order = NO;
	while (is_in_order == NO && (lst))
	{
		ptr = lst;
		is_in_order = YES;
		while (ptr->next)
		{
			if (ft_cmp_time(ptr, ptr->next))
			{
				ft_swap_stat(&ptr->status, &ptr->next->status);
				is_in_order = NO;
			}
			ptr = ptr->next;
		}
	}
}

// void	ft_sort_reverse_time(t_node *lst)
// {

// }

void	ft_sort(t_node **lst, int options)
{
	ft_sort_alphabet(*lst);
	if (options & REVERSE_ORDER && options & SORT_BY_NEWEST_FIRST)
	{
	 	ft_sort_time(*lst);
		ft_sort_reverse_alphabet(lst);
	}
	else if (options & REVERSE_ORDER)
		ft_sort_reverse_alphabet(lst);
	else if (options & SORT_BY_NEWEST_FIRST)
		ft_sort_time(*lst);
}
