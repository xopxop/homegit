#include <unistd.h>

int main(int ac, char **av)
{
    char *ptr1;
    char *ptr2;

    if (ac == 3)
    {
        ptr1 = av[1];
        ptr2 = av[2];
        while(*ptr1 && *ptr2)
        {
            while (*ptr2)
            {
                if (*ptr1 == *ptr2)
                {
                    ptr2++;
                    break;
                }
                ptr2++;
            }
            ptr1++;
        }
        if (!*ptr1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write (1, "\n", 1);
    return (0);
}