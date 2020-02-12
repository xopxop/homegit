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
#define ROUNDED 1
#define NOT_ROUNDED 0

/*
** This is a simple function to check if the number need to round or not
*/

static int need_to_round(long double nb, int lap)
{
	int i;

	i = 0;
	nb = (nb - (int)nb) * 10;
	if ((int)nb != 9)
		return (0);
	else
		while (i++ < lap)
		{
			if ((int) nb != 9)
				return (0);
			nb = (nb - (int)nb) * 10;
		}
	return (1);
}

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
		long double modulo, int *check_rounded)
{
	char *s;
	long double temp;

	s = *str;
	if ((int)*nb == 0)
		s[(*i)++] = '0';
	else
		while ((int)modulo != 0)
		{
			if (*check_rounded == NOT_ROUNDED)
			{
				temp = *nb;
				if (need_to_round(temp, 3))
				{
					*check_rounded = ROUNDED;
					*nb = *nb + (long double)0.001;
				}
			}
			s[(*i)++] = (char)((*nb / modulo) + '0');
			*nb -= (int)(*nb / modulo) * modulo;
			modulo /= 10;
		}
}

/*
** Handle the fractional part
** NOTE: This is not an accurate method, the accurate method will take way
** longer for reference: dtoa function : http://www.netlib.org/fp/dtoa.c
** FYI: https://en.wikipedia.org/wiki/IEEE_754
*/

void rounding(char **str, long double temp_nb, int first_position, int last_position, long double nb, int *check_rounded)
{
	char *s;

	s = *str;
	printf("String:%s\nfirst:%d\nLast:%d\nnb:%d\ntemp_nb:%d", *str, first_position, last_position, (int)nb, (int)temp_nb);
//	printf("%s\n", s);
	if ((int)nb > 4)
	{
		
//		printf("Here\n");
//		printf("%c\n", s[last_position]);
		if (s[last_position] != '9')
		{
			s[last_position] += 1;
		}
		else
		{
			while(first_position++ < last_position)
			{
			//	printf("%d\n", (int)temp_nb);
				if (*check_rounded == NOT_ROUNDED)
				{
					if (need_to_round(temp_nb, last_position - first_position))
					{
						s[first_position - 1] += 1;
						ft_memset(s + first_position, '0', last_position - first_position + 1);
						break ;
					}
				}
				temp_nb = (temp_nb - (int)(temp_nb)) * 10;
			}
		}
	}
}

void			ft_handle_fractional(char **str, int *i, long double nb, \
		t_info *info, int *check_rounded)
{
	char	*s;
	int temp_position;
	long double temp_nb;

	temp_nb = nb;
	nb *= 10;
	s = *str;
	if (info->percision == 0)
	{
		if (info->flags & HASH_SIGN)
			s[*i] = '.';
		return ;
	}
	s[(*i)++] = '.';
	temp_position = *i;
	if (*check_rounded == ROUNDED)
		ft_memset(s + *i, '0', info->percision);
	else
		while (info->percision-- > 0)
		{
//			if (*check_rounded == NOT_ROUNDED)
//				if (need_to_round(nb, info->percision))
//				{
//					*check_rounded = ROUNDED;
//					nb = nb + (long double)0.0001;
//				}
			s[(*i)++] = (char)((int)nb + 48);
			nb = (nb - (int)nb) * 10;
		}
//	printf("%Lf\n", nb);
//	printf("Temp:%d\nI%d\n", temp_position, *i);
	rounding(str, temp_nb, nb, );
}
/*
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
		tmp = ((int)nb != 9) ? (int)(nb + 0.01) : (int)nb;
		s[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
}
*/
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
	int check_rounded;

	check_rounded = NOT_ROUNDED;
	if (info->length == len_l)
		num = (long double)va_arg(arg, double);
	else if (info->length == len_lup)
		num = va_arg(arg, long double);
	else
		num = (long double)va_arg(arg, double);
	info->percision = (info->percision == -1) ? 6 : info->percision;
	float_to_string(num, info, &str, &check_rounded);
	flag_control(info, &str);
	width_ctrl(info, &str);
	write(STDOUT, str, *ct = ft_strlen(str));
	free(str);
}
