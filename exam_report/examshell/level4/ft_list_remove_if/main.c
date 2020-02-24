#include <stdio.h>
#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

int cmp(void *data, void *data_ref)
{
    if(((int*)data == (int*)data_ref))
        return (0);
    return (1);
}

int main()
{
	t_list *ptr;
    t_list *lst;
	int i = 1;
	int j = 2;
	int z = 3;
	int ct = 0;

	lst = malloc(sizeof(t_list));
	lst->data = &j;
	lst->next = malloc(sizeof(t_list));
	lst->next->data = &j;
	lst->next->next = malloc(sizeof(t_list));
	lst->next->next->data = &i;
	lst->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->data = &i;
	lst->next->next->next->next = malloc(sizeof(t_list));
	lst->next->next->next->next->data = &z;
	lst->next->next->next->next->next= NULL;

	printf("--Before deleting node--\n");
	ptr = lst;
	while (ptr)
	{
		printf("Value of node %d is %d\n", ct,*(int*)ptr->data);
		ptr = ptr->next;
		ct++;
	}
	ft_list_remove_if(&lst, &j, cmp);

	ct = 0;
	ptr = lst;
	printf("--After deleting node--\n");
	while (ptr)
	{
		printf("Value of node %d is %d\n", ct,*(int*)ptr->data);
		ptr = ptr->next;
		ct++;
	}
	return (0);
}