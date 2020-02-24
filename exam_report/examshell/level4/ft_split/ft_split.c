#include <stdlib.h>
#include <stdio.h>

void ft_strncpy(char *dest, char *source, int n)
{
    int i;

    i = 0;
    while(source[i] != '\0' && i <= n)
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

int ft_wct(char *str)
{
    int ct;

    ct = 0;
    while (*str)
    {
        if (*str != ' ' && *str != '\t' && *str != '\0')
        {
            ct++;
            while (*str != ' ' && *str != '\t' && *str != '\0')
                *str++;
        }
        else
            *str++;
    }
    return (ct);
}


char **ft_split(char *str)
{
    int i;
    int pos_begin;
    int pos_end;
    char **string_array;
    int j;
    int wc;

    i = 0;
    j = 0;
    wc = ft_wct(str);
    string_array = (char**)malloc(sizeof(char*) * (wc + 1));
    string_array[wc] = '\0';
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
        {
            pos_begin = i;
            while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
                i++;
            pos_end = i - 1;
            string_array[j] = (char*)malloc(sizeof(char) * (pos_end - pos_begin + 2));
            ft_strncpy(string_array[j], str + pos_begin, pos_end - pos_begin);
            j++;
        }
        else
            i++;
    }
    return (string_array);
}