int ft_strlen(char *str)
{
    int ct;

    ct = 0;
    while (*str++)
        ct++;
    return (ct);
}