#include "includes/ft_ls.h"
#include <stdio.h>

int main(void)
{
    struct dirent *entry;
    struct stat filestat;

    
    printf("stat return: %d\n", lstat("Makefile1", &filestat));
    return (0);
}