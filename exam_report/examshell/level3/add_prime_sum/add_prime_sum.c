#include <unistd.h>

int check_num(char *str)
{
    while (*str)
    {
        if (*str < 48 && *str > 57)
            return (0);
        str++;
    }
    return (1);
}

int basic_atoi(char *str)
{
    int nbr;

    nbr = 0;
    while(*str)
        nbr = nbr * 10 + *str++ - '0';
    return (nbr);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
    char chr;
    if (nbr < 9)
        ft_putchar(nbr + '0');
    else
    {
        ft_putnbr(nbr / 10);
        ft_putchar(nbr % 10 + '0');
    }
}

int main(int argc, char **argv)
{
    char *ptr;
    int nbr;
    int temp;
    int sum;
    int ct;
    int loop;

    if (argc == 2)
    {
        ptr = argv[1];
        if (!check_num(argv[1]) || *ptr == '-' || *ptr == '0')
            write(1, "0", 1);
        else
        {
            nbr = basic_atoi(argv[1]);
            sum = 0;
            temp = 2;
            if (nbr == 1)
                sum = 1;
            while (temp <= nbr)
            {
                loop = 1;
                ct = 0;
                while(loop <= temp)
                {
                    if (temp % loop == 0)
                        ct++;
                    loop++;
                }
                if (ct == 2)
                    sum += temp;
                temp++;
            }
            ft_putnbr(sum);
        }
    }
    else
        write(1, "0", 1);
    write (1, "\n", 1);
    return (0);
}