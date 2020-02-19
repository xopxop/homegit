#include <unistd.h>

int main(int argc, char **argv)
{
    int temp;

    if (argc == 2)
    {
        while (*argv[1])
        {
            if((*argv[1] > 'm' && *argv[1] <= 'z') || (*argv[1] > 'M' && *argv[1] <= 'Z'))
            {
                temp = *argv[1] - 13;
                write (1, &temp, 1);
            }
            else if ((*argv[1] >= 'a' && *argv[1] <= 'm') || (*argv[1] >= 'A' && *argv[1] <= 'M'))
            {
                temp = *argv[1] + 13;
                write (1, &temp, 1);
            }
            else
                write (1, &*argv[1], 1);
            *argv[1]++;
        }
    }
    write (1, "\n", 1);
    return (0);
}