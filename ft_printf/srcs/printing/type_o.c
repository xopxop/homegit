/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 08:51:30 by dthan             #+#    #+#             */
/*   Updated: 2019/12/31 14:27:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define OCTAL_MASK 7
#define SHIFF_OCTAL_MASK 3
#define MAX_OCTAL_STRLEN 22+1

void	ft_handle_alt(t_info *info, char **str)
{
	char *new;

	if (info->flags & HASH_SIGN && **str != '0')
	{
		new = ft_strjoin("0", *str);
		free(*str);
		*str = new;
	}
}

void	ft_handle_xou(t_info *info, char **str)
{
	if(info->flags & ZERO && info->percision == 0)
		info->flags ^= ZERO;
	if (info->percision == 0 && !ft_strcmp(*str, "0"))
		*str = '\0';
	ft_prec_nums(info, str);
	if (!(info->flags & ZERO && info->flags & HASH_SIGN))
		ft_handle_alt(info, str);
	ft_pad_handle(info, str);
}

void	type_o(t_info *info, va_list arg, char **output)
{
	unsigned long long num;
	char *str;
	char *oct = "01234567";

	num = get_unsigned_argument(info, arg);
	str = ft_number_conversion(num, OCTAL_MASK, SHIFF_OCTAL_MASK, \
			MAX_OCTAL_STRLEN, oct);
	ft_handle_xou(info, &str);
	*output = str;
}
