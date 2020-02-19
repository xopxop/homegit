#include <unistd.h>

int main(int argc, char **argv)
{
    int loop;
    int repeation;

    if (argc == 2)
    {
        while (*argv[1])
        {
            repeation = 0;
            if (*argv[1] >= 'a' && *argv[1] <= 'z')
            {
                loop = *argv[1] - 'a' + 1;
                while (repeation++ < loop)
                    write(1, &*argv[1], 1);
            }
            else if (*argv[1] >= 'A' && *argv[1] <= 'Z')
            {
                loop = *argv[1] - 'A' + 1;
                while (repeation++ < loop)
                    write(1, &*argv[1], 1);
            }
            else
                write(1, &*argv[1], 1);
            *argv[1]++;
        }
    }
    write (1, "\n", 1);
    return (0);
}