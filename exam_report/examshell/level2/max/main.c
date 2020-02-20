#include <stdio.h>

int max(int *tab, unsigned int len);

int main()
{
	int nbrs[] = {1002, 23, 12,6,30, 34, 2394835, 12, 1};
	int null[0] ;

	printf("%d\n", max(nbrs, 3));	
	printf("%d\n", max(nbrs, 7));
	printf("%d\n", max(null, 0));
	return (0);
}
