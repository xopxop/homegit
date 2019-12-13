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
** Print string
*/

void	prepare_str(va_list arg)
{
	const char *str;

	ft_putstr((str = va_arg(arg, char*)));
}

/*
** Unsigned Interger
*/

void	prepare_undercimal(va_list arg)
{
	unsigned int temp;
	char *str;

	ft_putstr(str = ft_itoa_unsigned_int(temp = va_arg(arg, unsigned int)));
}

/*
** Octal Interger
*/

unsigned int decimalToOctal(unsigned int decimalnum)
{
    unsigned int octalnum = 0; 
	unsigned int temp = 1;

    while (decimalnum != 0)
    {
    	octalnum = octalnum + (decimalnum % 8) * temp;
    	decimalnum = decimalnum / 8;
        temp = temp * 10;
    }

    return (octalnum);
}

void	prepare_octal(va_list arg)
{
	char *str;

	ft_putstr(str = ft_itoa_unsigned_int(\
			decimalToOctal(va_arg(arg, unsigned int))));
}

/*
** Hexadecimal number (not sure if we need to handle negative hexadecimal num)
*/

int		decimalToHexadecimal(int decimalnum)
{
	int octalnum = 0; 
	int temp = 1;

    while (decimalnum != 0)
    {
    	octalnum = octalnum + (decimalnum % 16) * temp;
    	decimalnum = decimalnum / 16;
        temp = temp * 10;
    }

    return (octalnum);
}

void	prepare_hexadecimal(va_list arg)
{
	char *str;
	ft_putstr(str = ft_itoa(\
			decimalToHexadecimal(va_arg(arg, int))));
}

/*
** type_p pointer, the void*pointer argument is printed in hexadecimal
*/

char *reverseString(char *str) // need to change to lower case: norm
{
	unsigned int i;
	unsigned int j;
	char temp;

	j = 2;
	i = ft_strlen(str) - 1;
	while (j < i)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		j++;
		i--;
	}
	return (str);
}

char	*converToHex(uint64_t ptr) // need to change to lower case : norm
{
	int i;
	char *s;
	char *hex = "0123456789abcdef";

	i = 0;
	s =(char*)ft_memalloc(14);
	s[i++] = '0';
	s[i++] = 'x';
	while(ptr)
	{
		s[i++] = hex[ptr & 0xf];
		ptr >>= 4;
	}
	return (reverseString(s));
}

void	prepare_ptr(va_list arg)
{
//	unsigned int ptr;
	uint64_t ptr;
	char *s;

//	ptr = va_arg(arg, unsigned int);
	ptr = va_arg(arg, uint64_t);
	s = converToHex(ptr);
	ft_putstr(s);
	free(s);
}

/*
**	Type float
*/

/*
void prepare_float(va_list arg)
{
	double temp;
	char *str;
	
	temp = va_arg(arg, double);
	str = 
}
*/

/*
** this function will take info from the struct info and print
*/

void	printing_helper(t_info *info, va_list arg)
{
	if (info->specifier.type_d == 1 || info->specifier.type_i == 1)
		prepare_signed_int(arg);
	else if (info->specifier.type_u == 1)
		prepare_undercimal(arg);
	else if (info->specifier.type_o == 1)
		prepare_octal(arg);
	else if (info->specifier.type_x == 1 || info->specifier.type_X == 1)
		prepare_hexadecimal(arg);
/*	
	else if (info->specifier->type_f == 1)
		prepare ; // Type_f
*/
	else if (info->specifier.type_c == 1)
		prepare_char(arg);
	else if (info->specifier.type_s == 1)
		prepare_str(arg);
	else if (info->specifier.type_p == 1)
		prepare_ptr(arg);
/*	else if (info->specifier.percentage_sign == 1)
		prepare_percentage_sign(info);
	// will be missing some data like nothing, check it later
*/
}
