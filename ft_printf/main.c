#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{
	ft_printf(RED"%.o %.0o\n", 0, 0);
	printf(RESET"%.o %.0o\n", 0, 0);
}
