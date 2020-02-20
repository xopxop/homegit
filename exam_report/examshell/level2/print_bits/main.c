#include <unistd.h>

void print_bits(unsigned char octet);

int main()
{
	print_bits(1);
	write(1, "\n", 1);
	print_bits(0);
	write(1, "\n", 1);
	print_bits(7);
	write(1, "\n", 1);
	print_bits(8);
	write(1, "\n", 1);
}
