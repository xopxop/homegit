#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

int main()
{
	int pos = 0;
	int tab1[] = {1,2,3,4,5,6,7,8,9};
	int tab2[] = {9,8,7,6,5,4,3,2,1};
	int tab3[] = {4,21,54,65,23,2,1,0,-32};

	sort_int_tab(tab1, 9);
	printf("Tab 1:\n");
	while(pos <= 8)
	{
		printf("{%d}", tab1[pos]);
		pos++;
	}

	sort_int_tab(tab2, 9);
	pos = 0;
	printf("\nTab 2:\n");
	while(pos <= 8)
	{
		printf("{%d}", tab2[pos]);
		pos++;
	}

	sort_int_tab(tab3, 9);
	pos = 0;
	printf("\nTab 3:\n");
	while(pos <= 8)
	{
		printf("{%d}", tab3[pos]);
		pos++;
	}
	pos = 0;
	return (0);
}
