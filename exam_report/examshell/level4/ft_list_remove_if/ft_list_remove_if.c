#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *lst;
    t_list *temp;
    int i;
    
    i = 0;
    if (begin_list == NULL || *begin_list == NULL)
        return ;
    temp = *begin_list;
    while ((*cmp)((*begin_list)->data, data_ref) == 0)
    {
        temp = (*begin_list)->next;
        free(*begin_list);
        (*begin_list) = temp;
    }
    temp = *begin_list;
    lst = *begin_list;
    while (lst)
    {
        if ((*cmp)(lst->data, data_ref) == 0)
        {
            temp->next = lst->next;
            free(lst);
            lst = temp;
            i = 0;
        }
        if (i > 0)
            temp = temp->next;
        if (lst)
            lst = lst->next;
        i++;
    }
}

/*
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp;
    t_list *head_list;

    if (begin_list == NULL, *begin_list == NULL)
        return ;
    while ((cmp)((*begin_list)->data, data_ref) == 0 && *begin_list != NULL)
    {
        temp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(temp);
    }
    head_list = *begin_list;
    while (head_list)
    {
        if (head_list->next != NULL)
        {
            temp = head_list->next;
            if ((cmp)(temp->data, data_ref) == 0)
            {
                head_list->next = head_list->next->next;
                free(temp);
            }
            else
                head_list = head_list->next;
        }
        else
            head_list = head_list->next;
    }
}
*/