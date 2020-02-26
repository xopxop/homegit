/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:38:51 by exam              #+#    #+#             */
/*   Updated: 2020/02/25 15:47:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_own_str(char *str, int pos1)
{
	int pos2;
	int check;

	check = 1;
	pos2 = 0;
	while (pos2 < pos1)
	{
		if (str[pos1] == str[pos2])
		{
			check = 0;
			break ;
		}
		pos2++;
	}
	return (check);
}

int	check_other_str(char chr, char *str)
{
	int check;
	int pos;

	check = 1;
	pos = 0;
	while (str[pos] != '\0')
	{
		if (chr == str[pos])
		{
			check = 0;
			break ;
		}
		pos++;
	}
	return (check);
}

int	main(int ac, char **av)
{
	int pos;

	if (ac == 3 && av[1] && av[2])
	{
		pos = 0;
		while (av[1][pos] != '\0')
		{
			if (check_own_str(av[1], pos))
				write(1, &av[1][pos], 1);
			pos++;
		}
		pos = 0;
		while (av[2][pos] != '\0')
		{
			if (check_other_str(av[2][pos], av[1]))
				if (check_own_str(av[2], pos))
					write(1, &av[2][pos], 1);
			pos++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
