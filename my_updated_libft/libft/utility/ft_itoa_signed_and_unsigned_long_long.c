/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_signed_and_unsigned_long_long.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 08:08:13 by dthan             #+#    #+#             */
/*   Updated: 2020/02/21 08:08:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

static int	getsizenumber(unsigned long long nb)
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

char	*malloc_string(unsigned int size, long long n)
{
	if (n < 0)
		return ((char *)malloc(sizeof(char) * (size + 2)));
	return ((char *)malloc(sizeof(char) * (size + 1)));
}

char	*ft_itoa_signed_longlong(long long n)
{
	char				*string;
	unsigned long long	nbr;
	unsigned int		index;
	unsigned int		size;

	index = 0;
	if (n < 0)
		nbr = (unsigned long long)(n * -1);
	else
		nbr = n;
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

char	*ft_itoa_unsigned_longlong(unsigned long long nbr)
{
	char			*string;
	unsigned int	index;
	unsigned int	size;

	index = 0;
	size = (unsigned int)getsizenumber(nbr);
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string)
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
