#include <string.h>
#include <stdio.h>

void ftt_toupper(unsigned int i, char *c) {
    if (*c >= 'a' && *c <= 'a')
        *c -= 32;
    else
        *c = *c;
}

void    ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    i = 0;
    if (!s || !f || !*(s))
        return ;
    while (s[i])
	{
        f(i, &s[i]);
		i++;
	}
}

int main(void) {
    char s[] = "aaaa";

    ft_striteri(s, ftt_toupper);
    printf("%s", s);
}
