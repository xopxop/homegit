/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_xX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:31:21 by dthan             #+#    #+#             */
/*   Updated: 2019/12/31 14:41:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define HEX_MASK 15
#define SHIFF_HEX_MASK 4
#define MAX_HEX_STRLEN 17

void	ft_percisionSmallerForxX(t_info *info, char **str)
{
	char *origin;
	char *new;
	char extra;
	int hash;

	origin = *str;
	extra = ((info->flags & PLUS_SIGN) || (info->flags & SPACE)) ? \
		((info->flags & PLUS_SIGN) ? '+' : ' ') : 0;
	new = ft_strnew(ft_strlen(*str) + !!extra + 2);
	hash = (info->flags & HASH_SIGN) ? 2 : 0;
	if (extra)
		new[0] = extra;
	if (hash)
		ft_strncpy(new + !!extra, "0x", 2);
	ft_strcpy(new + !!extra + hash, *str);
	free(origin);
	*str = new;
}

void	ft_prec_hex(t_info *info, char **str)
{
	char *new;
	char extra;
	char *orig;
	int hash;

	orig = *str;
	if (info->percision == -1)
		info->percision = 1;
	if (info->percision < (int)ft_strlen(*str))
	{
		ft_percisionSmallerForxX(info, str);
		return ;
	}
	else if ((info->percision > (int)ft_strlen(*str)))
		extra = (!ft_isalnum((*str)[0])) ? (*str)[0] : 0;
	hash = (info->flags & HASH_SIGN) ? 2 : 0;
	if (extra)
		(*str)++;
	new = ft_strnew(info->percision + !!extra);
	ft_memset(new + hash + !!extra, '0', info->percision - ft_strlen(*str));
	ft_strcpy(new + hash + info->percision - ft_strlen(*str) + \
			!! extra, *str);
	if (extra)
		new[0] = extra;
	if (hash)
		ft_strncpy(new + !!extra, "0x", 2);
	free(orig);
	*str = new;
}

/*
** This function type x is for hexadecimal number
** - First getting the length of the argument and put it into the unsigned
** long long type (the biggest data type for unsigned number)
** - Secondly, convert the number into the string with the ft_number_conversion
** - Next is checking the flags, ZERO, PLUS, SPACE
** - Next, handle the precision for type hex
** - Next, handle the spacial case so it will print like normal printf
** when there is a HASH, ZERO flags and flied width is bigger than strlen
** - Finally, handle the padding, if there is special case already been handled,
** this padding function will be skiped
*/

void	type_x(t_info *info, va_list arg, char **output)
{
	unsigned long long num;
	char *str;
	char *hex = "0123456789abcdef";

	num = get_unsigned_argument(info, arg);
	str = ft_number_conversion(num, HEX_MASK, SHIFF_HEX_MASK, \
			MAX_HEX_STRLEN, hex);
	if (info->percision != -1 && info->flags & ZERO)
		info->flags ^= ZERO;
	if (info->percision == 0 && !ft_strcmp("0", str))
		*str = '\0';
	if (info->flags & PLUS_SIGN || info->flags & SPACE)
	{
		str = ft_strjoin((info->flags & SPACE) ? " " : "+", str);
		str[0] = (info->flags & PLUS_SIGN) ? '+' : str[0];
	}
	ft_prec_hex(info, &str);
	ft_special_case(info,&str);
	ft_pad_handle(info, &str);
	*output = str;
}

/*
** This fuction type_x_up is for type hexadecimal (type x) but in the upper
** case (Type_X)
** It take the value from type lower case x then change the lower case letter
** to upper case
*/

void	type_x_up(t_info *info, va_list arg, char **output)
{
	char *new;

	type_x(info, arg, output);
	new = *output;
	while (*new)
	{
		*new = ft_toupper(*new);
		new++;
	}
}
