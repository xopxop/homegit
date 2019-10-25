/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:36:03 by dthan             #+#    #+#             */
/*   Updated: 2019/10/24 13:48:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *string, unsigned int start, size_t len)
{
	char *subString;

	if (!string)
		return (NULL);
	if (!(subString = ft_memalloc(len + 1)))
		return (NULL);
	subString = ft_strncpy(subString, (char*)string + start, len);
	return (subString);
}
