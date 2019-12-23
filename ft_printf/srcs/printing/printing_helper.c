/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 02:30:32 by dthan             #+#    #+#             */
/*   Updated: 2019/12/19 02:30:37 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define __do_div(n, base) ({ \
    int __res; \
    __res = ((unsigned long) n) % (unsigned) base; \
    n = ((unsigned long) n) / (unsigned) base; \
    __res; })

char *number(long num, int base, t_info *info)
{
    char *str = ft_memalloc(66);
    static const char digits[16] = "0123456789ABCDEF";
    char tmp[66];
    char c;
    char sign;
    char lowcase;
    int i;
    int j;

    j = 0;
    lowcase = (info->flags & SMALL);
    if (info->flags & MINUS_SIGN)
        info->flags &= ~ZERO;
    if (base < 2 || base > 16)
        return NULL;
    c = (info->flags & ZERO) ? '0' : ' ';
    sign = 0;
    if (info->flags & SIGN)
    {
        if (num < 0)
        {
            sign = '-';
            num = -num;
            info->field_width--;
        }
        else if (info->flags & PLUS_SIGN)
        {
            sign = '+';
            info->field_width--;
        }
        else if (info->flags & SPACE)
        {
            sign = ' ';
            info->field_width--;
        }
    }
    if (info->flags & HASH_SIGN)
    {
        if (base == 16)
            info->field_width -= 2;
        else if (base == 8)
            info->field_width--;
    }
    i = 0;
    if (num == 0)
        tmp[i++] = '0';
    else
        while (num != 0)
            tmp[i++] = (digits[__do_div(num, base) | lowcase]);
    if (i > info->percision)
        info->percision = i;
    info->field_width -= info->percision;
    if (!(info->flags & (ZERO + MINUS_SIGN)))
        while (info->field_width-- > 0)
            str[j++] = ' ';
    if (sign)
        str[j++] = sign;
    if (info->flags & HASH_SIGN)
    {
        if (base == 8)
            str[j++] = '0';
        else if (base == 16)
        {
            str[j++] = '0';
            str[j++] = ('X' | lowcase);
        }
    }
    if (!(info->flags & MINUS_SIGN))
        while (info->field_width-- > 0)
            str[j++] = c;
    while (i < info->percision--)
        str[j++] = '0';
    while (i-- > 0)
        str[j++] = tmp[i];
    while (info->field_width-- > '0')
        str[j++] = tmp[i];
    return (str);
}
