#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned b);

int main()
{
    printf("%d\n", lcm(12, 16));
    printf("%d\n", lcm(16, 12));
    printf("%d\n", lcm(8, 16));
    printf("%d\n", lcm(16, 8));
    printf("%d\n", lcm(0, 1));
    printf("%d\n", lcm(1, 0));
    return (0);
}