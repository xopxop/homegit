#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str);

int main()
{
	printf ("%d\n", ft_atoi("123"));
	printf ("%d\n", atoi("123"));
	printf ("%d\n", ft_atoi("-123"));
	printf ("%d\n", atoi("-123"));
	printf ("%d\n", ft_atoi("12312312312323"));
	printf ("%d\n", atoi("12312312312323"));
	printf ("%d\n", ft_atoi("-123123321321123"));
	printf ("%d\n", atoi("-123123321321123"));
	printf ("%d\n", ft_atoi("0"));
	printf ("%d\n", atoi("0"));
	printf ("%d\n", ft_atoi(" \t\n\v\f\r 2132"));
	printf ("%d\n", atoi(" \t\n\v\f\r 2132"));
	return (0);
}
