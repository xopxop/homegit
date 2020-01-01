/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:22:08 by dthan             #+#    #+#             */
/*   Updated: 2019/12/30 12:22:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

int			main(void)
{
	int		nb = 12;
	ft_printf(RESET"%x\n", nb);printf(RED"%x\n", nb);
	ft_printf(RESET"test X:%X\n", nb);printf(RED"test X:%X\n", nb);
	ft_printf(RESET"Hash:%#X\n", nb);printf(RED"Hash:%#X\n", nb);
	ft_printf(RESET"prec / grande:%.5X\n", nb);printf(RED"prec / grande:%.5X\n", nb);
	ft_printf(RESET"prec / petite:%.0X\n", nb);printf(RED"prec / petite:%.0X\n", nb);
	ft_printf(RESET"hash + prec / grande:%#.5X\n", nb);printf(RED"hash + prec / grande:%#.5X\n", nb);
	ft_printf(RESET"hash + prec / petite:%#.1X\n", nb);printf(RED"hash + prec / petite:%#.1X\n", nb);
	ft_printf(RESET"prec + 0: %0.5X\n", nb);printf(RED"prec + 0: %0.5X\n", nb);
	ft_printf(RESET"Prec + minus:%-.5X\n", nb);printf(RED"Prec + minus:%-.5X\n", nb);
	ft_printf(RESET"size:%5X\n", nb);printf(RED"size:%5X\n", nb);
	ft_printf(RESET"size + prec:%7.3X\n", nb);printf(RED"size + prec:%7.3X\n", nb);
	ft_printf(RESET"size + mminus:%-5X\n", nb);printf(RED"size + mminus:%-5X\n", nb);
	ft_printf(RESET"size + 0:%05X\n", nb);printf(RED"size + 0:%05X\n", nb);
	ft_printf("Here\n");
	ft_printf(RESET"size + 0 + hash:%#05X\n", nb);printf(RED"size + 0 + hash:%#05X\n", nb);
	ft_printf(RESET"size + 0 + prec:%05.3X\n", nb);printf(RED"size + 0 + prec:%05.3X\n", nb);
	ft_printf(RESET"size + minus + prec:%-5.3X\n", nb);printf(RED"size + minus + prec:%-5.3X\n", nb);
	ft_printf(RESET"size + hash + 0 + prec:%#05.3X\n", nb);printf(RED"size + hash + 0 + prec:%#05.3X\n", nb);
	ft_printf(RESET"size + hash + 0 + prec:%0#5.3X\n", nb);printf(RED"size + hash + 0 + prec:%0#5.3X\n", nb);
	ft_printf(RESET"size + hash + minus + prec:%-#7.3X\n", nb);printf(RED"size + hash + minus + prec:%-#7.3X\n", nb);
}
