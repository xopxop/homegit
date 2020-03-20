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

int ft_get_max_file_name(t_node *node, int options)
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

void ft_skip_hidden_node(t_node **node, int options)
{
    if (!(options & LIST_HIDDEN))
        while (*node && (*node)->status.is_hidden == YES)
            *node = (*node)->next;
}

int ft_get_list_size(t_node* node, int options)
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

char ***ft_creat_table(int row, int col)
{
    char ***table;
    int i = 0;
    int j;

    table = (char***)ft_memalloc(sizeof(char***));
    while (i < row)
    {
        table[i] = (char**)malloc(sizeof(char**));
        j = 0;
        while (j < col)
        {
            table[i][j] = (char*)malloc(sizeof(char*));
            table[i][j] = NULL;
            j++;
        }
        i++;
    }
    return (table);
}

char ***ft_putlist_into_table(char ***table, t_node *node, int row, int col, int options)
{
    int row2 = 0;
    int col2 = 0;

    while (col2 < col && node != NULL)
    {
        row2 = 0;
        while (row2 < row && node != NULL)
        {
            ft_skip_hidden_node(&node, options);
            table[row2][col2] = node->status.name;
            node = node->next;
            row2++;
        }
        col2++;
    }
    return (table);
}

void ft_print_table(char ***table, int width, int row, int col)
{
    int row2 = 0;
    int col2 = 0;

    while (row2 < row && table[row2][col2] != NULL)
    {
        while (col2 < col && table[row2][col2] != NULL)
        {
            ft_printf("%-*s ", width, table[row2][col2]);
            col2++;
        }
        write(1, "\n", 1);
        col2 = 0;
        row2++;
    }
}

void ft_print_short_list(t_node *lchild, int options)
{
    int win_size;
    int max_name_len;
    int col;
    int row;
    int lst_size;
    char ***table;

    win_size = get_terminal_width();
    max_name_len = ft_get_max_file_name(lchild, options);
    col = win_size / (max_name_len + 1);
    lst_size = ft_get_list_size(lchild, options);
    row = (lst_size == col) ? 1 : (lst_size / col) + 1;
    table = ft_creat_table(row, col);
    table = ft_putlist_into_table(table, lchild, row, col, options);
    ft_print_table(table, max_name_len, row, col);
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