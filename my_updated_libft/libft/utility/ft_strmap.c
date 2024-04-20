/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:56:47 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 23:01:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

char	*ft_strmap(char const *string, char (*f)(char))
{
	char	*newstring;
	char	*pstring;
	char	*pnewstring;

	if (!string || !f)
		return (NULL);
	newstring = ft_memalloc((size_t)ft_strlen((char *)string) + 1);
	if (!newstring)
		return (NULL);
	pstring = (char *)string;
	pnewstring = newstring;
	while (*pstring)
		*(pnewstring++) = f(*(pstring++));
	return (newstring);
}
