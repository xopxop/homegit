/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:46:29 by dthan             #+#    #+#             */
/*   Updated: 2019/12/05 23:54:20 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(char *format, ...) //need to change back to const char
{
	va_list arg;
	int pos;
	int count_byte;

	va_start(arg, format);
	pos = 0;
	count_byte = 0;
	while(format[pos] != '\0')
	{
		if (format[pos] == '%')
		{
			pos++;
			count_byte = parse_and_print(arg, format, pos);
		}
		else
		{
			ft_putchar(format[pos]);
			count_byte++;
		}
		pos++;
	}
	va_end(arg);
	return (count_byte);
}
