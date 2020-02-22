#include <unistd.h>

void ft_putchar(int chr)
{
    write(1, &chr, 1);
}

void ft_putnbr(int nbr)
{
    if (nbr < 10)
        ft_putchar(nbr + '0');
    else
    {
        ft_putnbr(nbr / 10);
        ft_putchar(nbr % 10 + '0');
    }
}

int main(int ac, char **av)
{
    int ct;
    char **ptr;

    ct = 0;
    if (ac > 2)
    {
        ct = -1;
        ptr = av;
        while(*ptr++)
            ct++;;
    }
    ft_putnbr(ct);
    write(1, "\n", 1);
    return (0);
}