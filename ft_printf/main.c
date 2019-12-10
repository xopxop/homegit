/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 00:45:54 by dthan             #+#    #+#             */
/*   Updated: 2019/12/11 01:55:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
	char	type_char = 'a';
	int	type_int = 23;
	char*	str = "abcdef";
	unsigned int	type_u = 4294967295;
	unsigned int	type_u_negative = -92;
	unsigned int	type_o = 65;
	int		type_x = -100;

	printf("PRINTF\n");
	ft_printf("MY FT_PRINTF\n");

	printf("Test for character: --%c\n", type_char);
	ft_printf("MY PRINTF Test for character: --%c\n", type_char);

	printf("Test for interger: --%d\n", type_int);
	ft_printf("MY PRINTF Test for interger: --%d\n", type_int);

	printf("Test for string: --%s\n", str);
	ft_printf("MY PRINTF Test for string: --%s\n", str);

	printf("Test for unsigned interger: --%u\n", type_u);
	ft_printf("MY PRINTF Test for unsigned interger: --%u\n", type_u);

	printf("Test for negative unsigned interger: --%u\n", type_u_negative);
	ft_printf("MY PRINTF Test for negative unsigned interger: --%u\n", type_u_negative);

	printf("Test for octal interger: --%o\n", type_o);
	ft_printf("MY PRINTF Test for octal interger: --%o\n", type_o);

	printf("Test for hexadecimal interger: --%x\n", type_x);
	ft_printf("MY PRINTF Test for hexadicimal interger: --%x\n", type_x);

	return (0);
}
