/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:34:28 by dthan             #+#    #+#             */
/*   Updated: 2019/12/23 04:34:38 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** ft printing for type_s
** RETURN VALUE: a string for type_s
*/

char    *type_s(t_info *info, va_list arg)
{
    const char *s;
    char *str;
    int len;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    s = va_arg(arg, char *);
    len = ft_strnlen(s, info->percision);
    if (info->field_width > len)
    {
        if (!(str = ft_memalloc(sizeof(char) * info->field_width + 1)))
            return (0);
    }
    else
    {
        if (!(str = ft_memalloc(sizeof(char) * len + 1)))
            return (0);
    }
    if (!(info->flags & MINUS_SIGN))
        while (len < info->field_width--)
            str[j++] = ' ';
    while (i++ < len)
        str[j++] = s[k++];
    while (len < info->field_width--)
        str[j++] = ' ';
    return (str);
}
