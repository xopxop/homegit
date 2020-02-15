#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{
	int i;
//	printf("%15.9p\n", 1234567);
//	printf("%+0#- 2.9p\n", 1234567);
printf("%#08x\n", 42); 
//	printf("hese%");

	ft_printf(RED"Test\n");
ft_printf("%#08x\n", 42); 
//	ft_printf("%15.9p\n", 1234567);
//	ft_printf("%+0#- 2.9p\n", 1234567);
//	ft_printf("%");
}