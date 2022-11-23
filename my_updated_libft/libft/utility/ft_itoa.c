/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:21:14 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 10:24:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

static int	getsizenumber(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (size + 1);
}

char	*malloc_string(unsigned int size, int n)
{
	if (n < 0)
		return ((char *)malloc(sizeof(char) * (size + 2)));
	return ((char *)malloc(sizeof(char) * (size + 1)));
}

char	*ft_itoa(int n)
{
	char			*string;
	unsigned int	nbr;
	unsigned int	index;
	unsigned int	size;

	index = 0;
	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)(n);
	size = (unsigned int)getsizenumber(nbr);
	string = malloc_string(size, n);
	if (!string)
		return (NULL);
	if (n < 0 && (string[index] == '-'))
		size++;
	index = size - 1;
	while (nbr >= 10)
	{
		string[index--] = (char)(nbr % 10 + '0');
		nbr /= 10;
	}
	string[index] = (char)(nbr % 10 + '0');
	string[size] = '\0';
	return (string);
}
