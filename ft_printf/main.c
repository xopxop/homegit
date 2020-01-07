#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{
	int a;
	int b;
	a = ft_printf("%s\n", "this is a string");
	b = printf("%s\n", "this is a string");
	printf("%d--%d\n", a, b);
}
