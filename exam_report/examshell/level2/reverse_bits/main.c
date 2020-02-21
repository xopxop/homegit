#include <stdio.h>

unsigned char reverse_bits(unsigned char num);

int main()
{
	printf("%d\n", reverse_bits(1));
	printf("%d\n", reverse_bits(0));
	printf("%d\n", reverse_bits(2));
	printf("%d\n", reverse_bits(255));
	printf("%d\n", reverse_bits(8));
	return (0);
}
