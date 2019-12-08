/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:47:36 by dthan             #+#    #+#             */
/*   Updated: 2019/12/07 18:00:01 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_nbr(char *format, int pos)
{
	int nbr;

	nbr = 0;
	if (!(ft_isdigit(format[pos])))
		return (0);
	while(ft_isdigit(format[pos]))
		nbr = nbr * 10 + (format[pos++] - '0');
	return (nbr);
}


