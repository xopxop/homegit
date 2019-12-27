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

void ft_right_just(t_info *info, char **str, char *new)
{
    char extra;

    extra = 0;
    if (info->flags & ZERO)
    {
        extra = (!ft_isdigit((*str)[0]) && info->specifier == spec_int) ? (*str)[0] : 0;
        ft_memset(new, '0', info->field_width - ft_strlen(*str) + !!extra);
        if (extra)
        {
            new[0] = extra;
            (*str)[0] = '0';
        }
    }
    else
    {
        ft_memset(new, ' ', info->field_width - ft_strlen(*str));
        if ((info->flags & PLUS_SIGN) && **str != '-')
            new[info->field_width -ft_strlen(*str)] = ((*str)[0] == '-') ? '-' : '+';
    }
    ft_strcpy(new + info->field_width - ft_strlen(*str) + !!extra, *str + !!extra);
}

void ft_pad_handle(t_info *info, char **str)
{
    char *new;

    if (info->field_width == 0 || ft_strlen(*str) >= (size_t)info->field_width)
        return ;
    new = ft_strnew(info->field_width);
    if (info->flags & MINUS_SIGN)
    {
        ft_strcpy(new, *str);
        ft_memset(new + ft_strlen(*str), ' ', info->field_width - ft_strlen(*str));
    }
    else
        ft_right_just(info, str, new);
    free(*str);
    *str = new;
    return ;
}

void    ft_prec_nums(t_info *info, char **str)
{
    char *new;
    char extra;
    char *orig;

    orig = *str;
    if (info->percision == 0 && !ft_strcmp("0", *str))
    {
        **str = '\0';
        return ;
    }
    if (info->percision == -1)
        info->percision = 1;
    if (info->percision < (int) ft_strlen(*str))
        return ;
    extra = (!ft_isdigit((*str)[0]) && info->specifier == spec_int) ? (*str)[0] : 0;
    if (extra)
        (*str)++;
    new = ft_strnew(info->percision + !!extra);
    ft_memset(new + !!extra, '0', info->percision - ft_strlen(*str));
    ft_strcpy(new + info->percision - ft_strlen(*str) + !! extra, *str);
    if (extra)
        new[0] = extra;
    free(orig);
    *str = new;
}

void ft_prec_handle(t_info *info, char **str)
{
    if (info->percision == -1)
        return ;
    if (ft_strlen(*str) <= (size_t)info->percision)
        return ;
    (*str)[info->percision] = '\0';
}