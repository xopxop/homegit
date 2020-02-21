#include <unistd.h>

int main(int argc, char **argv)
{
	int pos1;
	int pos2;
	int check;
	int pos3;

	if (argc == 3)
	{
		pos1 = 0;
		while (argv[1][pos1] != '\0')
		{
			if (pos1 == 0)
				write(1, &argv[1][pos1], 1);
			pos2 = 0;
			while (pos2 < pos1)
			{
				if (argv[1][pos1] != argv[1][pos2])
				{
					write(1, &argv[1][pos1], 1);
					break ;
				}
				else
					pos2++;
			}
			pos1++;

		}
		pos2 = 0;
		while (argv[2][pos2] != '\0')
		{
			pos1 = 0;
			check = 0;
			while (argv[1][pos1] != '\0')
			{
				if (argv[2][pos2] == argv[1][pos1])
				{
					check = 1;
					break ;
				}
				else
					pos1++;
			}
			if (!check)
			{
				pos3 = 0;
				while(pos3 < pos2)
				{
					if (argv[2][pos2] == argv[2][pos3])
					{
						check = 1;
						break ;
					}
					else
						pos3++;
				}
			}
			if (!check)
				write(1, &argv[2][pos2], 1);
			pos2++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
