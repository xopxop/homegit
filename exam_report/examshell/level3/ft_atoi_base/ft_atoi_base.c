int valid(char *str, int str_base)
{
    char base_16_1[] = "0123456789abcdef";
    char base_16_2[] = "0123456789ABCDEF";
    int pos;
    int check;

    while (*str)
    {
        pos = 0;
        check = 0;
        while (pos < str_base)
        {
            if (*str == base_16_1[pos] || *str == base_16_2[pos])
                check = 1;
            pos++;
        }
        if (!check)
            return (0);
        str++;
    }
    return (1);
}

int value_of(int c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'f')
        return (c - 87);
    else if (c >= 'A' && c <= 'F')
        return (c - 55);
}

int ft_isblank(int c)
{
    return ((c == ' ' || c == '\t') ? 1 : 0);
}

int ft_atoi_base(const char *str, int str_base)
{
    int pos;
    int base_10;
    int negative;

    base_10 = 0;
    while (ft_isblank(*str))
        str++;
    negative = (*str == '-') ? -1 : 1;
    if (negative == -1)
        *str++;
    if (valid((char*)str, str_base))
        while (*str)
            base_10 = base_10 * str_base + value_of(*str++);
    return (base_10 * negative);
}