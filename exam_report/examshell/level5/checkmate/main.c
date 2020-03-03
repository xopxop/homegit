#include "checkmate.h"

// LOGIC: First take the argiment , check the number of the argument which is equal to all the number of dot in every argument
// Check the argument to take the infomation of the pieces, type of piece
// Last file in board

int isvalid(char **inputs)
{
    int row;
    int col;

    row = 0;
    while (*inputs)
    {
        row = 0;
        while (**inputs)
        {

        }
        *inputs++;
        row++
    }
    return (1);
}

int main (int ac, char **av)
{
    if (ac >= 2)
    {
        if (isvalid(av))
            checkmate();
        else
            write(1, "\n", 1);
    }
    else if (ac < 2)
        write(1, "\n", 1);
    return (0);
}