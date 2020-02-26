/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:54:17 by exam              #+#    #+#             */
/*   Updated: 2020/02/25 16:50:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int nb;
	int sign;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || \
			*str == '\f' || *str == '\r')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	nb = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}

int		is_prime_nbr(int nbr)
{
	int i;

	i = 2;
	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int nb;
	int sum;
	int i;

	if (ac == 2 && av[1] && ((nb = ft_atoi(av[1])) > 0))
	{
		if (nb == 1)
			write(1, "1\n", 2);
		else
		{
			sum = 0;
			i = 2;
			while (i <= nb)
			{
				if (is_prime_nbr(i))
					sum += i;
				i++;
			}
			ft_putnbr(sum);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "0\n", 2);
	return (0);
}
