/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:10:52 by dthan             #+#    #+#             */
/*   Updated: 2019/11/13 11:18:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int first = 3;
	int second = 6;

	printf("FIRST: %d\nSECOND: %d\n", first, second);
	ft_swap(&first, &second);
	printf("FIRST: %d\nSECOND: %d\n", first, second);
}
