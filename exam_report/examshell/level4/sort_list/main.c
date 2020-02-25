#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int));

int ascending(int a, int b)
{
	return (a <= b);
}

int main()
{
	t_list *lst;
	t_list *temp;
	int i;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = 1;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = -32;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = -421;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = 100;
	lst->next->next->next->next = NULL;

	temp = lst;
	i = 1;
	while(temp)
	{
		printf("Node %d has value of %d\n", i , temp->data);
		i++;
		temp = temp->next;
	}

	printf("LIST SORTING...\n");
	temp = sort_list(lst, ascending);
	i = 1;
	while(temp)
	{
		printf("Node %d has value of %d\n", i , temp->data);
		i++;
		temp = temp->next;
	}
	return (0);
}
