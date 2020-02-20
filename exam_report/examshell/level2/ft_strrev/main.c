#include <stdio.h>

char *ft_strrev(char *str);

int main()
{
	char str1[] = "abcde";
	char str2[] = "abcd";
	printf("%s\n", ft_strrev(str1));
	printf("%s\n", ft_strrev(str2));
	return (0);
}
