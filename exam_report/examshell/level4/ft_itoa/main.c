#include <stdio.h>
#include <limits.h>

char *ft_itoa(int nbr);

int main()
{
	printf("%s\n", ft_itoa(12));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
	return (0); 
}
