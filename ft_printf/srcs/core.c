/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 02:33:13 by dthan             #+#    #+#             */
/*   Updated: 2019/12/18 02:33:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#define STDOUT 1

/*
** The ft_parse_and_print will check every character from the string format.
** If it hit '%' then it will move to the next position in the format string
** then start parsing [flags][field_width].[percision][specifier]
** Since it have all the infomation for printing, then printing ft will print
** the result
** RETURN VALUE: the len of the printed string
*/

int parse_and_print(const char *format, va_list args, t_info *info)
{
	size_t pos;
	int len;

	pos = 0;
	len = 0;
	while(format[pos] != '\0')
	{
		if (format[pos] != '%')
		{
			write(STDOUT, &format[pos], 1);
			len++;
		}
		else
		{
			pos++;
			parsing(format, args, &pos, info);
			len += printing(info, args);
		}
		pos++;
	}
	return (len);
}

/*
** Ft_printf function, where the function start, initialized struct info
** and passed the str format, the arguments, and the struct info into
** ft_parse_and_print.
** Return: number of bytes
*/

int	ft_printf(const char *format, ...)
{
	t_info info;
	int printed;
	va_list args;

	va_start(args, format);
	printed = parse_and_print(format, args, &info);
	va_end(args);
	return (printed);
}
