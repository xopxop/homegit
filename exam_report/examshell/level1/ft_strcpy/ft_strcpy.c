char *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (*s2)
        *s1++ = *s2++;
    *s1 = '\0';
    return (s1);
}