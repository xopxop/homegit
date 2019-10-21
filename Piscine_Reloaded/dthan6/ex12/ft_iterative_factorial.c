/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:24:38 by dthan             #+#    #+#             */
/*   Updated: 2019/10/14 16:50:48 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int factorial;
	int i;

	factorial = 1;
	i = 1;
	if (nb < 0 || nb > 12)
		return (0);
	else
		while (i <= nb)
		{
			factorial *= i;
			i++;
		}
	return (factorial);
}
