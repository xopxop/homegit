#include <unistd.h>

int ft_atoi(char *str)
{
    int nbr;
    int sign;

    
    nbr = 0;
    while((*str == ' ' || *str == '\t') && *str != '\0')
        str++;
    sign = (*str == '-') ? -1 : 1;
    if (*str == '-' || *str == '+')
        str++;
    while(*str <= '9' && *str >= '0')
        nbr = nbr * 10 + (*str++ - '0');
    return (nbr * sign);
}

void ft_putchar(int c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    if (nb < 0)
    {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb < 10)
        ft_putchar(nb + '0');
    else
    {
        ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + '0');
    }
}

int main(int ac, char **av)
{
    int nb;
    int i;
    int result;

    if (ac == 2)
    {
        nb = ft_atoi(av[1]);
        if (nb >= 0)
        {
            i = 1;
            while (i <= 9)
            {
                ft_putnbr(i);
                write(1, " x ", 3);
                ft_putnbr(nb);
                write(1, " = ", 3);
                result = i * nb;
                ft_putnbr(result);
                write(1, "\n", 1);
                i++;
            }
        }
        else
            write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return (0);
}