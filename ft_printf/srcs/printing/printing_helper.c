/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:43:18 by dthan             #+#    #+#             */
/*   Updated: 2019/12/23 04:43:20 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

long long get_signed_argument(t_info* info, va_list arg)
{
    long long num;

    if (info->length == len_h)
        num = (short)va_arg(arg, int);
    else if (info->length == len_hh)
        num = (char)va_arg(arg, int);
    else if (info->length == len_l)
        num = (long)va_arg(arg, long);
    else if (info->length == len_ll)
        num = (long long)va_arg(arg, long long);
    else
        num = (int)va_arg(arg, int);
    return (num);
}

unsigned long long get_unsigned_argument(t_info* info, va_list arg)
{
    unsigned long num;

    if (info->length == len_h)
        num = (unsigned short)va_arg(arg, unsigned int);
    else if (info->length == len_hh)
        num = (unsigned char)va_arg(arg, unsigned int);
    else if (info->length == len_l)
        num = (unsigned long)va_arg(arg, unsigned long);
    else if (info->length == len_ll)
        num = (unsigned long long)va_arg(arg, unsigned long long);
    else
        num = (unsigned int)va_arg(arg, unsigned int);
    return (num);
}

char *ft_number_conversion(unsigned long long num, int mask, int shiff_nbr, int strlen, char *s)
{
    int i = 0;
    int j = 0;
    char temp = '\0';
    char *str;

    if (!(str = (char*)ft_memalloc(strlen)))
        return (0);
    while (num)
    {
        str[i++] = s[num & mask];
        num >>= shiff_nbr;
    }
    i--;
    while (i > j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j++;
        i--;
    }
    return (str);
}