#include <unistd.h>

int main(int argc, char **argv)
{
    write(1, "z\n", 2);
    return (0);
}