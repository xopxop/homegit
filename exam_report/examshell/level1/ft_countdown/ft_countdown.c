#include <unistd.h>

int main()
{
    write(1, "9876543210\n", 11);
    return (0);
}