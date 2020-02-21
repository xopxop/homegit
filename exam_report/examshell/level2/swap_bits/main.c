#include <stdio.h>

unsigned char swap_bits(unsigned char num);

int main()
{
	printf("%d\n", swap_bits(0));
	printf("%d\n", swap_bits(123));
	printf("%d\n", swap_bits(255));
	printf("%d\n", swap_bits(13));
	printf("%d\n", swap_bits(175));
	printf("%d\n", swap_bits(20));
	printf("%d\n", swap_bits(90));
	return (0);
}
