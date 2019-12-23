/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 06:26:56 by dthan             #+#    #+#             */
/*   Updated: 2019/12/17 06:27:01 by dthan            ###   ########.fr       */
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

/*
char    *type_p(t_info *info, va_list arg)
{
    char *str;

    if (info->field_width == -1)
    {
        info->field_width = 2 * sizeof(void *);
        info->flags |= ZERO;
    }
    str = number((unsigned long)va_arg(arg, void *), 16, info);
    return (str);
}
*/
