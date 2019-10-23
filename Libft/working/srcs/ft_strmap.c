/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:56:47 by dthan             #+#    #+#             */
/*   Updated: 2019/10/23 13:58:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *string, char (*f)(char))
{
	char *newString;
	char *pstring;
	char *pnewString;

	if (!string || !f || !(newString = ft_memalloc((size_t)ft_strlen((char*)string) + 1)))
		return (NULL);
	pstring = (char*)string;
	pnewString = newString;
	while (*pstring)
		*(pnewString++) = f(*(pstring++));
	return (newString);
}
