#include <unistd.h>

int main(int argc, char **argv)
{
	char *ptr;
	char mirror_chr;
	int difference;

	if (argc == 2)
	{
		ptr = argv[1];
		while (*ptr)
		{
			if (*ptr >= 'a' && *ptr <= 'z')
			{
				difference = 122 - *ptr;
				mirror_chr = 'a' + difference;
				write(1, &mirror_chr, 1);
			}
			else if (*ptr >= 'A' && *ptr <= 'Z')
			{
				difference = 90 - *ptr;
				mirror_chr = 'A' + difference;
				write(1, &mirror_chr, 1);
			}
			else
				write(1, &*ptr, 1);
			ptr++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
