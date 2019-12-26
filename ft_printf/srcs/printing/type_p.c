/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:07:20 by dthan             #+#    #+#             */
/*   Updated: 2019/12/24 04:07:22 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define HEX_MASK 15
#define SHIFF_HEX_MASK 4
#define MAX_HEX_STRLEN 17

char    *type_p(t_info *info, va_list arg)
{
    unsigned long long num;
    char *str;
    char *hex = "0123456789abcdef";

    if (info->specifier == spec_ptr)
        num = (long long)va_arg(arg, long long);
    str = ft_number_conversion(num, HEX_MASK, SHIFF_HEX_MASK, MAX_HEX_STRLEN, hex);
    str = ft_strjoin("Ox", str);
    return (str);
}
