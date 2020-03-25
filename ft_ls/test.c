#include "includes/ft_ls.h"
#include <stdio.h>

void ft_err_can_not_read_link();

char *ft_get_path_sym_link(char *pathname)
{
    char buf[50];
    ssize_t len;

    len = readlink(pathname, buf, sizeof(buf) - 1);
    if (len != -1)
    {
        buf[len] = '\0';
        return (buf);
    }
    ft_err_can_not_read_link();
    return (NULL);
}

int main(void)
{
    char *symlink;

    symlink = ft_get_path_sym_link("test/42");

    printf("%s -> %s", "42", symlink);
    return (0);
}