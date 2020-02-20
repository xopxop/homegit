#include <stdlib.h>

int ft_strlen(char *str)
{
	int ct;

	ct = 0;
	while (*str++)
		ct++;
	return (ct);
}

char *ft_strdup(char *src)
{
	char *dest;
	int pos;

	if (!(dest = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	pos = 0;
	while (src[pos] != '\0')
	{
		dest[pos] = src[pos];
		pos++;
	}
	return (dest);
}
