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

void display(t_node *head, int options)
{
    if (options & LIST_SUBDIR_RECUSIVELY)
    {
        ft_putstr_fd(head->status.path, STD_OUT);
        write(STD_OUT, "\n", 1);
    }
    if (options & LONG_LIST_FORMAT)
        ft_print_long_list(head, options);
    else
        ft_print_short_list(head, options);
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
    ft_init_struct_max(max);
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

void ft_print_long_list(t_node *lst, int options)
{
    int total_block;
    t_max max;

    total_block = ft_blockct(lst, options);
    ft_printf ("total %d\n", total_block, options);
    ft_get_max(&max, lst, options);
    while (lst)
    {
        if (!(options & LIST_HIDDEN) && lst->status.is_hidden == YES)
            ;
        else
        {
            ft_printf("%c%s %*u %*s %*s %*d %s %s\n", lst->status.type, \
            lst->status.file_permission, max.width_of_link ,lst->status.link, \
            max.width_of_user_name, lst->status.user_name, max.width_of_group_name, \
            lst->status.group_name, max.width_of_size, lst->status.size , \
            lst->status.time, lst->status.name);
        }
        lst = lst->next;
    }
}