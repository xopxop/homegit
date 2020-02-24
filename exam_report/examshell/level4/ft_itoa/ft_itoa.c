#include <stdlib.h>

char *ft_minint(int nbr)
{
    char *str;
    int i;

    if (!(str = (char*)malloc(sizeof(char) * 11 + 1)))
        return (NULL);
    str[0] = '-';
    nbr = (nbr + 1) * -1;
    i = 9;
    str[10] = '8';
    nbr /= 10;
    while (i >= 1)
    {
        str[i--] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (str);
}

char *ft_itoa(int nbr)
{
    char *str;
    int str_size;
    int negative;
    int temp;

    negative = 0;
    if (nbr == -2147483648)
        return(ft_minint(nbr));
    if (nbr < 0)
    {
        negative = 1;
        nbr *= -1;
    }
    str_size = negative;
    if (nbr == 0)
        str_size = 1;
    temp = nbr;
    while (temp)
    {
        temp /= 10;
        str_size++;
    }
    if (!(str = (char*)malloc(sizeof(char) * str_size + 1)))
        return (NULL);
    while(str_size > negative)
    {
        str[str_size - 1] = nbr % 10 + '0';
        nbr /= 10;
        str_size--;
    }
    if (negative)
        str[0] = '-';
    return (str);
}