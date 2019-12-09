/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:40:30 by dthan             #+#    #+#             */
/*   Updated: 2019/12/08 21:57:12 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	prepare_char(va_list arg)
{
	int temp;

	temp = va_arg(arg, int);
	ft_putchar(temp);
}


void	prepare_signed_int(va_list arg)
{
	int temp;
	char *nbr;

	temp = va_arg(arg, int);
	nbr = ft_itoa(temp);
	ft_putstr((const char*)nbr);
}


/*
** this function will take info from the struct info and print
*/

void	printing_helper(t_info *info, va_list arg)
{
	if (info->specifier.type_d == 1 || info->specifier.type_i == 1)
		prepare_signed_int(arg);
/*
	else if (info->specifier.type_u == 1)
		prepare_undercimal(info, arg);
	else if (info->specifier.type_o == 1)
		prepare_octal(info, arg);
	else if (info->specifier.type_x == 1 || info->specifier.type_X == 1)
		prepare_hexadecimal(info, arg);
	else if (info->specifier->type_f == 1)
		prepare ; // Type_f
*/
	else if (info->specifier.type_c == 1)
		prepare_char(arg);
/*	else if (info->specifier.type_s == 1)
		prepare_str(info, arg);
	else if (info->specifier.type_p == 1)
		prepare_ptr(info, arg);
	else if (info->specifier.percentage_sign == 1)
		prepare_percentage_sign(info);
	// will be missing some data like nothing, check it later
*/
}
