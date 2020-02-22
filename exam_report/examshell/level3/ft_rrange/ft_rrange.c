#include <stdlib.h>

int *ft_rrange(int start, int end)
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
            array[i] = end - i;
        else
            array[i] = end + i;
        i++;
    }
    return (array);
}