/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:45:26 by dthan             #+#    #+#             */
/*   Updated: 2019/11/13 11:06:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : rotone
** Expected files   : rotone.c
** Allowed functions: write
** -----------------------------------------------------------------------------
**
** Write a program that takes a string and displays it, replacing each of its
** letters by the next one in alphabetical order.
**
** 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
**
** The output will be followed by a newline.
**
** If the number of arguments is not 1, the program displays a newline.
**
** Example:
**
** $>./rotone "abc"
** bcd
** $>./rotone "So long, and thanks for all the fish." | cat -e
** Tp mpoh, boe uibolt gps bmm uif gjti.$
** $>./rotone "AkjhZ zLKIJz , 23y " | cat -e
** BlkiA aMLJKa , 23z $
** $>./rotone | cat -e
** $
** $>
** $>./rotone "" | cat -e
** $
** $>
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		while (*av[1])
		{
			if ((*av[1] >= 'A' && *av[1] <= 'Z') || \
					(*av[1] >= 'a' && *av[1] <= 'z'))
			{
				if (*av[1] == 'Z' || *av[1] == 'z')
				{
					*av[1] -= 25;
					write(1, av[1], 1);
				}
				else
				{
					*av[1] += 1;
					write(1, av[1], 1);
				}
			}
			else
				write(1, av[1], 1);
			*av[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
