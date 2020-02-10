#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{	
	printf("%+#5x", -42);
//	ft_printf("\n");
//	ft_printf("%+#5x", 42);
}
