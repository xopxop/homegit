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

int     is_flags(char *format, t_info *info, int pos)
{
	if (format[pos] == '#')
		info->flags.hash_key = 1;
	else if (format[pos] == '0')
		info->flags.zero = 1;
	else if (format[pos] == '-')
		info->flags.minus_sign = 1;
	else if (format[pos] == '+')
		info->flags.plus_sign = 1;
	else if (format[pos] == ' ')
		info->flags.space == 1;
	else
		return (0);
	return (1);
}

int    is_width(char *format, t_info *info, int pos, va_list arg)
{
	if (!(format[pos] == '*' || ft_isdigit(format[pos])))
		return (0);
	if (format[pos] == '*')
		info->width.asterisk = va_arg(arg, int);
	else
		info->width.nbr = get_nbr(format, pos); // should i return pos if it is a number?
	return (1);
}

int	is_percision(char *format, t_info *info, int pos, va_list arg)
{
	if (!(format[pos] == '.'))
		return (0);
	if (format[pos + 1] == '*')
		info->percision.asterisk = va_arg(arg, int);
	else if (ft_isdigit(format[pos + 1]))
		info->percision.nbr = get_nbr(format, pos + 1);
	else
		info->percision.nbr = 0;
	return (1);
}


int	is_specifier(char *format, t_info *info, int pos)
{
	if (format[pos] == 'd')
		info->specifier.type_d = 1;
	else if (format[pos] == 'i')
		info->specifier.type_i = 1;
	else if (format[pos] == 'u')
		info->specifier.type_u = 1;
	else if (format[pos] == 'o')
		info->specifier.type_o = 1;
	else if (format[pos] == 'x')
		info->specifier.type_x = 1;
	else if (format[pos] == 'X')
		info->specifier.type_X = 1;
	else if (format[pos] == 'c')
		info->specifier.type_c = 1;
	else if (format[pos] == 's')
		info->specifier.type_s = 1;
	else if (format[pos] == 'p')
		info->specifier.type_p = 1;
/*
	if (format[pos + 1] == ) //nothing case
		info->specifier.nothing = 1;
	if (format[pos + 1] == '%')
		info->specifier.percentage_sign = 1;
*/
	else
		return (0);
	return (1);
}

int is_length(char *format, t_info *info, int pos)
{
	if (format[pos] == 'h')
		if (format[pos + 1] == 'h')
			info->length.hh = 1;
		else
			info->length.h = 1;
	else if (format[pos] == 'l')
		if (format[pos + 1] == 'l')
			info->length.ll = 1;
		else
			info->length.l = 1;
	else if (format[pos] == 'L')
		info->length.L = 1;
	else
		return (0);
	return (1);
}