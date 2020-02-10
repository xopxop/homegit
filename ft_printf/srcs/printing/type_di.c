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

/*
** ft for type integer 'i' and 'd'
** taking the argument and put into a string
** taking care of the flags 0:  if percision is not bigger than 0
**                              percions is 0 -> nothing to be printed
** taking care of PLUS and SPACE flags, if there are plus and space, plus
** will be alwasy printed
** ft_prec_nums will take care of the percision
** ft_pad_handle will taking care of the padding
*/

void	type_di(t_info *info, va_list arg, size_t *ct)
{
	long long	num;
	char		*str;

	num = get_signed_argument(info, arg);
	str = ft_itoa_signed_longlong(num);
	flag_control(info, &str);
	prec_ctrl_nums(info, &str);
	width_ctrl(info, &str);
	write(STDOUT, str, *ct = ft_strlen(str));
	free(str);
}
