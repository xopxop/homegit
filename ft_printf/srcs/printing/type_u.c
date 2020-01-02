/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:01:44 by dthan             #+#    #+#             */
/*   Updated: 2019/12/31 14:30:37 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** this function is for type unsigned integer (type_u) only
** the way for dealing with this is the same for type signed integer (type d,i)
** but not negative sign here
*/

void	type_u(t_info *info, va_list arg, char **output)
{
	unsigned long long num;
	char *str;

	num = get_unsigned_argument(info, arg);
	str = ft_itoa_unsigned_longlong(num);
	if (info->percision != -1 && info->flags & ZERO)
		info->flags ^= ZERO;
	if (info->percision == 0 && !ft_strcmp("0", str))
		*str = '\0';
	ft_prec_nums(info, &str);
	ft_pad_handle(info, &str);
	*output = str;
}
