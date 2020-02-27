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

int get_dir(char *input, t_dinfo **ldir)
{
    DIR *current_dir;
    t_dinfo *new;

    if (!(new = (t_dinfo*)ft_memalloc(sizeof(t_dinfo))))
        return (MINOR_PROBLEMS);
    new->dir_name = ft_strdup(input);
    current_dir = opendir(new->dir_name);
    if (current_dir == NULL)
        return (MINOR_PROBLEMS);
    closedir(current_dir);
    new->next = NULL;
    if (!*ldir)
        *ldir = new;
    else
        (*ldir)->next = new;
    return (OK);
}