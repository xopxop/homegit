/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 03:30:22 by dthan             #+#    #+#             */
/*   Updated: 2019/12/07 17:05:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    parsing(char *format, int pos, t_info *info, va_list arg)
{

    if (is_flags(format, info, pos))
        pos++;
    if (is_width(format, info, pos, arg))
        pos++;
    if (is_percision(format, info, pos, arg))
        pos++;
    if (is_length(format, info, pos))
        pos++;
    is_specifier(format, info, pos);
}



void printing(t_info *info, va_list arg) //need to add t_info *info
{
    if (info)
        printing_helper(info, arg);
}

int	parse_and_print(va_list arg, char *format, int pos)
{
    t_info *info;

    info = (t_info*)ft_memalloc(sizeof(t_info));
    parsing(format, pos, info, arg);
    printing(info, arg);
    free(info);
    return (0); //Just temp, it need to return with different number
}

