#include <stdio.h>
#include "includes/ft_printf.h"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#include <stdlib.h>

int main(void)
{
//	printf("%.3f\n", 23.46964);

//	printf(RED"Test\n");
//	printf("%f\n", 23.00041);
/*	printf("%f\n", 0.000001);
	printf("%f\n", -875.000001);
	printf("%f\n", 0.0894255);
	printf("%f\n", 43.4399999);
	printf("%f\n", -5.0299999);
	printf("%f\n", 3.9999999);
	printf("%f\n", -5.9999999);
	printf("this %.0f float\n", 1.6);
	printf("%.0f\n", -3.85);
	printf("Il fait au moins %015Lf\n", (long double)-8000);

*/
//	ft_printf(RESET"Test\n");
//	ft_printf("%f\n", 23.00041);
/*	ft_printf("%f\n", 0.000001);
	ft_printf("%f\n", -875.000001);
	ft_printf("%f\n", 0.0894255);
	ft_printf("%f\n", 43.4399999);
	ft_printf("%f\n", -5.0299999);
	ft_printf("%f\n", 3.9999999);
	ft_printf("%f\n", -5.9999999);
	ft_printf("this %.0f float\n", 1.6);
	ft_printf("%.0f\n", -3.85);
	ft_printf("Il fait au moins %015Lf\n", (long double)-8000);
*/
	printf("%f\n", 43.4399999);
	ft_printf("%f\n", 43.4399999);
}
