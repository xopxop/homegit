#include <unistd.h>

int main(int argc, char **argv)
{
    int pos1;
    int pos2;
    int pos3;
    int check_word;

    pos1 = 0;
    if (argc == 2)
    {
        while (argv[1][pos1] != '\0')
        {
            if (argv[1][pos1] != ' ' && argv[1][pos1] != '\t')
            {
                pos2 = pos1;
                while (argv[1][pos2] != ' ' && argv[1][pos2] != '\t' && argv[1][pos2] != '\0')
                    pos2++;
                pos3 = pos2;
                check_word = 0;
                while(argv[1][pos3] != '\0')
                {
                    if (argv[1][pos3] != ' ' && argv[1][pos3] != '\t')
                    {
                        check_word = 1;
                        break ;
                    }
                    pos3++;
                }
                if (check_word)
                    while (pos1 <= pos2)
                        write(1, &argv[1][pos1++], 1);
                else
                    while (pos1 <= pos2 - 1)
                        write(1, &argv[1][pos1++], 1);
            }
            else
                pos1++;
        }
    }
    write(1, "\n", 1);
    return (0);
}