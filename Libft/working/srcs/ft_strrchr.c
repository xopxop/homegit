char	*ft_strrchr(const char *s, int c)
{
	char *last_c;

	last_c = (0);
	while (*s)
	{
		if (*s == c)
			last_c = (char*)s;
		s++;
	}
	if (last_c)
		return (last_c);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
