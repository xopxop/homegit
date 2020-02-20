#include <stdlib.h>

int max(int *tab, unsigned int len)
{
	int maxnb;

	if (!tab)
		return (0);
	maxnb = *tab;
	while (len-- > 0)
	{
		if (*tab > maxnb)
			maxnb = *tab;
		tab++;
	}
	return (maxnb);	
}
