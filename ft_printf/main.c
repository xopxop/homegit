/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 00:45:54 by dthan             #+#    #+#             */
/*   Updated: 2019/12/26 05:14:04 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{

	ft_printf("");
	printf("");

//	int	type_int = 23;
//	char*	str = "abcdef";
//	unsigned int	type_u = 4294967295;
//	unsigned int	type_u_negative = -92;
//	unsigned int	type_o = 65;
//	int		type_x = -100;
//	int	*ptr;
//	float	type_f = 2.453;

//	ptr = &type_int;

//	printf("PRINTF\n");
//	ft_printf("MY FT_PRINTF\nabc");

/*
	printf("TEST CHAR\n");
	char	type_char = 'a';
	printf("--%c--\n", type_char);
	ft_printf("++%c++\n", type_char);
	printf("--%5c--\n", type_char);
	ft_printf("++%5c++\n", type_char);
	printf("--%1c--\n", type_char);
	ft_printf("++%1c++\n", type_char);
	printf("--%-5c--\n", type_char);
	ft_printf("++%-5c++\n", type_char);
*/

//	printf("--%#5c--", 'a');
//	printf("Test for interger: --%d\n", type_int);
//	ft_printf("--%dabc\nabc", type_int);

//	printf("Test for string: --%4.2s--\n", str);
//	ft_printf("MY PRINTF Test for string: --%4.2s--\n", str);

/*	printf("Test for unsigned interger: --%u\n", type_u);
	ft_printf("MY PRINTF Test for unsigned interger: --%u\n", type_u);

	printf("Test for negative unsigned interger: --%u\n", type_u_negative);
	ft_printf("MY PRINTF Test for negative unsigned interger: --%u\n", type_u_negative);

	printf("Test for octal interger: --%o\n", type_o);
	ft_printf("MY PRINTF Test for octal interger: --%o\n", type_o);

	printf("Test for hexadecimal interger: --%x\n", type_x);
	ft_printf("MY PRINTF Test for hexadicimal interger: --%x\n", type_x);
*/
//	printf("Test for pointer : --%p\n", (void*)ptr);
//	ft_printf("MY PRINTF Test for pointer : --%p\n", (void*)ptr);
//	printf("Test for float : --%f\n", type_f);
//	ft_printf("MY PRINTF Test for float : --%f\n", type_f);

//	long long type_longlong = 123791123124285123;
//	long long type_longlong = -9223372036854775807;
//	ft_printf("--%lld--\n", type_longlong);

//	unsigned long long a = 18446744073709551615U;
//	ft_printf("--%llu--\n", a);

//	int type_o = 301;
//	ft_printf("--%o--", type_o);

//	unsigned long long max_unsigned_long_long_type_o = -1844674407370955161U;
//	ft_printf("--%llo--\n", max_unsigned_long_long_type_o);
//	printf("--%llo--\n", max_unsigned_long_long_type_o);

//	unsigned long long max_unsigned_long_long = 18446744073709551615U;
//	ft_printf("--%llx--\n", max_unsigned_long_long);
//	ft_printf("--%llX--\n", max_unsigned_long_long);
//	printf("--%llx--\n", max_unsigned_long_long);

//NOTE: THIS case needs to consider flags
//	int a = 2;
//	void *ptr = &a;

//	ft_printf("--% p--\n", ptr);
//	printf("--% p--\n", ptr);

//	double a = 0.231;
//	ft_printf("--%f--\n", a);
//	printf("++%f++\n", a);

	return (0);
}
