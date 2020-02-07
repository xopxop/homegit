/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:51:30 by dthan             #+#    #+#             */
/*   Updated: 2020/01/06 21:18:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define OCTAL_MASK 7
#define SHIFF_OCTAL_MASK 3
#define MAX_OCTAL_STRLEN 22+1

static void flag_control(t_info *info, char **str)
{
	if (info->percision != -1 && info->flags & ZERO)
		info->flags ^= ZERO;
	if (info->percision == 0 && !ft_strcmp("0", *str))
		**str = '\0';
	if (info->flags & HASH_SIGN)
	{
		if (!ft_strcmp("0", *str))
			;
		else
			*str = ft_strjoin_and_free_string2("0", *str);
	}
	if (info->flags & PLUS_SIGN || info->flags & SPACE)
	{
		*str = ft_strjoin_and_free_string2((info->flags & SPACE) ? " " : "+", \
				*str);
		*str[0] = (info->flags & PLUS_SIGN) ? '+' : *str[0];
	}
}

void	type_o(t_info *info, va_list arg, size_t *ct)
{
	unsigned long long	num;
	char				*str;
	char				*oct;

	oct	= "01234567";
	num = get_unsigned_argument(info, arg);
	str = ft_number_conversion(num, OCTAL_MASK, SHIFF_OCTAL_MASK, \
			MAX_OCTAL_STRLEN, oct);
	flag_control(info, &str);
	ft_prec_nums(info, &str);
	ft_pad_handle(info, &str);
	write(STDOUT, str, *ct = ft_strlen(str));
	free(str);
}
