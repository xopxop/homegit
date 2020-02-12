/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:56:46 by dthan             #+#    #+#             */
/*   Updated: 2020/02/10 07:45:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define MAXLEN 23

/*
** the function get_signed_argument is for signed integer (type i & d)
** it will return the value which is respectively to the flags length
** length:  h(short) -
**          hh(signed char)
**          l (long int)
**          ll (long long int)
** for more info: http://www.cplusplus.com/reference/cstdio/printf/
*/

long long			get_signed_argument(t_info *info, va_list arg)
{
	long long num;

	if (info->length == len_h)
		num = (short)va_arg(arg, int);
	else if (info->length == len_hh)
		num = (char)va_arg(arg, int);
	else if (info->length == len_l)
		num = (long)va_arg(arg, long);
	else if (info->length == len_ll)
		num = (long long)va_arg(arg, long long);
	else
		num = (int)va_arg(arg, int);
	return (num);
}

/*
** the function get_unsigned_arument is for unsigned interger (type u)
** the return value is rescpectively to the length
** http://www.cplusplus.com/reference/cstdio/printf/
*/

unsigned long long	get_unsigned_argument(t_info *info, va_list arg)
{
	unsigned long num;

	if (info->length == len_h)
		num = (unsigned short)va_arg(arg, unsigned int);
	else if (info->length == len_hh)
		num = (unsigned char)va_arg(arg, unsigned int);
	else if (info->length == len_l)
		num = (unsigned long)va_arg(arg, unsigned long);
	else if (info->length == len_ll)
		num = (unsigned long long)va_arg(arg, unsigned long long);
	else
		num = (unsigned int)va_arg(arg, unsigned int);
	return (num);
}

/*
** This fucntion is for putting the floating point into a string
** Algorithm;
** - Check the special case: positive/negative infinity, not a number
** - Find the size of the new str, if negative -> + 1, redax point -> + 1
** - Filling the Decimal part
** - Check if the percision == 0, then stop filling, also, if Hash sign,
** then the next position need to be the radix point
** - Filling the Fractional part
*/

void				float_to_string(long double num, t_info *info, char **str, \
			int *check_rounded)
{
	long double	modulo;
	int			str_size;
	char		negative_sign;
	char		radix_point;
	int			i;

	if (special_case(str, num))
		return ;
	i = 0;
	str_size = 1;
	negative_sign = (num < 0) ? '-' : 0;
	if (negative_sign)
		num *= -1;
	radix_point = (info->percision > 0 || (info->percision == 0 && \
				info->flags & HASH_SIGN)) ? '.' : 0;
	modulo = ft_calc_modulo(num, &str_size);
	str_size += (info->percision + !!negative_sign + !!radix_point);
	*str = ft_strnew(str_size);
	if (negative_sign)
		*str[i++] = negative_sign;
	ft_handle_decimal(&num, str, &i, modulo, check_rounded);
	ft_handle_fractional(str, &i, num, info, check_rounded);
}

/*
** The ft_number_conversion is using for reversing the string s
** the reason using this function is using for putting the number of type_x
** (hexadecial numbers) & type_o (octal numbers) into a string using the
** binary operators
** shifting 4 for hex and 3 for octal in binary
** After getting the str, we need to reverse it because the shifting is
** shifting right
*/

char				*ft_number_conversion(unsigned long long num, int mask, \
		int shiff_nbr, char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char*)ft_memalloc(MAXLEN)))
		return (0);
	if (num == 0)
		ft_strcpy(str, "0");
	else
	{
		while (num)
		{
			str[i++] = s[num & mask];
			num >>= shiff_nbr;
		}
		str = ft_strrev(str);
	}
	return (str);
}
