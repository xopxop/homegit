#include <stdio.h>

char *ft_strcpy(char *s1, char*s2);

int main()
{
	char s1[] = "Hi there";
	char *s2 = "Hello";

	printf("%s\n", s1);
	ft_strcpy(s1, s2);
	printf("%s\n", s1);
	return (0);
}
