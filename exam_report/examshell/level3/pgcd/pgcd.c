#include <stdlib.h>
#include <stdio.h>

int ft_hcd(unsigned int a, unsigned int b)
{
    if (a == 0)
        return (b);
    return (ft_hcd(b % a, a));
}

int main(int ac, char **av)
{
    int array[2];
    int pos_int_array;
    int hcd;

    if (ac == 3)
    {
        pos_int_array = 0;
        *av++;
        while(*av)
        {
            array[pos_int_array++] = atoi(*av);
            *av++;
        }
        if (array[0] >= 0 && array[1] >= 0)
        {
            hcd = ft_hcd(array[0], array[1]);
            printf("%d", hcd);
        }
    }
    printf("\n");
    return (0);
}