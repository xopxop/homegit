/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_xX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:31:21 by dthan             #+#    #+#             */
/*   Updated: 2019/12/24 03:31:23 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define HEX_MASK 15
#define SHIFF_HEX_MASK 4
#define MAX_HEX_STRLEN 17

char    *type_x(t_info *info, va_list arg)
{
    unsigned long long num;
    char *str;
    char *hex = "0123456789abcdef";

    num = get_unsigned_argument(info, arg);
    str = ft_number_conversion(num, HEX_MASK, SHIFF_HEX_MASK, MAX_HEX_STRLEN, hex);
    str = ft_strjoin("Ox", str);
    return (str);
}

char    *type_x_up(t_info *info, va_list arg)
{
    unsigned long long num;
    char *str;
    char *hex = "0123456789ABCDEF";

    num = get_unsigned_argument(info, arg);
    str = ft_number_conversion(num, HEX_MASK, SHIFF_HEX_MASK, MAX_HEX_STRLEN, hex);
    str = ft_strjoin("OX", str);
    return (str);
}
