#include <stdio.h>

int is_power_of_2(unsigned int n);

int main()
{
	printf("%d\n", is_power_of_2(0));
	printf("%d\n", is_power_of_2(2));
	printf("%d\n", is_power_of_2(4));
	printf("%d\n", is_power_of_2(8));
	printf("%d\n", is_power_of_2(10));
	printf("%d\n", is_power_of_2(100));
	return (0);
}
