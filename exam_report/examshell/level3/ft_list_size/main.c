#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

int ft_list_size(t_list *begin_list);

int main()
{
    t_list *list1;
    t_list *list2;
    t_list *list3;
    t_list *list4;
    t_list *list5;
    t_list *list6;

    list1 = (t_list*)malloc(sizeof(t_list));
    list2 = (t_list*)malloc(sizeof(t_list));
    list3 = (t_list*)malloc(sizeof(t_list));
    list4 = (t_list*)malloc(sizeof(t_list));
    list5 = (t_list*)malloc(sizeof(t_list));
    list6 = (t_list*)malloc(sizeof(t_list));

    list1->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = list5;
    list5->next = list6;
    list6->next = NULL;

    printf("Size of linked list: %d\n", ft_list_size(list1));
    return (0);
}