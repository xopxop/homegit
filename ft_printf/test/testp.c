/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:21:45 by dthan             #+#    #+#             */
/*   Updated: 2019/12/30 12:21:48 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

int			main(void)
{
	int		nb;
	char	c;
	nb = 0;
	c = 'W';

	ft_printf("WIDTH ONLY--------------------------------\n");
	printf(RED"%5p\n", &nb);
	ft_printf(RESET"%5p\n", &nb);
	printf(RED"%-15p\n", &nb);
	ft_printf(RESET"%-15p\n", &nb);
	printf(RED"%-5p\n", &nb);
	ft_printf(RESET"%-5p\n", &nb);
	printf(RED"%42p\n", &nb);
	ft_printf(RESET"%42p\n", &nb);
	printf(RED"%-18p\n", &nb);
	ft_printf(RESET"%-18p\n", &nb);
	printf(RED"%42p\n", &nb);
	ft_printf(RESET"%42p\n", &nb);
	printf(RED"%5p\n", &c);
	ft_printf(RESET"%5p\n", &c);
	printf(RED"%-15p\n", &c);
	ft_printf(RESET"%-15p\n", &c);
	printf(RED"%-5p\n", &c);
	ft_printf(RESET"%-5p\n", &c);
	printf(RED"%42p\n", &c);
	ft_printf(RESET"%42p\n", &c);
	printf(RED"%-18p\n", &c);
	ft_printf(RESET"%-18p\n", &c);
	printf(RED"%42p\n", &c);
	ft_printf(RESET"%42p\n", &c);
	ft_printf("FLAGS ONLY-------------------------------------\n");
	printf(RED"% 5p\n", &nb);
	ft_printf(RESET"% 5p\n", &nb);
	printf(RED"% -15p\n", &nb);
	ft_printf(RESET"% -15p\n", &nb);
	printf(RED"%+-5p\n", &nb);
	ft_printf(RESET"%+-5p\n", &nb);
	printf(RED"%+42p\n", &nb);
	ft_printf(RESET"%+42p\n", &nb);
	printf(RED"%+-18p\n", &nb);
	ft_printf(RESET"%+-18p\n", &nb);
	printf(RED"% 42p\n", &nb);
	ft_printf(RESET"% 42p\n", &nb);
	printf(RED"%05p\n", &c);
	ft_printf(RESET"%05p\n", &c);
	printf(RED"%+-15p\n", &c);
	ft_printf(RESET"%+-15p\n", &c);
	printf(RED"% -5p\n", &c);
	ft_printf(RESET"% -5p\n", &c);
	printf(RED"%+42p\n", &c);
	ft_printf(RESET"%+42p\n", &c);
	printf(RED"% -18p\n", &c);
	ft_printf(RESET"% -18p\n", &c);
	printf(RED"%+42p\n", &c);
	ft_printf(RESET"%+42p\n", &c);	
	ft_printf("PERCISION ONLY--------------------------------\n");
	printf(RED"%.20p\n", &c);
	ft_printf(RESET"%.20p\n", &c);
	printf(RED"%.30p\n", &c);
	ft_printf(RESET"%.30p\n", &c);
	printf(RED"%.2p\n", &c);
	ft_printf(RESET"%.2p\n", &c);
	printf(RED"%.5p\n", &c);
	ft_printf(RESET"%.5p\n", &c);
	ft_printf("WIDTH & PERCISION--------------------------------\n");
	printf(RED"%30.20p\n", &c);
	ft_printf(RESET"%30.20p\n", &c);
	printf(RED"%20.30p\n", &c);
	ft_printf(RESET"%20.30p\n", &c);
	printf(RED"%5.2p\n", &c);
	ft_printf(RESET"%5.2p\n", &c);
	printf(RED"%2.5p\n", &c);
	ft_printf(RESET"%2.5p\n", &c);	
	ft_printf("WIDTH & PERCISION & FLAGS-------------------------\n");
	printf(RED"%+30.20p\n", &c);
	ft_printf(RESET"%+30.20p\n", &c);
	printf(RED"% 30.20p\n", &c);
	ft_printf(RESET"% 30.20p\n", &c);
	printf(RED"% 20.30p\n", &c);
	ft_printf(RESET"% 20.30p\n", &c);
	printf(RED"%+5.2p\n", &c);
	ft_printf(RESET"%+5.2p\n", &c);
	printf(RED"% 2.5p\n", &c);
	ft_printf(RESET"% 2.5p\n", &c);
}
