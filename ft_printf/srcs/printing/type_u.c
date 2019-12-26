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

char *type_u(t_info *info, va_list arg)
{
    unsigned long long num;
    char *str;

    num = get_unsigned_argument(info, arg);
    str = ft_itoa_unsigned_longlong(num);
    return (str);
}
