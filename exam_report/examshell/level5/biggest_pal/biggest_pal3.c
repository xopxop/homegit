#include <unistd.h>

int ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void biggest_pal(char *s)
{
	int n = ft_strlen(s);
	int i, j, cl;
	int L[n][n];

	for (i = 0; i < n; i++)
		L[i][i] = 1;
	for (cl = 2; cl <= n; cl++)
	{
		for (i = 0; i < n - cl + 1; i++)
		{
			j = i + cl - 1;
			if (s[i] == s[j] && cl == 2)
				L[i][j] = 2;
			else if (s[i] == s[j])
				L[i][j] = L[i + 1][j - 1] + 2;
			else
				L[i][j] = max(L[i][j - 1], L[i + 1][j]);
		}
	}
	return (L[0][n - 1]);
}

int main(int ac, char **av)
{
	if (ac == 2)
		biggest_pal(av[1]);
	write(STDOUT_FILENO, "\n", 1);
}
