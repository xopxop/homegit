/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:31:31 by dthan             #+#    #+#             */
/*   Updated: 2020/02/27 16:31:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void get_dir(char *dir_name, t_dir **ldir)
{
    t_dir *new;
    t_dir *ptr;

    if (!(new = (t_dir*)ft_memalloc(sizeof(t_dir))))
        ft_err_malloc();
    new->name = ft_strdup(dir_name);
    new->next = NULL;
    if (!*ldir)
        *ldir = new;
    else
    {
        ptr = *ldir;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = new;
    }
}