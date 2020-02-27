/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:31:22 by dthan             #+#    #+#             */
/*   Updated: 2020/02/27 16:31:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int get_options(char *input, int *options)
{
    input++;
    while(*input)
    {
        if (*input++ == 'l')
            *options |= LONG_LIST_FORMAT; 
        else if (*input++ == 'R')
            *options |= LIST_SUBDIR_RECUSIVELY;
        else if (*input++ == 'a')
            *options |= LIST_HIDDEN;
        else if (*input++ == 'r')
            *options |= REVERSE_ORDER;
        else if (*input++ == 't')
            *options |= SORT_BY_NEWEST_FIRST;
        else
            return(SERIOUS_TROUBLE);
    }
    return (OK);
}