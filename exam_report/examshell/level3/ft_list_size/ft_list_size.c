#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int ct;

    ct = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        ct++;
    }
    return (ct);
}