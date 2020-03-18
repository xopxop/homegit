/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:15:40 by dthan             #+#    #+#             */
/*   Updated: 2020/02/28 14:15:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void display(t_node *parent, t_node *lchild, int options)
{
    if (options & LIST_SUBDIR_RECUSIVELY && lchild != NULL)
            ft_printf("%s:\n", parent->status.path);
    if (options & LONG_LIST_FORMAT)
        ft_long_list(parent, lchild, options);
    else
        ft_print_short_list(lchild, options);
}

int get_terminal_width()
{
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return (w.ws_col);
}

/*
t_window ft_calculate(t_file *lfile, int col)
{
    t_window w;

    w.max = get_max_file_name(lfile);
    w.lm = get_lm(w.max);
    w.columns = (col - 1) / w.lm;
    w.columns = 
    return (w);
}
*/

void ft_print_short_list(t_node *lst, int options)
{
//    int col;
//    t_window window;

//    col = get_terminal_width();
//    ft_calculate(lfile, col);
    while (lst)
    {
        if (!(options & LIST_HIDDEN) && lst->status.is_hidden == YES)
            ;
        else
            ft_printf("%s\n", lst->status.name);
        lst = lst->next;
    }
}

int ft_blockct(t_node *lst, int options)
{
    int total_block;

    total_block = 0;
    while (lst)
    {
        if (!(options & LIST_HIDDEN) && lst->status.is_hidden == YES)
            ;
        else
            total_block += lst->status.blocks;
        lst = lst->next;
    }
    return (total_block);
}

void ft_init_struct_max(t_max *max)
{
    max->width_of_link = 0;
    max->width_of_user_name = 0;
    max->width_of_group_name = 0;
    max->width_of_size = 0;
}

void ft_get_max(t_max *max, t_node *lst, int options)
{
    while(lst)
    {
        if (!(options & LIST_HIDDEN) && lst->status.is_hidden == YES)
            ;
        else
        {
            if (max->width_of_link < lst->status.min_of.width_of_link)
                max->width_of_link = lst->status.min_of.width_of_link;
            if (max->width_of_user_name < lst->status.min_of.width_of_user_name)
                max->width_of_user_name = lst->status.min_of.width_of_user_name;
            if (max->width_of_group_name < lst->status.min_of.width_of_group_name)
                max->width_of_group_name = lst->status.min_of.width_of_group_name;
            if (max->width_of_size < lst->status.min_of.width_of_size)
                max->width_of_size = lst->status.min_of.width_of_size;
        }
        lst = lst->next;
    }
}

void ft_print_long_list(t_node *node, t_max max)
{
    ft_printf("%c%s %*u %*s %*s %*d %s %s\n", node->status.type, \
    node->status.file_permission, max.width_of_link ,node->status.link, \
    max.width_of_user_name, node->status.user_name, max.width_of_group_name, \
    node->status.group_name, max.width_of_size, node->status.size , \
    node->status.time, node->status.name);
}

void ft_long_list(t_node* parent, t_node *lchild, int options)
{
    int total_block;
    t_max max;

    ft_init_struct_max(&max);
    if (lchild)
    {
        total_block = ft_blockct(lchild, options);
        ft_printf ("total %d\n", total_block, options);
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