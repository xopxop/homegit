/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:54:29 by dthan             #+#    #+#             */
/*   Updated: 2020/03/25 01:54:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int ft_numlen(int num)
{
    int ct;

    ct = 0;
    if (num < 0)
    {
        ct++;
        num *= -1;
    }
    while (num > 9)
    {
        num /= 10;
        ct++;
    }
    return (ct + 1);
}

void ft_push_node_to_lst(t_node **head, t_node *node)
{
    t_node *ptr;

    if (*head == NULL)
        *head = node;
    else
    {
        ptr = *head;
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = node;
    }
    
}

void ft_split_input(char *name ,t_args *lst, int *ret)
{
    t_node *node;

    if (!(node = (t_node*)malloc(sizeof(t_node))))
        ft_err_malloc();
    initialize_struct(node);
    ft_get_file_info(node, name, NULL, ret);
    if (node->status.type == 'd')
        ft_push_node_to_lst(&lst->dir, node);
    else
        ft_push_node_to_lst(&lst->file, node);
}