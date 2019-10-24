/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:55:44 by dthan             #+#    #+#             */
/*   Updated: 2019/10/24 14:25:37 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *string1, char const *string2)
{
	char *jointString;
	size_t jointStringSize;

	if (string1 && string2)
		jointStringSize = (size_t)(ft_strlen(string1) + ft_strlen(string2));
	else if (string1)
		jointStringSize = (size_t)(ft_strlen(string1));
	else if (string2)
		jointStringSize = (size_t)(ft_strlen(string2));
	else
		return (NULL);
	if (!(jointString = ft_memalloc(jointStringSize + 1)))
		return (NULL);
	if (string1)
		jointString = ft_strcpy(jointString, (char*)string1);
	else if (string2)
		jointString = ft_strcpy(jointString, (char*)string2);
	if (string1 && string2)
		jointString = ft_strcat(jointString, (char*)string2);
	return (jointString);
}
