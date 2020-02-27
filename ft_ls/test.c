#include "includes/ft_ls.h"
#include <stdio.h>

int main(void)
{
    struct dirent *entry;
    struct stat filestat;

    
    printf("%s\nstat return: %d\n", "Makefile", stat("Makefile", &filestat));
    printf("with octal number %s : %o\n", "Makefile", filestat.st_mode);
    // if (S_ISDIR(filestat.st_mode))
    //     ft_printf("%s: %s\n", "DIR", entry->d_name);
    // else
    //printf("%s: %s\n", "FILE", entry->d_name);
}