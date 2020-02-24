#include <stdlib.h>
#include <unistd.h>

// Logic: reverser string then reverse each word the string

void word_rev(char *str, int begin, int end)
{
	char temp;

	while(begin < end)
	{
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
}

void str_rev(char *str)
{
	int head;
	int tail;
	char temp;
	
	head = 0;
	tail = 0;
	while (str[tail] != '\0')
		tail++;
	tail--;
	while(head < tail)
	{
		temp = str[head];
		str[head] = str[tail];
		str[tail] = temp;
		head++;
		tail--;
	}
}

int main(int ac, char **av)
{
	int pos1;
	int pos2;
	int temp_pos1;

	if (ac == 2)
	{
		str_rev(av[1]);
		pos1 = 0;
		while(av[1][pos1] != '\0')
		{
			if(av[1][pos1] != ' ' && av[1][pos1] != '\t')
			{
				pos2 = pos1;
				while(av[1][pos1] != ' ' && av[1][pos1] != '\t' && av[1][pos1] != '\0')
					pos1++;
				word_rev(av[1], pos2, pos1 - 1);
			}
			else
				pos1++;
		}
		while(*av[1])
			write(1, &*av[1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
