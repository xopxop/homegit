/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 05:19:49 by dthan             #+#    #+#             */
/*   Updated: 2019/12/08 05:25:05 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <cstdint>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_putstr(char const *pstring)
{
    if (pstring)
        while (*pstring)
            ft_putchar(*pstring++);
}

static char    *convert(uint64_t p)
{
    int        i;
    char    *s;
    char    *hex;

    NULL_CHECK(!(s = (char*)pt_strnew(14)));
    hex = "0123456789abcdef";
    s[0] = '0';
    s[1] = 'x';
    i = 2;
    if (!p)
        s[2] = '0';
    while (p)
    {
        s[i] = hex[p & 15];
        p >>= 4;
        i++;
    }
    pt_strrev(&s[2]);
    return (s);
}

int main() {
  
  uint64_t    p;
  char        *s;
  int            len;
    
  p = 140722110259732;
  s = convert(p);
  pt_putstr(s);
  free(s);
    
  return 0;
}
