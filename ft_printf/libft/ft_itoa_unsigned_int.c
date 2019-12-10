/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 00:28:04 by dthan             #+#    #+#             */
/*   Updated: 2019/12/10 00:28:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	getsizenumber(unsigned int nb)
{
	unsigned int size;

	size = 0;
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa_unsigned_int(unsigned int nbr)
{
	char			*string;
	unsigned int	index;
	unsigned int	size;

	size = (unsigned int)getsizenumber(nbr);
	if (!(string = (char*)malloc(sizeof(char) *
					(size + 1 ))))
		return (NULL);
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
