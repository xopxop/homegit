#include <unistd.h>

int main(int argc, char **argv)
{
    int pos;

    pos = 0;
    if (argc == 2)
    {
        while (argv[1][pos])
            pos++;
        pos--;
        while (pos >= 0)
            write(1, &argv[1][pos--], 1);
    }
    write (1, "\n", 1);
    return (0);
}