/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:42:08 by dthan             #+#    #+#             */
/*   Updated: 2019/10/24 13:03:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *string1, char const *string2)
{
	if (!string1 || !string2)
		return (0);
	return(ft_strcmp(string1, string2) ? 0 : 1);
}
