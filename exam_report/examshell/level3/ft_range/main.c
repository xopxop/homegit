#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end);

int main()
{
    int *array;
    int *array2;
    int *array3;
    int *array4;
    int begin;

    // Test 1
    begin = 0;
    array = ft_range(1, 3);
    while (begin < 3)
    {
        printf("{%d}", array[begin]);
        begin++;
    }
    printf("\n");
    // Test 2
    begin = 0;
    array2 = ft_range(-1, 2);
    while (begin < 4)
    {
        printf("{%d}", array2[begin]);
        begin++;
    }
    printf("\n");
    // Test 3
    begin = 0;
    array3 = ft_range(0, 0);
    while (begin < 1)
    {
        printf("{%d}", array3[begin]);
        begin++;
    }
    printf("\n");
    // Test 4
    begin = 0;
    array4 = ft_range(0, -3);
    while (begin < 4)
    {
        printf("{%d}", array4[begin]);
        begin++;
    }
    printf("\n");
    return (0);
}