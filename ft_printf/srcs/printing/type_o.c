/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:51:30 by dthan             #+#    #+#             */
/*   Updated: 2019/12/23 08:54:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define OCTAL_MASK 7
#define SHIFF_OCTAL_MASK 3
#define MAX_OCTAL_STRLEN 22+1

char    *type_o(t_info *info, va_list arg)
{
    unsigned long long num;
    char *str;
    char *oct = "01234567";

    num = get_unsigned_argument(info, arg);
    if (!num)
        return (0);
    str = ft_number_conversion(num, OCTAL_MASK, SHIFF_OCTAL_MASK, MAX_OCTAL_STRLEN, oct);
    return (str);
}
