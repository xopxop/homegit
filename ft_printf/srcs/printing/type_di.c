/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:43:51 by dthan             #+#    #+#             */
/*   Updated: 2019/12/23 04:43:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void type_di(t_info *info, va_list arg, char **output)
{
    long long num;
    char *str;

    num = get_signed_argument(info, arg);
    str = ft_itoa_signed_longlong(num);
    if (info->percision != -1 && info->flags & ZERO)
        info->flags ^= ZERO;
    if (info->percision == 0 && !ft_strcmp("0", str))
        *str = '\0';
    if ((info->flags & PLUS_SIGN || info->flags & SPACE) && str[0] != '-' && info->specifier == spec_int)
    {
        str = ft_strjoin((info->flags & SPACE) ? " " : "+", str);
        str[0] = (info->flags & PLUS_SIGN) ? '+' : str[0];
    }
    ft_prec_nums(info, &str);
    ft_pad_handle(info, &str);
    *output = str;
}