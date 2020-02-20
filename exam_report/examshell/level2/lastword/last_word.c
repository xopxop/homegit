#include <unistd.h>

int main(int argc, char **argv)
{
	int pos;
	int pos_last_word;

	if (argc == 2 && argv[1] != '\0')
	{
		pos = 0;
		pos_last_word = 0;
		while (argv[1][pos] != '\0')
		{
			if (argv[1][pos] != ' ' && argv[1][pos] != '\t')
			{	
				pos_last_word = pos;
				while (argv[1][pos] != ' ' && argv[1][pos] != '\t' && argv[1][pos] != '\0')
					pos++;
			}
			else
				pos++;
		}
		while (argv[1][pos_last_word] != '\0' && argv[1][pos_last_word] != ' ' && argv[1][pos_last_word] != '\t')
			write(1, &argv[1][pos_last_word++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
