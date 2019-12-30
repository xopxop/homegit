/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:01:44 by dthan             #+#    #+#             */
/*   Updated: 2019/12/23 08:01:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void type_u(t_info *info, va_list arg, char **output)
{
    unsigned long long num;
    char *str;

    num = get_unsigned_argument(info, arg);
    str = ft_itoa_unsigned_longlong(num);
    if (info->percision != -1 && info->flags & ZERO)
        info->flags ^= ZERO;
    if (info->percision == 0 && !ft_strcmp("0", str))
        *str = '\0';
    if (info->flags & PLUS_SIGN || info->flags & SPACE)
    {
        str = ft_strjoin((info->flags & SPACE) ? " " : "+", str);
        str[0] = (info->flags & PLUS_SIGN) ? '+' : str[0];
    }
    ft_prec_nums(info, &str);
    ft_pad_handle(info, &str);
    *output = str;
}

