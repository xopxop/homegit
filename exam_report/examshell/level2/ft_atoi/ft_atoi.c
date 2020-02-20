int ft_atoi(const char *str)
{
	int nbr;
	int negative_sign;

	nbr = 0;
	negative_sign = 1;
	while (*str && (*str == '\b' || *str == '\t' || *str == '\n' || \
				*str == '\v' || *str == '\f' || *str == '\r' \
				|| *str == ' '))
		*str++;
	if (*str == '-')
		negative_sign = -1;
	if (*str == '-' || *str == '+')
		*str++;
	while (*str)
		nbr = nbr * 10 + (*str++ - '0');
	return (nbr * negative_sign);
}
