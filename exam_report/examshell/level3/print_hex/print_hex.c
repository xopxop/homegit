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

void print_hex(int nb)
{
    int i;
    char place_holder[17] = "0123456789abcdef";

    if (nb >= 16)
        print_hex(nb / 16);
    i = nb % 16;
    write(1, &place_holder[i], 1);
}

int main(int ac, char **av)
{
    int nb;
    char *hex_str;
    char chr;
    int mask;

    if (ac = 2)
    {
        mask = -268435456;
        hex_str = "0123456789abcdef";
        nb = ft_atoi(av[1]);
        if (nb >= 0)
            print_hex(nb);
    }
    write(1, "\n", 1);
    return (0);
}