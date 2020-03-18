/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 09:28:16 by dthan             #+#    #+#             */
/*   Updated: 2020/02/28 09:28:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

int ft_isoptions(char chr)
{
    return (chr == '-');
}

int ft_is_short_options(char chr1, char chr2)
{
    return ((chr1 == '-' && chr2 != '-'));
}

int ft_is_long_option(char chr1, char chr2)
{
    return ((chr1 == '-' && chr2 == '-'));
}

int ft_isfile(char *dir_name, int *ret)
{
    struct stat filestat;

    if (!(lstat(dir_name, &filestat)))
        return (YES);
    *ret = MINOR_PROBLEMS;
    ft_err_can_not_access(dir_name);
    return (NO);
}