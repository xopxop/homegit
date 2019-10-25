/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:59:06 by dthan             #+#    #+#             */
/*   Updated: 2019/10/25 17:14:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

char**ft_strsplit(char const *s, char c)
{
    char **a;
    size_t inside_a_word;
    size_t word_index;
    size_t i;
    size_t start;
    
    if (!s)
        return (NULL);
    if (!(a = (char **)ft_memalloc((ft_countwords(s, c) + 1) * sizeof(char *))))
        return (NULL);
    word_index = 0;
    inside_a_word = 0;
    i = -1;
    start = 0;
    while (s[++i])
    {
        if (inside_a_word && s[i] == c)
            a[word_index++] = ft_strsub(s, start, i - start);
        if (!inside_a_word && s[i] != c)
            start = i;
        inside_a_word = (s[i] == c) ? 0 : 1;
    }
    if (inside_a_word)
        a[word_index] = ft_strsub(s, start, i - start);
    return (a);
}
