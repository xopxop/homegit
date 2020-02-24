#include <stdio.h>

char **ft_split(char *str);

int main()
{
    char *str = "  This \t \t string has to be cut    into small      string \t  ";
    char **array;

    array = ft_split(str);
    while (*array)
    {
        printf("%s\n", *array);
        *array++;
    }
    return (0)
;}