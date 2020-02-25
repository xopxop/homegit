#include <unistd.h>
#include <stdlib.h>

// My Logic: count words frist, the size of the new string is equal
// to the size of the total number of the words + (the number of
// the word - 1) + 1 for the null terminator

int word_count(char *str)
{
	int wc;

	wc = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
		{
			wc++;
			while(*str != ' ' && *str != '\t' && *str \
					!= '\0')
				*str++;
		}
		else
			*str++;
	}
	return (wc);
}

int size_new_str(char *str, int wc)
{
	int size;

	size = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			size++;
		*str++;
	}
	size += wc - 1;
	return (size);
}

void ft_copy_str(char *dest, char *src, int wc)
{
	while(*src)
	{
		if (*src != ' ' && *src != '\t')
		{
			while (*src != ' ' && *src != '\t' && \
					*src != '\0')
				*dest++ = *src++;
			if (*src != '\0' && wc > 1)
			{

				*dest++ = ' ';
				wc--;
			}
		}
		else
			*src++;
	}
	*dest = '\0';
}

void ft_switch_first_word(char *str)
{
	int pos1;
	int pos2;
	char *first_word;

	pos1 = 0;
	while(str[pos1] != ' ' && str[pos1] != '\t')
		pos1++;
	if (!(first_word = (char*)malloc(sizeof(char) * pos1 + 1)))
		return ;
	pos1 = 0;
	while (str[pos1] != ' ' && str[pos1] != '\t')
		first_word[pos1++] = str[pos1];
	first_word[pos1] = '\0';
	pos1++;
	pos2 = 0;
	while (str[pos1] != '\0')
		str[pos2++] = str[pos1++];
	str[pos2++] = ' ';
	while (str[pos2] != '\0')
		str[pos2++] = *first_word++;
}

int main(int ac, char **av)
{
	int wc;
	int str_size;
	char *new;
	char *temp;

	if (ac == 2)
	{
		// Count word
		wc = word_count(av[1]);
		// Get length new string without null terminator
		str_size = size_new_str(av[1], wc);
		if (!(new = (char*)malloc(sizeof(char) * str_size\
					       	+ 1)))
			return (0);
		ft_copy_str(new, av[1], wc);
		if (wc > 1)
			ft_switch_first_word(new);
		temp = new;
		while (*temp)
			write(1, &*temp++, 1);
		free(new);
	}
	write(1, "\n", 1);
	return (0);
}
