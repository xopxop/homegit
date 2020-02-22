#include <stdio.h>

int ft_atoi_base(const char *str, int str_base);

int main()
{
    printf("%d\n", ft_atoi_base("123", 2));
    printf("%d\n", ft_atoi_base("123", 3));
    printf("%d\n", ft_atoi_base("123", 4));
    printf("%d\n", ft_atoi_base("123", 5));
    printf("%d\n", ft_atoi_base("123", 6));
    printf("%d\n", ft_atoi_base("123", 7));
    printf("%d\n", ft_atoi_base("123", 8));
    printf("%d\n", ft_atoi_base("123", 9));
    printf("%d\n", ft_atoi_base("123", 10));
    printf("%d\n", ft_atoi_base("123", 11));
    printf("%d\n", ft_atoi_base("123", 12));
    printf("%d\n", ft_atoi_base("123", 13));
    printf("%d\n", ft_atoi_base("123", 14));
    printf("%d\n", ft_atoi_base("123", 15));
    printf("%d\n", ft_atoi_base("123", 16));
    printf("%d\n", ft_atoi_base("-123", 16));
    printf("%d\n", ft_atoi_base("       -123", 16));
    printf("%d\n", ft_atoi_base("af", 16));
    printf("%d\n", ft_atoi_base("1pw23", 16));
    return (0);
}