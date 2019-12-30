/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testdi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:20:50 by dthan             #+#    #+#             */
/*   Updated: 2019/12/30 12:20:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

int main(void)
{
    int		nb;

    nb = 45;
    ft_printf("-------D---------\n");
	ft_printf("-space% d-\n", nb);
    printf( RED"-space% d-" RESET"\n", nb);
	ft_printf("-plus:%+d-\n", nb);
    printf( RED"-plus:%+d-" RESET"\n", nb);
	ft_printf("-precision:%.5d-\n", nb);
    printf( RED"-precision:%.5d-" RESET"\n", nb);
	ft_printf("-space + prec:% .5d-\n", nb);
    printf(RED "-space + prec:% .5d-" RESET"\n", nb);
	ft_printf("-Plus + prec / grande:%+.5d-\n", nb);
    printf( RED "-Plus + prec / grande:%+.5d-" RESET"\n", nb);
	ft_printf("-Plus + prec / petite:%+.0d-\n", nb);
    printf( RED"-Plus + prec / petite:%+.0d-"RESET"\n", nb);
	ft_printf("-Prec + 0:%0.5d-\n", nb);
    printf( RED"-Prec + 0:%0.5d-"RESET"\n", nb);
	ft_printf("-Prec + minus:%-.5d-\n", nb);
    printf(RED"-Prec + minus:%-.5d-"RESET"\n", nb);
	ft_printf("-size:%5d-\n", nb);
    printf(RED"-size:%5d-"RESET"\n", nb);
	ft_printf("-size + space:% 5d-\n", nb);
    printf(RED"-size + space:% 5d-"RESET"\n", nb);
	ft_printf("-size + plus:%+5d-\n", nb);
    printf(RED"-size + plus:%+5d-"RESET"\n", nb);
	ft_printf("-size + minus:%-5d-\n", nb);
    printf(RED"-size + minus:%-5d-"RESET"\n", nb);
	ft_printf("size + 0:%05d-\n", nb);
    printf(RED"size + 0:%05d-"RESET"\n", nb);
	ft_printf("size + 0 + plus:%+05d-\n", nb);
    printf(RED"size + 0 + plus:%+05d-"RESET"\n", nb);
	ft_printf("size + 0 + plus:%0+5d-\n", nb);
    printf(RED"size + 0 + plus:%0+5d-"RESET"\n", nb);
	ft_printf("size + 0 + prec:%05.3d-\n", nb);
    printf(RED"size + 0 + prec:%05.3d-"RESET"\n", nb);
	ft_printf("size + minus + prec:%-5.3d-\n", nb);
    printf(RED"size + minus + prec:%-5.3d-"RESET"\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3d-\n", nb);
    printf(RED"size + plus + 0 + prec:%+05.3d-"RESET"\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3d-\n", nb);
    printf(RED"size + espace + zero + prec:%0 5.3d-"RESET"\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3d-\n", nb);
    printf(RED"size + espace + zero + prec:% 05.3d-"RESET"\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3d-\n", nb);
    printf(RED"size + minus + plus + prec:%-+5.3d-"RESET"\n", nb);

    ft_printf("\n--------I----------\n");

    ft_printf("space% i\n", nb);
	printf(RED"space% i"RESET"\n", nb);
	ft_printf("plus:%+i\n", nb);
	printf(RED"plus:%+i"RESET"\n", nb);
	ft_printf("precision:%.5i\n", nb);
	printf(RED"precision:%.5i"RESET"\n", nb);
	ft_printf("space + prec:% .5i\n", nb);
	printf(RED"space + prec:% .5i"RESET"\n", nb);
	ft_printf("Plus + prec / grande:%+.5i\n", nb);
	printf(RED"Plus + prec / grande:%+.5i"RESET"\n", nb);
	ft_printf("Plus + prec / petite:%+.0i\n", nb);
	printf(RED"Plus + prec / petite:%+.0i"RESET"\n", nb);
	ft_printf("Prec + 0:%0.5i\n", nb);
	printf(RED"Prec + 0:%0.5i"RESET"\n", nb);
	ft_printf("Prec + minus:%-.5i\n", nb);
	printf(RED"Prec + minus:%-.5i"RESET"\n", nb);
	ft_printf("size:%5i\n", nb);
	printf(RED"size:%5i"RESET"\n", nb);
	ft_printf("size + space:% 5i\n", nb);
	printf(RED"size + space:% 5i"RESET"\n", nb);
	ft_printf("size + plus:%+5i\n", nb);
	printf(RED"size + plus:%+5i"RESET"\n", nb);
	ft_printf("size + minus:%-5i\n", nb);
	printf(RED"size + minus:%-5i"RESET"\n", nb);
	ft_printf("size + 0:%05i\n", nb);
	printf(RED"size + 0:%05i"RESET"\n", nb);
	ft_printf("size + 0 + plus:%+05i\n", nb);
	printf(RED"size + 0 + plus:%+05i"RESET"\n", nb);
	ft_printf("size + 0 + plus:%0+5i\n", nb);
	printf(RED"size + 0 + plus:%0+5i"RESET"\n", nb);
	ft_printf("size + 0 + prec:%05.3i\n", nb);
	printf(RED"size + 0 + prec:%05.3i"RESET"\n", nb);
	ft_printf("size + minus + prec:%-5.3i\n", nb);
	printf(RED"size + minus + prec:%-5.3i"RESET"\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3i\n", nb);
	printf(RED"size + plus + 0 + prec:%+05.3i"RESET"\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3i\n", nb);
	printf(RED"size + espace + zero + prec:%0 5.3i"RESET"\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3i\n", nb);
	printf(RED"size + espace + zero + prec:% 05.3i"RESET"\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3i\n", nb);
	printf(RED"size + minus + plus + prec:%-+5.3i"RESET"\n", nb);

}
