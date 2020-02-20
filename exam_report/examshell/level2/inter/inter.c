#include <unistd.h>

int check_double(char *str1, int pos)
{
	int newpos;

	newpos = 0;
	while (newpos < pos && pos != 0)
	{
		if (str1[pos] == str1[newpos])
			return (1);
		newpos++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int pos1;
	int pos2;

	if (argc == 3)
	{
		pos1 = 0;
		while (argv[1][pos1])
		{
			pos2 = 0;
			if (!check_double(argv[1], pos1))
			{
				while(argv[2][pos2])
				{
					if (argv[1][pos1] == argv[2][pos2])
					{
						write(1, &argv[1][pos1], 1);
						break ;
					}
					pos2++;
				}
			}
			pos1++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
