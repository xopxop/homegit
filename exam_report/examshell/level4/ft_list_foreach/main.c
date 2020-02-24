#include <stdio.h>
#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>

void ft_list_foreach(t_list *begin_list, void (*f)(void *));

void	print_data(void *data)
{
	printf("%s\n", (char*)data);
}

int main()
{
    t_list *list1;
    t_list *list2;
    t_list *list3;
    t_list *list4;
    t_list *list5;
    t_list *list6;
    void (*f)(void*);
    f = print_data;

    list1 = (t_list*)malloc(sizeof(t_list));
    list2 = (t_list*)malloc(sizeof(t_list));
    list3 = (t_list*)malloc(sizeof(t_list));
    list4 = (t_list*)malloc(sizeof(t_list));
    list5 = (t_list*)malloc(sizeof(t_list));
    list6 = (t_list*)malloc(sizeof(t_list));
    list1->data = "This is list 1";
    list2->data = "This is list 2";
    list3->data = "This is list 3";
    list4->data = "This is list 4";
    list5->data = "This is list 5";
    list6->data = "This is list 6";
    list1->next = list2;
    list2->next = list3;
    list3->next = list4;
    list4->next = list5;
    list5->next = list6;
    list6->next = NULL;

    ft_list_foreach(list1, f);    
    printf("--------\n");
    ft_list_foreach(list4, f);   
    return (0);
}