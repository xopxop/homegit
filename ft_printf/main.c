#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{
	printf(RED"%p", 0);
	printf("\n");
	ft_printf(RESET"%p", 0);
//	ft_printf("%hd%hd", (short int)0, (short int)42);
}
