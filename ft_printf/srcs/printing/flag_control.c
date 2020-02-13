/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:36:35 by dthan             #+#    #+#             */
/*   Updated: 2020/02/13 18:41:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	flag_control(t_info *info, char **str)
{
	if (info->percision > -1 && info->flags & ZERO)
		info->flags ^= ZERO;
	if (info->specifier == spec_hexlowcase || info->specifier == spec_hexupcase\
			|| info->specifier == spec_octal)
	{
		if (info->percision == 0 && !ft_strcmp("0", *str) && \
					info->specifier == spec_octal)
			**str = '\0';
		if (info->flags & HASH_SIGN && !ft_strcmp("0", *str))
			info->flags ^= HASH_SIGN;
	}
	if (info->percision == 0 && !ft_strcmp("0", *str)\
			&& info->specifier != spec_octal && info->specifier != spec_float)
		**str = '\0';
	if ((info->flags & PLUS_SIGN || info->flags & SPACE) && *str[0] != '-' \
	&& !(info->specifier == spec_uint || info->specifier == spec_octal || \
	info->specifier == spec_hexlowcase || info->specifier == spec_hexupcase))
	{
		*str = ft_strjoin_and_free_string2((info->flags & SPACE) ? " " : "+", \
				*str);
		*str[0] = (info->flags & PLUS_SIGN) ? '+' : *str[0];
	}
}
