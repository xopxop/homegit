#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{
	int a = ft_printf("%hd", -32768);
	ft_printf("\n%d\n", a);
	int b = printf("%hd", -32768);
	printf("\n%d\n", b);
}
