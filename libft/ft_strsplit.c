/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:15:10 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 08:45:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *string, char c)
{
	char	**re;
	size_t	checkinsideaword;
	size_t	indexword;
	size_t	indexstring;
	size_t	start;

	if (!string)
		return (NULL);
	if (!(re = (char**)ft_memalloc((ft_countwords(string, c) + 1) * sizeof(char*))))
		return (NULL);
	indexword = 0;
	checkinsideaword = 0;
	indexstring = -1;
	start = 0;
	while (string[++indexstring])
	{
		if (checkinsideaword && string[indexstring] == c)
			re[indexword++] = ft_strsub(string, start, indexstring - start);
		if (!checkinsideaword && string[indexstring] != c)
			start = indexstring;
		checkinsideaword = (string[indexstring] == c) ? 0 : 1;
	}
	if (checkinsideaword)
		re[indexword] = ft_strsub(string, start, indexstring - start);
	return (re);
}
