#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{	
	ft_printf("%#08x", 42);
	ft_printf("\n");
	printf("%#08x", 42);
}