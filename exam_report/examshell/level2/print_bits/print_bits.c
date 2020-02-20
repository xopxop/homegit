#include <unistd.h>

void print_bits(unsigned char octet)
{
	if (octet > 0)
	{
		while (octet > 0)
		{	
			if (octet % 2 == 0)
				write (1, "1", 1);
			else
				write (1, "0", 1);
			octet /= 2;
		}
	}
	else if (octet == 0)
		write (1, "0" , 1);
}
