/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:32:09 by dthan             #+#    #+#             */
/*   Updated: 2019/10/25 18:32:44 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void    *ft_memalloc(size_t size)
{
            void *ptr;

                    if(!(ptr = malloc(size)))
                                        return (NULL);
                            bzero(ptr, size);
                                    return (ptr);
}

char    *ft_strncpy(char *dst, const char *src, size_t len)
{
            size_t ct;

                    ct = 0;
                            while ((src[ct]) && (ct < len))
                                        {
                                                            dst[ct] = src[ct];
                                                                            ct++;
                                                                                    }
                                    while (ct < len)
                                                {
                                                                    dst[ct] = '\0';
                                                                                    ct++;
                                                                                            }
                                            return (dst);
}

char    *ft_strsub(char const *string, unsigned int start, size_t len)
{
            char *subString;

                    if (!string)
                                        return (NULL);
                            if (!(subString = ft_memalloc(len + 1)))
                                                return (NULL);
                                    subString = ft_strncpy(subString, (char*)string + start, len);
                                            return (subString);
}

int ft_countwords(char const *str, char c)
{
        size_t  count;
            int     inside_a_word;

                inside_a_word = 0;
                    count = 0;
                        while (*str)
                                {
                                            if (!inside_a_word && *str != c)
                                                            count++;
                                                    inside_a_word = (*str == c) ? 0 : 1;
                                                            str++;
                                                                }
                            return (count);
}
char    **ft_strsplit(char const *s, char c)
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

int main(void) {
            char **s;
                    int i;

                            i = 0;
                                    s = ft_strsplit("*hello*fellow***students*", '*');
                                            while (s[i])
                                                        {
                                                                            printf("%s\n", s[i]);
                                                                                            i++;
                                                                                                    }
}
