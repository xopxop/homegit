#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int nb;
    int i;

    if (ac == 2)
    {
        nb = atoi(av[1]);
        if (nb >= 2)
        {
            i = 2;
            while (i <= nb)
            {
                if (nb % i == 0)
                {
                    nb /= i;
                    printf("%d", i);
                    if (i < nb)
                        printf("*");
                }
                else
                    i++;
            }
        }
        else if (nb == 1)
            printf("1");
    }
    printf("\n");
    return (0);
}