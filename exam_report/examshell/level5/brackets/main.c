#include <unistd.h>

int match(char close_bracket, char open_bracket)
{
	if (close_bracket == ')' && open_bracket == '(')
		return (1);
	else if (close_bracket == ']' && open_bracket == '[')
		return (1);
	else if	(close_bracket == '}' && open_bracket == '{')
		return (1);
	return (0);
}

int brackets(char *str)
{
	int stack[4094];
	int pos_stack;

	pos_stack = 0;
	while(*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
			stack[pos_stack++] = *str;
		else if (*str == ')' || *str == ']' || *str == '}')
		{
			pos_stack--;
			if(!match(*str, stack[pos_stack]))
				return (0);
		}
		str++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int i;

	if (ac > 1)
	{
		i = 1;
		while(av[i])
		{
			if (brackets(av[i]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
