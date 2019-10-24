/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:25:48 by dthan             #+#    #+#             */
/*   Updated: 2019/10/24 15:47:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *string)
{
	size_t stringStart;
	size_t stringEnd;

	stringStart = 0;
	stringEnd = ft_strlen(string);
	if (!string)
		return (0);
	while (ft_isspace(string[stringStart]))
		stringStart++;
	while (ft_isspace(string[stringEnd - 1]))
		stringEnd--;
	if (stringStart < stringEnd)
		return (ft_strsub(string, stringStart, stringEnd - stringStart));
	else
		return (0);
}
