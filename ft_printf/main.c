#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{
	ft_printf(RED"--%5%--\n"); 
	printf(RESET"--%5%--\n"); 
}
