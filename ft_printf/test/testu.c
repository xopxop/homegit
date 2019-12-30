/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:21:55 by dthan             #+#    #+#             */
/*   Updated: 2019/12/30 12:21:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"


int			main(void)
{
	int		nb;
	nb = 0;
	ft_printf(RESET"precision:%.5u\n", nb);
	printf(RED"precision:%.5u\n", nb);
	ft_printf(RESET"Prec + 0:%0.5u\n", nb);
	printf(RED"Prec + 0:%0.5u\n", nb);
	ft_printf(RESET"Prec + minus:%-.5u\n", nb);
	printf(RED"Prec + minus:%-.5u\n", nb);
	ft_printf(RESET"size:%5u\n", nb);
	printf(RED"size:%5u\n", nb);
	ft_printf(RESET"size + minus:%-5u\n", nb);
	printf(RED"size + minus:%-5u\n", nb);
	ft_printf(RESET"size + 0:%05u\n", nb);
	printf(RED"size + 0:%05u\n", nb);
	ft_printf(RESET"size + 0 + prec:%05.3u\n", nb);
	printf(RED"size + 0 + prec:%05.3u\n", nb);
	ft_printf(RESET"size + minus + prec:%-5.3u\n", nb);
	printf(RED"size + minus + prec:%-5.3u\n", nb);
	ft_printf(RESET"%-5.3u\n", nb);
	printf(RED"%-5.3u\n", nb);
	ft_printf(RESET"%-1.45u\n", nb);
	printf(RED"%-1.45u\n", nb);
	ft_printf(RESET"%-55.35u\n", nb);
	printf(RED"%-55.35u\n", nb);
}
