#include <stdio.h>

int max(int *tab, unsigned int len);

int main()
{
	int test1[0];
	int test2[1] = {-20};
	int test3[19] = {6,-9,-4,-6,12,-14,-12,0,2,-19,1,6,16,-10,9,11,4,-11,7};
	int test4[17] = {1,-14,-2,-20,-5,5,1,20,-10,-8,18,11,-20,-9,10,-16,-5};
	int test5[20] = {13,4,13,-12,-10,5,-1,6,17,-14,-17,15,12,-2,-1,4,-15,9,3,16};
	int test6[29]= {0,-12,3,-9,10,9,7,-1,7,-15,16,17,-9,14,4,-18,-9,-5,-7,-6,-1,-20,-12,14,-19,17,16,-16,9};

	printf("%d\n", max(test1, 0));
	printf("%d\n", max(test2, 1));
	printf("%d\n", max(test3, 19));
	printf("%d\n", max(test4, 17));
	printf("%d\n", max(test5, 20));
	printf("%d\n", max(test6, 29));
	return (0);
}
