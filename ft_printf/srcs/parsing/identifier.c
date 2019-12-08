/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 03:26:58 by dthan             #+#    #+#             */
/*   Updated: 2019/12/07 06:25:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int     is_flags(char *format, t_info *info, int pos)
{
	if (format[pos + 1] == '#')
	{
		info->flags.hash_key = 1;
		return (1);
	}
	if (format[pos + 1] == '0')
	{
		info->flags.zero = 1;
		return (1);
	}
	if (format[pos + 1] == '-')
	{
		info->flags.minus_sign = 1;
		return (1);
	}
	if (format[pos + 1] == '+')
	{
		info->flags.plus_sign = 1;
		return (1);
	}
	if (format[pos + 1] == ' ')
	{
		info->flags.space == 1;
		return (1);
	}
	return (0);
}
*/
/*
int    is_width(char *format, t_info *info, int pos) //need to add the va_list "second argument"
{
	if (!(format[pos + 1] == '*' || ft_isdigit(format[pos + 1])))
		return (0);
	if (format[pos + 1] == '*')
	{
		info->width.asterisk = ; //additional argument here
		return (1);
	}
	info->width.nbr = get_nbr(format, pos + 1);
	return (1);
}
*/

/*
int	is_percision(char *format, t_info *info, int pos)
{
	if (!(format[pos + 1] == '.'))
		return (0);
	else
	{
		pos++;
		if (format[pos + 1] == '*')
			info->percision.asterisk = ; // nbr additional argument
		info->percision.nbr = get_nbr(format, pos + 1);
	}
	return (1);
}
*/

int	is_specifier(char *format, t_info *info, int pos)
{
	if (format[pos] == 'd')
	{
		info->specifier.type_d = 1;
		return (1);
	}
	if (format[pos] == 'i')
	{
		info->specifier.type_i = 1;
		return (1);
	}
	if (format[pos] == 'u')
	{
		info->specifier.type_u = 1;
		return (1);
	}
	if (format[pos] == 'o')
	{
		info->specifier.type_o = 1;
		return (1);
	}
	if (format[pos] == 'x')
	{
		info->specifier.type_x = 1;
		return (1);
	}
	if (format[pos] == 'X')
	{
		info->specifier.type_X = 1;
		return (1);
	}
	if (format[pos] == 'c')
	{
		info->specifier.type_c = 1;
		return (1);
	}
	if (format[pos] == 's')
	{
		info->specifier.type_s = 1;
		return (1);
	}
	if (format[pos] == 'p')
	{
		info->specifier.type_p = 1;
		return (1);
	}
/*
	if (format[pos + 1] == ) //nothing case
		info->specifier.nothing = 1;
	if (format[pos + 1] == '%')
		info->specifier.percentage_sign = 1;
*/
	return (0);
}
