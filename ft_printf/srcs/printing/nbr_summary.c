/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_summary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 05:53:42 by dthan             #+#    #+#             */
/*   Updated: 2019/12/20 05:53:46 by dthan            ###   ########.fr       */
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



char *type_di(t_info *info, va_list arg)
{
    long long num;
    char *str;

    num = get_signed_argument(info, arg);
    str = ft_itoa_signed_longlong(num);
    return (str);
}
