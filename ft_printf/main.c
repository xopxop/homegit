#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{	
	printf(RED"Test\n");
	printf("%#.3x\n", 32123142);
	printf("%x\n", 32123142);
//	printf("%#++#-5x\n", 42);
//	printf("%+o\n", 42);
//	printf("% o\n", 42);
//	printf("%+x\n", 42);
//	printf("% x\n", 42);
//	printf("%+X\n", 42);
//	printf("% X\n", 42);
//	printf("Il fait au moins %f\n", (double)-8000);
	
//	ft_printf(RESET"Test\n");
//	ft_printf("% 5x\n");
//	ft_printf("%#++#-5x\n", 42);
//	ft_printf("%+o\n", 42);
//	ft_printf("% o\n", 42);
//	ft_printf("%+x\n", 42);
//	ft_printf("% x\n", 42);
//	ft_printf("%+X\n", 42);
//	ft_printf("% X\n", 42);
//	ft_printf("Il fait au moins %f\n", (double)-8000);
}
