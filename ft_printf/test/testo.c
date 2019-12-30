/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:21:34 by dthan             #+#    #+#             */
/*   Updated: 2019/12/30 12:21:36 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"


int			main(void)
{

//	int	nb = 0;
	int nb = 30;
	ft_printf("test o:%o\n", nb);
	printf(RED"test o:%o\n", nb);
	ft_printf(RESET"hash:%#o\n", nb);
	printf(RED"hash:%#o\n", nb);
	ft_printf("precision / grande:%.5o\n", nb);
	printf(RED"precision / grande:%.5o\n", nb);
	ft_printf("Prec + hash / grande:%#.5o\n", nb);
	printf(RED"Prec + hash / grande:%#.5o\n", nb);
	ft_printf("Prec + hash / petite:%#.1o\n", nb);
	printf(RED"Prec + hash / petite:%#.1o\n", nb);
	ft_printf("Prec + 0:%0.5o\n", nb);
	printf(RED"Prec + 0:%0.5o\n", nb);
	ft_printf("Prec + minus:%-.5o\n", nb);
	printf(RED"Prec + minus:%-.5o\n", nb);
	ft_printf("Size:%5o\n", nb);
	printf(RED"Size:%5o\n", nb);
	ft_printf("size + prec:%7.3o\n", nb);
	printf(RED"size + prec:%7.3o\n", nb);
	ft_printf("size + minus:%-5o\n", nb);
	printf(RED"size + minus:%-5o\n", nb);
	ft_printf("size + zero:%05o\n", nb);
	printf(RED"size + zero:%05o\n", nb);
	ft_printf("size + zero + hash:%#05o\n", nb);
	printf(RED"size + zero + hash:%#05o\n", nb);
	ft_printf("size + zero + prec:%05.3o\n", nb);
	printf(RED"size + zero + prec:%05.3o\n", nb);
	ft_printf("size + minus + prec:%-5.3o\n", nb);
	printf(RED"size + minus + prec:%-5.3o\n", nb);
	ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
	printf(RED"size + hash + zero + prec:%0#5.3o\n", nb);
	ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);
	printf(RED"size + hash + zero + prec:%#05.3o\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3o\n", nb);
	printf(RED"size + hash + minus + prec:%-#7.3o\n", nb);
}
