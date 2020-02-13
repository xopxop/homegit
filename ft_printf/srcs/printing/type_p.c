/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:07:20 by dthan             #+#    #+#             */
/*   Updated: 2020/02/10 07:43:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define HEX_MASK 15
#define SHIFF_HEX_MASK 4

void	type_p(t_info *info, va_list arg, size_t *ct)
{
	unsigned long long	num;
	char				*str;
	char				*hex;

	hex = "0123456789abcdef";
	num = (long long)va_arg(arg, long long);
	str = ft_number_conversion(num, HEX_MASK, SHIFF_HEX_MASK, hex);
	prec_ctrl_str(info, &str);
	if (num == 0 && info->percision > 1)
	{
		str = ft_strnew(2 + info->percision);
		str = ft_strncpy(str, "0x0", 3);
		ft_memset(str + 3, '0', info->percision - 1);
	}
	else
		str = ft_strjoin_and_free_string2("0x", str);
	width_ctrl(info, &str);
	write(STDOUT, str, *ct = ft_strlen(str));
	free(str);
}
