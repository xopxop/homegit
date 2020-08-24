#include <unistd.h>

int ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void printSubString(char *s, int low, int high)
{
	for (int i = low; i <= high; ++i)
		write(STDERR_FILENO, &s[i], 1);
}

void cmp(int *low, int *high, char *s, int *maxLength, int *start)
{
	int len = ft_strlen(s);
	
	while (*low >= 0 && *high < len && s[*low] == s[*high])
	{
		if (*high - *low + 1 > *maxLength)
		{
			*start = *low;
			*maxLength = *high - *low + 1;
		}
		(*low)--;
		(*high)++;
	}
}

void biggest_pal(char *s)
{
	int maxLength = 1;
	int start = 0;
	int len = ft_strlen(s);
	int low, high;
	int i;

	i = -1;
	while (++i < len)
	{
		low = i - 1;
		high = i;
		// even
		cmp(&low, &high, s, &maxLength, &start);
		low = i - 1;
		high = i + 1;
		cmp(&low, &high, s, &maxLength, &start);
	}
	printSubString(s, start, start + maxLength - 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
		biggest_pal(av[1]);
	write(STDOUT_FILENO, "\n", 1);
}