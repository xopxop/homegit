char *ft_strrev(char *str)
{
	int tail;
	int head;
	char temp;
	char *ptr;

	ptr = str;
	head = 0;
	tail = 0;
	while (str[tail] != '\0')
		tail++;
	tail--;
	while (head < tail)
	{
		temp = ptr[head];
		ptr[head++] = ptr[tail];
		ptr[tail--] = temp;
	}
	return (str);
}
