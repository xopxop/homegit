#include <unistd.h>

int main(int ac, char **av)
{
    char *ptr;
    if (ac > 1)
    {
        *av++;
        while (*av)
        {
            ptr = *av;
            while(*ptr)
            {
                if (*(ptr + 1) == ' ' || *(ptr + 1) == '\t' || *(ptr + 1) == '\0')
                {
                    if(*ptr >= 'a' && *ptr <= 'z')
                        *ptr -= 32;
                }
                else if(*ptr >= 'A' && *ptr <= 'Z')
                   *ptr += 32;
                write(1, &*ptr, 1);
                *ptr++;
            }
            write(1, "\n", 1);
            *av++;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}