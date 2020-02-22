#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *array;
    int range;
    int i;

    i = 0;
    if (end >= start)
        range = end - start + 1;
    else
        range = start - end + 1;
    if (!(array = (int*)malloc(sizeof(int) * range)))
        return (NULL);
    while (i < range)
    {
        if (start <= end)
            array[i] = start + i;
        else
            array[i] = start - i;
        i++;
    }
    return (array);
}