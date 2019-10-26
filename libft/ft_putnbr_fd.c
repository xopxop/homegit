/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:48:02 by dthan             #+#    #+#             */
/*   Updated: 2019/10/26 04:51:14 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int filedescriptor)
{
	if (nbr == -2147483648)
	{
		ft_putchar_fd('-', filedescriptor);
		ft_putchar_fd('2', filedescriptor);
		ft_putnbr_fd(147483648, filedescriptor);
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', filedescriptor);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, filedescriptor);
	ft_putchar_fd((nbr % 10) + '0', filedescriptor);
}
