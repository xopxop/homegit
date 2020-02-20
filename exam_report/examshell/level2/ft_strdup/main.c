#include <stdio.h>
#include <string.h>

char *ft_strdup(char *src);

int main()
{
	printf("%s\n", ft_strdup("abc"));
	printf("%s\n", strdup("abc"));
	printf("%s\n", ft_strdup("ab421c"));
	printf("%s\n", strdup("ab421c"));
	printf("%s\n", ft_strdup("ab43c"));
	printf("%s\n", strdup("ab43c"));
	return (0);
}
