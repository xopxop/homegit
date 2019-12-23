/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 00:45:54 by dthan             #+#    #+#             */
/*   Updated: 2019/12/20 05:32:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
	char	type_char = 'a';
//	int	type_int = 23;
	char*	str = "abcdef";
//	unsigned int	type_u = 4294967295;
//	unsigned int	type_u_negative = -92;
//	unsigned int	type_o = 65;
//	int		type_x = -100;
//	int	*ptr;
//	float	type_f = 2.453;

//	ptr = &type_int;

//	printf("PRINTF\n");
	ft_printf("MY FT_PRINTF\n");

//	printf("--%c--\n", type_char);
	ft_printf("--%5.2c--\n", type_char);

//	printf("Test for interger: --%d\n", type_int);
//	ft_printf("--%d\n", type_int);

//	printf("Test for string: --%4.2s--\n", str);
	ft_printf("MY PRINTF Test for string: --%4.2s--\n", str);

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
	return (0);
}
