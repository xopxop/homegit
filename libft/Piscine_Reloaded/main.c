// ex08
/*
void	ft_is_negative(int n);

int main(void)
{
	int number;

//	number = -2147483648;
//	number = 0;
	number = 2147483647;
	ft_is_negative(number);
}
*/

// ex09
/*
#include <stdio.h>

void	ft_ft(int *nbr);

int main(void)
{
	int nbr;

	ft_ft(&nbr);
	printf("%d", nbr);
}
*/

// ex10
/*
#include <stdio.h>

void	ft_swap(int *a, int *b);

int main(void)
{
	int a = 2, b = 3;
	printf("a = %d, b = %d\nSwap\n", a, b);
	ft_swap(&a, &b);
	printf("a = %d, b = %d", a, b);
}
*/

// ex11
/*
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
	int a = 20, b = 3, div, mod;

	ft_div_mod(a, b, &div, &mod);
	printf("Div = %d\nMod = %d", div, mod);
}
*/

// ex12
/*
#include <stdio.h>

int ft_iterative_factorial(int nb);

int main(void)
{
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(1));
	printf("%d\n", ft_iterative_factorial(-4));
	printf("%d\n", ft_iterative_factorial(4));
	printf("%d\n", ft_iterative_factorial(14));
}
*/

// ex13
/*
#include <stdio.h>

int ft_recusive_factorial(int nb);

int main(void)
{
	printf("%d\n", ft_recusive_factorial(0));
	printf("%d\n", ft_recusive_factorial(1));
	printf("%d\n", ft_recusive_factorial(-4));
	printf("%d\n", ft_recusive_factorial(4));
	printf("%d\n", ft_recusive_factorial(14));
	printf("%d\n", ft_recusive_factorial(12));
}
*/

// ex14
/*
#include <stdio.h>

int	ft_sqrt(int nb);

int main(void)
{
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(-25));
	printf("%d\n", ft_sqrt(126));
	printf("%d\n", ft_sqrt(2124445675));

}

*/

// ex15
/*
#include <unistd.h>


void	ft_putstr(char *str);

int main(void)
{
	char *str = "absgdsqw";
	ft_putstr(str);
}
*/

//ex16
/*
#include <stdio.h>

int ft_strlen(char *str);

int main(void)
{
	char *str = "abcd";
	printf("%d", ft_strlen(str));
}
*/

//ex17
/*
#include <stdio.h>

int ft_strcmp(char *s1, char *s2);

int main(void)
{
	char *str1 = "";
	char *str2 = "act";
	printf("%d\n", ft_strcmp(str1, str2));
}
*/

//ex 20

#include <string.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{

	char *str = "hello";
	printf("%s\n", strdup(str));
	printf("%s\n", ft_strdup(str));

	char *str2 = "test";
	printf("%s\n", strdup(str2));
	printf("%s\n", ft_strdup(str2));
}

// ex21
/*
#include <stdio.h>

int *ft_range(int min, int max);
void    putarr(int *arr);

int main(void)
{
	int *arr;
	int *arr2;
	int j = 5;
	int i = 0;
	arr = ft_range(5, 9);
	arr2 = ft_range(9, 4);
	while (j < 9)
	{
		printf("%d", arr[i]);
		i++;
		j++;
	}
}
*/

// ex22
/*
#include "ft_abs.h"
#include <stdio.h>

int main(void)
{
	int x;
	x  = ABS(-12);
	printf("%d", x);
}
*/

// ex23
/*
#include "ft_point.h"

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int main(void)
{
	t_point point;
	set_point(&point);
	return (0);
}
*/

//ex25
/*
#include <unistd.h>

void	ft_foreach(int *tab, int length, void(*f)(int));
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int main(void)
{
	int nums[] = {0, 1, 2, 3, 4};
	int length = 5;
	void (*f)(int);
	f = &ft_putnbr;
	ft_foreach(nums, length, f);
}
*/

// ex26
/*
#include <stdio.h>

int	ft_count_if(char **tab, int (*f)(char*));

int ainarr(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int main(void)
{
	//char *arr0 = "hello";
   	//char *arr1 = "hallo";
	//char *arr2 = "who";	
	char *arr3[4];
	arr3[0] = "ha";
	arr3[1] = "haama";
	arr3[2] = "ha";
	arr3[3] = 0;
	int (*f)(char*);
	f = &ainarr;

	printf("%d", ft_count_if(arr3, f));
}
*/
