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

/*
** the function get_signed_argument is for signed integer (type i & d)
** it will return the value which is respectively to the flags length 
** length:  h(short) - 
**          hh(signed char)
**          l (long int)
**          ll (long long int)
** for more info: http://www.cplusplus.com/reference/cstdio/printf/
*/

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

/*
** the function get_unsigned_arument is for unsigned interger (type u)
** the return value is rescpectively to the length
** http://www.cplusplus.com/reference/cstdio/printf/
*/

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

/*
** The ft_number_conversion is using for reversing the string s
** the reason using this function is using for putting the number of type_x
** (hexadecial numbers) & type_o (octal numbers) into a string using the
** binary operators
** shifting 4 for hex and 3 for octal in binary
** After getting the str, we need to reverse it because the shifting is
** shifting right
*/

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

char *ft_strrev(char *s)
{
    char temp;
    int i;
    int j;

    temp = '\0';
    i = 0;
    j = (int)ft_strlen(s);
    j--;
    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
        i++;
    }
    return (s);
}
