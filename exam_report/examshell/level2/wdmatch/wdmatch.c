#include <unistd.h>

int main(int argc, char **argv)
{
	int pos1;

	int pos2;
	if (argc == 3)
	{
		pos1 = 0;
		pos2 = 0;
		while (argv[2][pos2] != '\0' && argv[1][pos1] != '\0')
		{
			if (argv[2][pos2] == argv[1][pos1])
				pos1++;
			if (argv[1][pos1] == '\0' && pos1 != 0)
			{
				pos1 = 0;
				while(argv[1][pos1])
					write(1, &argv[1][pos1++], 1);
			}
			pos2++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
