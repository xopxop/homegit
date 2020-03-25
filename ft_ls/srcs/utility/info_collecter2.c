/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_collecter2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:50:21 by dthan             #+#    #+#             */
/*   Updated: 2020/03/25 01:50:22 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

char *ft_get_path_sym_link(char *pathname, int *ret)
{
    char *symlink;
    char buf[50];
    ssize_t len;

    len = readlink(pathname, buf, sizeof(buf) - 1);
    if (len != -1)
    {
        buf[len] = '\0';
        if (!(symlink = ft_strdup(buf)))
            ft_err_malloc();
        return (symlink);
    }
    ft_err_can_not_read_link(pathname);
    *ret = MINOR_PROBLEMS;
    return (NULL);
}

t_min ft_get_min(t_node *node)
{
    t_min min;

    min.width_of_link = ft_numlen(node->status.stats.st_nlink);
    min.width_of_user_name = ft_strlen(node->status.user_name);
    min.width_of_group_name = ft_strlen(node->status.group_name);
    min.width_of_size = ft_numlen(node->status.stats.st_size);
    return (min);
}
