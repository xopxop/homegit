#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{	
	printf(RED"%.5p", 0);
	ft_printf("\n");
	ft_printf(RESET"%.5p", 0);
}
