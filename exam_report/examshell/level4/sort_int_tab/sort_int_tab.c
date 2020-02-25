void sort_int_tab(int *tab, unsigned int size)
{
	int sorted;
	int pos;
	int temp;

	sorted = 0;
	while(sorted == 0)
	{
		sorted = 1;
		pos = 1;
		while(pos <= size - 1)
		{
			if (tab[pos - 1] > tab[pos])
			{
				temp = tab[pos - 1];
				tab[pos - 1] = tab[pos];
				tab[pos] = temp;
				sorted = 0;
			}
			pos++;
		}
	}
}
