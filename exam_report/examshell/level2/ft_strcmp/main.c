#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int main()
{
	printf("%d\n", ft_strcmp("abc", "abc"));
	printf("%d\n", strcmp("abc", "abc"));
	printf("%d\n", ft_strcmp("aby", "abz"));
	printf("%d\n", strcmp("aby", "abz"));
	printf("%d\n", ft_strcmp("c1", "c4"));
	printf("%d\n", strcmp("c1", "c4"));
	printf("%d\n", ft_strcmp("0123423", "01234"));
	printf("%d\n", strcmp("0123423", "1234"));
	return (0);
}
