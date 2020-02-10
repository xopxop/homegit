/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_xX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:31:21 by dthan             #+#    #+#             */
/*   Updated: 2020/02/10 07:42:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define HEX_MASK 15
#define SHIFF_HEX_MASK 4

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

void	small_x(t_info *info, va_list arg, char **output)
{
	unsigned long long	num;
	char				*str;
	char				*hex;

	hex = "0123456789abcdef";
	num = get_unsigned_argument(info, arg);
	str = ft_number_conversion(num, HEX_MASK, SHIFF_HEX_MASK, hex);
	flag_control(info, &str);
	prec_ctrl_oct_hex(info, &str, "0x");
	ft_special_case(info, &str);
	width_ctrl(info, &str);
	*output = str;
}

/*
** This fuction type_x_up is for type hexadecimal (type x) but in the upper
** case (Type_X)
** It take the value from type lower case x then change the lower case letter
** to upper case
*/

void	big_x(char **output)
{
	char *new;

	new = *output;
	while (*new)
	{
		*new = ft_toupper(*new);
		new++;
	}
}

void	type_x(t_info *info, va_list arg, size_t *ct)
{
	char *output;

	small_x(info, arg, &output);
	if (info->specifier == spec_hexupcase)
		big_x(&output);
	write(STDOUT, output, *ct = ft_strlen(output));
	free(output);
}
