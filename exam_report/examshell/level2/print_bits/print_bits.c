#include <unistd.h>

void print_bits(unsigned char octet)
{
	int z;

	z = 128;
	while (z > 0)
	{
		if (z & octet)
			write (1, "1", 1);
		else
			write (1, "0", 1);
		z >>= 1;
	}
}
