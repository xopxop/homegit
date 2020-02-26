#include <unistd.h>

int goto_match(char *str, int i, int step)
{
	int bracket_nbr;

	bracket_nbr = step;
	while (i >= 0 && i <= 4096)
	{
		i += step;
		if (str[i] == ']')
			bracket_nbr--;
		else if (str[i] == '[')
			bracket_nbr++;
		if (bracket_nbr == 0)
			return (i);
	}
	return (0);
}

void brainfuck(char *str)
{
	char array[2049] = {[0 ... 2048] = 0};
	int ptr;
	int i = 0;

	ptr = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>')
			ptr++;
		else if (str[i] == '<')
			ptr--;
		else if (str[i] == '+')
			array[ptr]++;
		else if (str[i] == '-')
			array[ptr]--;
		else if (str[i] == '.')
			write(1, &array[ptr], 1);
		else if (str[i] == '[' && array[ptr] == 0)
			i = goto_match(str, i, 1);
		else if (str[i] == ']' && array[ptr] != 0)
			i = goto_match(str, i, -1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac >= 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
