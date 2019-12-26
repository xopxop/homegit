/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:33:24 by dthan             #+#    #+#             */
/*   Updated: 2019/12/23 04:33:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** ft printing for type_c
** RETURN VALUE: a string for type_c
*/

char    *type_c(t_info *info, va_list arg)
{
    char *str;
    char *res;

    if(!(str = ft_memalloc(2)))
            return (0);
    str[0] = (unsigned char)va_arg(arg, int);
    if (info->field_width > 1)
	{
		if (info->flags & MINUS_SIGN)
			res = ft_strjoin(str, create_space(info->field_width - 1));
		else
			res = ft_strjoin(create_space(info->field_width - 1), str);
	}
    return (res);
}


