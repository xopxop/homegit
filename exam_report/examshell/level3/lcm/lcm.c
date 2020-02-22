unsigned int ft_hcf(unsigned int a, unsigned int b)
{
    if (a == 0)
        return (b);
    return ft_hcf(b % a, a);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int lcm;
    
    lcm = (a * b) / ft_hcf(a, b);
    return (lcm);
}