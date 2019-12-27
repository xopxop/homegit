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

#include "../includes/ft_printf.h"
# define SPECIFIER_COUNT 11
# define STDOUT 1

/*
** This is the Dispatch table/ Jump table using pointer to function array
** it will return the function coresponding to the specifier type
*/

void (*get_func(t_specifier specifier))(t_info*, va_list, char **)
{
	void (*func[SPECIFIER_COUNT])(t_info*, va_list, char **);

	func[spec_char] = &type_c;
	func[spec_str] = &type_s;

//	func[spec_ptr] = &type_p;
	func[spec_int] = &type_di;
/*	func[spec_uint] = &type_u;
	func[spec_octal] = &type_o;
	func[spec_hexlowcase] = &type_x;
	func[spec_hexupcase] = &type_x_up;
	func[spec_float] = &type_f;
*/
	return (func[specifier]);
}

/*
** The printing ft will take the pared struc info and the argument va_list
** First, using the dispatch table the get the function which coresponding to
** the specifier and take that address of that specific function into print_func
** output_str will be the returned string from the choosen function
** then it will count the output_str and display the out_putstr
** Return value: length of the output_str
*/

int	printing(t_info *info, va_list arg)
{
	void (*print_func)(t_info*, va_list, char **);
	char *output_str;
	int count;

	count = 0;
	print_func = get_func(info->specifier);
	print_func(info, arg, &output_str);
	count = ft_strlen(output_str);
	write (STDOUT, output_str, count);
	free(output_str);
	return (count);
}