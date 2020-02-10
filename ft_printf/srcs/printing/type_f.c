/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:25:23 by dthan             #+#    #+#             */
/*   Updated: 2020/01/06 21:10:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Finding the modulo for decimal part
** if the decimal part of the number / 10 not equal to 0
** ex: 332.32(double) -> 332(int) / 10
** then the modulo = 10^n while n is the number of every loop if (int)number
** != 0
*/

long double		ft_calc_modulo(double num, int *str_size)
{
	long double modulo;

	modulo = 1;
	while ((int)(num /= 10) != 0)
	{
		modulo *= 10;
		(*str_size)++;
	}
	return (modulo);
}

/*
** Handle decimal part
** Algorithm:   If (int)nb != 0
**              (double)nb / modulo ex: 4223.423/1000 = 4.223423
**              Then into the string with (int)nb only --> 4
**              Remove the first digit of the number by using the fomular
**                    nb = floating point nbr - interger nbr
**              Then reduce the modulo by / 10
**              The loop stop when (int)nb == 0
** ex: 423.2324 -> 0.2324, stop here cause int(nb) == '0'
*/

void			ft_handle_decimal(long double *nb, char **str, int *i, \
		long double modulo)
{
	char *s;

	s = *str;
	if ((int)*nb == 0)
		s[(*i)++] = '0';
	else
		while ((int)*nb != 0)
		{
			s[(*i)++] = (char)((*nb / modulo) + '0');
			*nb -= (int)(*nb / modulo) * modulo;
			modulo /= 10;
		}
}

/*
** Handle the fractional part
** NOTE: This is not an accurate method, the accurate method will take way
** longer for reference: dtoa function : http://www.netlib.org/fp/dtoa.c
** - Push one by one the fractional part to decimal by multiply with 10 then
** put the nbr we got into the str
** Rouding the nb with 0.01
** Why?
** Read this: https://en.wikipedia.org/wiki/IEEE_754
*/

void			ft_handle_fractional(char **str, int *i, long double nb, \
		t_info *info)
{
	int		tmp;
	char	*s;

	nb *= 10;
	s = *str;
	if (info->percision == 0)
	{
		if (info->flags & HASH_SIGN)
			s[*i] = '.';
		return ;
	}
	s[(*i)++] = '.';
	while (info->percision-- > 0)
	{
		if ((int)nb == 0)
		{
			s[(*i)++] = '0';
			nb *= 10;
			continue;
		}
		tmp = ((int)nb != 9) ? (int)(nb + 0.00000001) : (int)nb;
		s[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
}

/*
** This function is for floating point type
** - first it will take the argument and put its value into the long double
** number
** - then it check the percision, if there is no percision then it will take
** the default percision which is 6
** - next is putting the floating point into the string
** - next step is flags checking, flags '+' and ' '
** - finally, paddling for field width
*/

void			type_f(t_info *info, va_list arg, size_t *ct)
{
	long double	num;
	char		*str;

	if (info->length == len_l)
		num = (long double)va_arg(arg, double);
	else if (info->length == len_lup)
		num = va_arg(arg, long double);
	else
		num = (long double)va_arg(arg, double);
	info->percision = (info->percision == -1) ? 6 : info->percision;
	float_to_string(num, info, &str);
	if ((info->flags & PLUS_SIGN || info->flags & SPACE) && str[0] != '-')
	{
		str = ft_strjoin_and_free_string2((info->flags & SPACE) ? " " : "+", \
				str);
		str[0] = (info->flags & PLUS_SIGN) ? '+' : str[0];
	}
	width_ctrl(info, &str);
	write(STDOUT, str, *ct = ft_strlen(str));
	free(str);
}
