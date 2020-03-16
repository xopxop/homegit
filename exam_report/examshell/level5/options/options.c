#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    int j;
    int stack[32] = {0};

    if (ac == 1)
        write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
    else if (ac >= 2)
    {
        i = 1;
        while (av[i])
        {
            j = 1;
            if (av[i][0] == '-')
            {
                while (av[i][j] && av[i][j] >= 'a' && av[i][j] <= 'z')
                {
                    if (av[i][j] == 'h')
                    {
                        write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
                        return (0);
                    }
                    stack['z' - av[i][j] + 6] = 1;
                    j++;
                }
            }
            i++;
        }
    }
    return (0);
}