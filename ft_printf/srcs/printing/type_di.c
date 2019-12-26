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

char *type_di(t_info *info, va_list arg)
{
    long long num;
    char *str;


    num = get_signed_argument(info, arg);
    str = ft_itoa_signed_longlong(num);
    if (info->flags & PLUS_SIGN || info->flags & MINUS_SIGN || info->flags || \
        info->flags & SPACE || (size_t)info->percision < ft_strlen(str))
    {
        if (info->flags &PLUS_SIGN && num > 0)
            str = ft_strjoin("+", str);
        
    }
    return (str);
}
