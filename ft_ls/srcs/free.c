/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:23:59 by dthan             #+#    #+#             */
/*   Updated: 2020/03/15 15:24:01 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void free_lfile(t_node *node)
{
    t_node *ptr;

    while (node)
    {
        ptr = node;
        node = node->next;
        free(ptr->status.name);
        free(ptr->status.path);
        free(ptr->status.user_name);
        free(ptr->status.group_name);
        free(ptr->status.time);
        free(ptr->status.file_permission);
        free(ptr);
    }
}
