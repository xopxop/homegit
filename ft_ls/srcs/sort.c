/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:01:27 by dthan             #+#    #+#             */
/*   Updated: 2020/03/16 22:01:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int     cmp(t_stat file1, t_stat file2)
{
    int check1;
    int check2;

    check1 = 0;
    check2 = 0;
    if (file1.allow_open && file2.allow_open)
    {
        if (file1.is_hidden)
            file1.name++;
        if (file2.is_hidden)
            file2.name++;
        check1 = (ft_isupper(file1.name[0])) ? 32 : 0;
        check2 = (ft_isupper(file2.name[0])) ? 32 : 0;             
    }
    return (ft_strcmp(file1.name, file2.name) + check1 - check2 > 0);
}

void    ft_swap_stat(t_stat *file1, t_stat *file2)
{
    t_stat temp;
    temp.name = file1->name;
    temp.path = file1->path;
    temp.user_name = file1->user_name;
    temp.group_name = file1->group_name;
    temp.link = file1->link;
    temp.size = file1->size;
    temp.time = file1->time;
    temp.file_permission = file1->file_permission;
    temp.type = file1->type;
    temp.is_hidden = file1->is_hidden;
    temp.allow_open = file1->allow_open;
    temp.blocks = file1->blocks;
    temp.stats = file1->stats;
    temp.min_of = file1->min_of;

    file1->name = file2->name;
    file1->path = file2->path;
    file1->user_name = file2->user_name;
    file1->group_name = file2->group_name;
    file1->link = file2->link;
    file1->size = file2->size;
    file1->time = file2->time;
    file1->file_permission = file2->file_permission;
    file1->type = file2->type;
    file1->is_hidden = file2->is_hidden;
    file1->allow_open = file2->allow_open;
    file1->blocks = file2->blocks;
    file1->stats = file2->stats;
    file1->min_of = file2->min_of;

    file2->name = temp.name;
    file2->path = temp.path;
    file2->user_name = temp.user_name;
    file2->group_name = temp.group_name;
    file2->link = temp.link;
    file2->size = temp.size;
    file2->time = temp.time;
    file2->file_permission = temp.file_permission;
    file2->type = temp.type;
    file2->is_hidden = temp.is_hidden;
    file2->allow_open = temp.allow_open;
    file2->blocks = temp.blocks;
    file2->stats = temp.stats;
    file2->min_of = temp.min_of;
}

void    ft_sort_alphabet(t_node *lst)
{
    int is_in_order;
    t_node *ptr;

    is_in_order = NO;
    while(is_in_order == NO && (lst))
    {
        ptr = lst;
        is_in_order = YES;
        while (ptr->next)
        {
            if (cmp(ptr->status, ptr->next->status))
            {
                ft_swap_stat(&ptr->status, &ptr->next->status);
                is_in_order = NO;
            }
            ptr = ptr->next;
        }
    }
}

void ft_sort_rever_alphabet(t_node *lst)
{
    int is_in_order;
    t_node *ptr;

    is_in_order = NO;
    while(is_in_order == NO && (lst))
    {
        ptr = lst;
        is_in_order = YES;
        while (ptr->next)
        {
            if (!cmp(ptr->status, ptr->next->status))
            {
                ft_swap_stat(&ptr->status, &ptr->next->status);
                is_in_order = NO;
            }
            ptr = ptr->next;
        }
    }
}

int     cmp_time(t_node *file1, t_node *file2)
{
    return (file1->status.stats.st_mtime < file2->status.stats.st_mtime);
}

void ft_sort_time(t_node *lst)
{
    int is_in_order;
    t_node *ptr;

    is_in_order = NO;
    while(is_in_order == NO && (lst))
    {
        ptr = lst;
        is_in_order = YES;
        while (ptr->next)
        {
            if (cmp_time(ptr, ptr->next))
            {
                ft_swap_stat(&ptr->status, &ptr->next->status);
                is_in_order = NO;
            }
            ptr = ptr->next;
        }
    }
}

void ft_sort(t_node *lst, int options)
{
    if (options & REVERSE_ORDER)
        ft_sort_rever_alphabet(lst);
    else if (options & SORT_BY_NEWEST_FIRST)
        ft_sort_time(lst);
    else
        ft_sort_alphabet(lst);
}