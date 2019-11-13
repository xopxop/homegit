/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:06:23 by dthan             #+#    #+#             */
/*   Updated: 2019/11/13 11:18:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assignment name  : ft_swap
** Expected files   : ft_swap.c
** Allowed functions:
** -----------------------------------------------------------------------------
**
** Write a function that swaps the content of two integers.
** The addresses of those integers are passed as parameters to the function.
**
** Your function must be declared as follows:
**
**void    ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
