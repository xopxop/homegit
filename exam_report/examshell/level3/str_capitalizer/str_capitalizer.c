#include <unistd.h>

int main(int ac, char **av)
{
    char *ptr_str;

    if (ac > 1)
    {
        *av++;
        while(*av)
        {
            ptr_str = *av;
            while (*ptr_str)
            {
                if(*(ptr_str - 1) == ' ' || *(ptr_str - 1) == '\t' || *(ptr_str - 1) == '\0')
                {
                    if (*ptr_str >= 'a' && *ptr_str <= 'z')
                        *ptr_str -= 32;
                }
                else if (*ptr_str >= 'A' && *ptr_str <= 'Z')
                    *ptr_str += 32;
                write (1, &*ptr_str, 1);
                *ptr_str++;
            }
            write(1, "\n", 1);
            *av++;
        }
    }
    else
        write (1, "\n", 1);
    return (0);
}