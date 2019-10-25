/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:15:10 by dthan             #+#    #+#             */
/*   Updated: 2019/10/25 18:33:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_wordct(char const *string, char delimeter)
{
    size_t ct;
    int insideAword;

    insideAword = 0;
    ct = 0;
    while (*string)
    {
        if (!insideAword && *string != delimeter)
            ct++;
        insideAword = (*string == delimeter) ? 0 : 1;
        string++;
    }
    return (ct);
}

char    **ft_strsplit(char const *string, char delimeter)
{
    char **freshStringArray;
    size_t checkInsideAWord;
    size_t indexWord;
    size_t indexString;
    size_t start;

    if (!string)
        return (NULL);
    if (!(freshStringArray = (char**)ft_memalloc((ft_wordct(string, delimeter) + 1) * sizeof(char*))))
        return (NULL);
    indexWord = 0;
    checkInsideAWord = 0;
    indexString = -1;
    start = 0;
    while (string[++indexString])
    {
        if (checkInsideAWord && string[indexString] == delimeter)
            freshStringArray[indexWord++] = ft_strsub(string, start, indexString - start);
        if (!checkInsideAWord && string[indexString] != delimeter)
            start = indexString;
        checkInsideAWord = (string[indexString] == delimeter) ? 0 : 1;
    }
    if(checkInsideAWord)
        freshStringArray[indexWord] = ft_strsub(string, start, indexString - start);
    return (freshStringArray);
}
