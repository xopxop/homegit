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

void biggest_pal(char *s)
{
	int maxLength = 1;
	int start = 0;
	int len = ft_strlen(s);
	int low, high;

	for (int i = 1; i < len; ++i)
	{
		low = i -1;
		high = i;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			if (high - low + 1 > maxLength)
			{
				start = low;
				maxLength = high - low + 1;
			}
			--low;
			++high;
		}
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			if (high - low + 1 > maxLength)
			{
				start = low;
				maxLength = high - low + 1;
			}
			--low;
			++high;
		}
	}
	printSubString(s, start, start + maxLength - 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
		biggest_pal(av[1]);
	write(STDOUT_FILENO, "\n", 1);
}