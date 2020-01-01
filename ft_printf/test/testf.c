/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 12:21:21 by dthan             #+#    #+#             */
/*   Updated: 2019/12/31 10:19:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

int			main(void)
{
	double		nb;
	nb = 12547.58;

	ft_printf(RESET"test basique:");printf(RED"test basique:");
    ft_printf(RESET"space:% f\n", nb);printf(RED"space:% f\n", nb);
    ft_printf(RESET"plus:%+f\n", nb);printf(RED"plus:%+f\n", nb);
    ft_printf(RESET"hash:%#f\n", nb);printf(RED"hash:%#f\n", nb);
    ft_printf(RESET"precision:%.2f\n", nb);printf(RED"precision:%.2f\n", nb);
    ft_printf(RESET"big prec:%.14f\n", nb);printf(RED"big prec:%.14f\n", nb);
    ft_printf(RESET"precision + hash:%#.0f\n", nb);printf(RED"precision + hash:%#.0f\n", nb);
    ft_printf(RESET"space + prec:% .5f\n", nb);printf(RED"space + prec:% .5f\n", nb);
    ft_printf(RESET"space + prec + hash:%# .0f\n", nb);printf(RED"space + prec + hash:%# .0f\n", nb);
    ft_printf(RESET"space + prec + hash:% #.0f\n", nb);printf(RED"space + prec + hash:% #.0f\n", nb);
    ft_printf(RESET"Plus + prec / grande:%+.5f\n", nb);printf(RED"Plus + prec / grande:%+.5f\n", nb);
    ft_printf(RESET"Plus + prec / petite:%+.0f\n", nb);printf(RED"Plus + prec / petite:%+.0f\n", nb);
    ft_printf(RESET"Plus + prec + hash:%#+.0f\n", nb);printf(RED"Plus + prec + hash:%#+.0f\n", nb);
    ft_printf(RESET"Prec + 0:%0.5f\n", nb);printf(RED"Prec + 0:%0.5f\n", nb);
    ft_printf(RESET"Prec + minus:%-.5f\n", nb);printf(RED"Prec + minus:%-.5f\n", nb);
    ft_printf(RESET"size:%5f\n", nb);printf(RED"size:%5f\n", nb);
    ft_printf(RESET"size + space:% 5f\n", nb);printf(RED"size + space:% 5f\n", nb);
    ft_printf(RESET"size + plus:%+5f\n", nb);printf(RED"size + plus:%+5f\n", nb);
    ft_printf(RESET"size + space:%# 5f\n", nb);printf(RED"size + space:%# 5f\n", nb);
    ft_printf(RESET"size + plus:%#+5f\n", nb);printf(RED"size + plus:%#+5f\n", nb);
    ft_printf(RESET"size + minus:%-5f\n", nb);printf(RED"size + minus:%-5f\n", nb);
    ft_printf(RESET"size + 0:%05f\n", nb);printf(RED"size + 0:%05f\n", nb);
    ft_printf(RESET"size + 0 + plus:%+05f\n", nb);printf(RED"size + 0 + plus:%+05f\n", nb);
    ft_printf(RESET"size + 0 + plus:%0+5f\n", nb);printf(RED"size + 0 + plus:%0+5f\n", nb);
    ft_printf(RESET"size + 0 + prec:%05.3f\n", nb);printf(RED"size + 0 + prec:%05.3f\n", nb);
    ft_printf(RESET"size + 0 + prec + hash:%0#5.0f\n", nb);printf(RED"size + 0 + prec + hash:%0#5.0f\n", nb);
    ft_printf(RESET"size + minus + prec:%-5.3f\n", nb);printf(RED"size + minus + prec:%-5.3f\n", nb);
    ft_printf(RESET"size + minus + prec + hash:%-#5.0f\n", nb);printf(RED"size + minus + prec + hash:%-#5.0f\n", nb);
    ft_printf(RESET"size + plus + 0 + prec:%+05.3f\n", nb);printf(RED"size + plus + 0 + prec:%+05.3f\n", nb);
    ft_printf(RESET"size + plus + 0 + prec + hash:%0+#5.0f\n", nb);printf(RED"size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    ft_printf(RESET"size + espace + zero + prec:%0 5.3f\n", nb);printf(RED"size + espace + zero + prec:%0 5.3f\n", nb);
    ft_printf(RESET"size + espace + zero + prec:% 05.3f\n", nb);printf(RED"size + espace + zero + prec:% 05.3f\n", nb);
    ft_printf(RESET"size + espace + zero + prec + hash:%#0 5.0f\n", nb);printf(RED"size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    ft_printf(RESET"size + minus + plus + prec:%-+5.3f\n", nb);printf(RED"size + minus + plus + prec:%-+5.3f\n", nb);
    ft_printf(RESET"size + minus + plus + prec + hash:%-#+5.0f\n", nb);printf(RED"size + minus + plus + prec + hash:%-#+5.0f\n", nb);
}
