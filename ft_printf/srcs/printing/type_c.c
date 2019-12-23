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
    char c;
    int i;

    i = 0;
    if (info->field_width > 1)
    {
        if(!(str = ft_memalloc(sizeof(char) * info->field_width + 1)))
            return (0);
        if(!(info->flags & MINUS_SIGN))
        while(--info->field_width > 0)
            str[i++] = ' ';
        str[i++] = va_arg(arg, int);
        while(--info->field_width > 0)
            str[i++] = ' ';
    }
    else
    {
        c = (unsigned char)va_arg(arg, int);
        str = ft_strdup(&c);
    }
    return (str);
}
