#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{
	printf(RED"Test\n");
	printf("%");

	ft_printf(RESET"\nTest\n");
	ft_printf("%");
}
