/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:25:23 by dthan             #+#    #+#             */
/*   Updated: 2019/12/24 04:25:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <string.h>

int ft_isnan(double num)
{
    return (num != num);
}

int ft_isinf(double num)
{
    if (num == (10.0 / 0.0) || num == (-10.0 / 0.0))
        return (1);
    return (0);
}

int special_case(char **s, double num)
{
    if (ft_isnan(num))
    {
        ft_strcpy(*s, "nan");
        return (1);
    }
    else if (ft_isinf(num))
    {
        ft_strcpy(*s, "inf");
        return (1);
    }
    return (0);
}

/*
** Finding the modulo for integer part
** the function take the floating point number and the size of the string
** Return value: size of the string & the modulo
** if the integer part of the number / 10 not equal to 0
** ex: 332.32(double) -> 332(int) / 10
** then the modulo = 10^n while n is the number of every loop if (int)number != 0
** also, str_size++
*/

long double ft_calc_modulo(double num, int *str_size)
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
** Handle_interger part
** Intake variable: the number, string, position of string, and the modulo
** which are found with the ft_calc_modulo
** RETURN VALUE: the number, string, position of string
** Algorithm:   If (int)nb != 0
**              (double)nb / modulo ex: 4223.423/1000 = 4.223423
**              Then into the string with (int)nb only --> 4
**              Remove the first digit of the number by using the fomula
**                    nb = floating point nbr - interger nbr
**              Then reduce the modulo by / 10
**              The loop stop when (int)nb == 0
** ex: 423.2324 -> 0.2324, stop here cause int(nb) == '0'
*/

void ft_handle_integer(long double *nb, char **str, int *i, long double modulo)
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
** Handle the frational part
** Intake variable: the string, its position, the number and the precision for
** the fractional part, default printf is 7 including the '.'
** Return value: string, its postion
**
** The first char for a string is the '.'
**                          Algorithm     
**          Promote each frational digit to the integer part
** and striping it off from the number
**          Put the interger part into a string
** NOTE: This is not an accurate method
**          



*/

void	ft_handle_decimals(char **str, int *i, long double nb, int precision)
{
	int		j;
	int		tmp;
	char	*s;

	nb *= 10;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < precision)
	{
		if ((int)nb == 0)
		{
			s[(*i)++] = '0';
            continue;
		}
		tmp = (int)nb;
		s[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
}

void put_floating_point_to_string(long double num, int frac_size, char **str)
{
    long double modulo;
    int str_size;
    char *new;
    int i;
    int neg;

    i = 0;
    neg = 0;
    str_size = 1;
    if(special_case(str, num))
        return ;
    if (num < 0)
    {
        num *= -1;
        neg = 1;
    }
    modulo = ft_calc_modulo(num, &str_size);
    str_size += frac_size;
    new =  ft_strnew(str_size);
    if (neg)
        new[i++] = '-';
    ft_handle_integer(&num, new, &i, modulo);
    ft_handle_decimals(&new, &i, num, frac_size);
    
    *str = new;
}


void type_f(t_info *info, va_list arg, char **output)
{
    long double num;
    char *str;
    int frac_size;
    
    frac_size = 0;
    if(info->length == len_l)
        num = (long double)va_arg(arg, double);
    else if (info->length == len_lup)
        num = va_arg(arg, long double);
    else
        num = (long double)va_arg(arg, double);
    if (info->percision = -1)
        frac_size = 7;
    else if (info->percision > 0)
        frac_size = info->percision + 1;
    put_floating_point_to_string(num, frac_size, &str);
    if ((info->flags & PLUS_SIGN || info->flags & SPACE) && str[0] != '-')
    {
        str = ft_strjoin((info->flags & SPACE) ? " " : "+", str);
        str[0] = (info->flags & PLUS_SIGN) ? '+' : str[0];
    }
    *output = str;
}