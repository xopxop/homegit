/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:43:51 by dthan             #+#    #+#             */
/*   Updated: 2020/01/06 21:04:44 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	type_di(t_info *info, va_list arg, size_t *ct)
{
	long long	num;
	char		*str;

	num = get_signed_argument(info, arg);
	str = ft_itoa_signed_longlong(num);
	flag_ignore(info);
//	flag_control(info, &str); change order
	prec_ctrl_nums(info, &str);
	width_ctrl(info, &str);
	flag_control(info, &str);
	write(STDOUT, str, *ct = ft_strlen(str));
	free(str);
}
