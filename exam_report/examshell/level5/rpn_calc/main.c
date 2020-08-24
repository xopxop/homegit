#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
// stack problem solving way
#define STACK_SIZE 50

void ft_bzero(void *s, size_t n)
{
	int i;
	char *ptr;

	ptr = s;
	i = 0;
	while (i++ < n)
		*(ptr++) = 0;
}

int ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int ft_isnum(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int ft_isoperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int do_op(int *a, int *b, char operand)
{
	if (*a && *b)
	{
		(operand == '+') ? *a += *b : 0;
		(operand == '-') ? *a -= *b : 0;
		(operand == '*') ? *a *= *b : 0;
		(operand == '/') ? *a /= *b : 0;
		(operand == '%') ? *a %= *b : 0;
		*b = 0;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int ft_rpn(char *str, int stack[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isnum(str[i]))
		{
			stack[j++] = atoi(&str[i]);			
			while (str[i] && ft_isnum(str[i]))
				i++;
		}
		else if (ft_isoperand(str[i]))
		{
			if (j < 2 || do_op(&stack[j - 2], &stack[j - 1], str[i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			j--;
			i++;
		}
		else if (!ft_isspace(str[i++]))
			return (EXIT_FAILURE);
	}
	if (stack[0] && stack[1] == 0)
	{
		printf("%d", stack[0]);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int main(int ac, char **av)
{
	int stack[STACK_SIZE];

	if(ac == 2)
	{
		ft_bzero(stack, STACK_SIZE);
		if (ft_rpn(av[1], stack) == EXIT_FAILURE)
			printf("Error");
	}
	else
		printf("Error");
	printf("\n");
}