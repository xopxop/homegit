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

void ft_print_long_list(t_node *lst, int options)
{
    int block_ct;
    t_node *ptr;

    block_ct = 0;
    ptr = lst;
 //   ft_printf("%s:\n", lfile->path);
    while (ptr)
    {
        if (!(options & LIST_HIDDEN) && ptr->status.is_hidden == YES)
            ptr = ptr->next;
        else
        {
            block_ct += ptr->status.blocks;
            ptr = ptr->next;
        }
    }
    ft_printf ("total %d\n", block_ct);
    while (lst)
    {
        if (!(options & LIST_HIDDEN) && lst->status.is_hidden == YES)
            ;
        else
        {
            ft_printf("%c%s | %u | %s | %s | %d | %s | %s\n", lst->status.type, \
            lst->status.file_permission, lst->status.link, lst->status.user_name, \
            lst->status.group_name, lst->status.size , lst->status.time, \
            lst->status.name);
        }
        lst = lst->next;
    }
}