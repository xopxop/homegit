#include "list.h"

void ft_swap_node(t_list *node, t_list *next_node)
{
	int temp;

	temp = node->data;
	node->data = next_node->data;
	next_node->data = temp;
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	int sorted;
	t_list *current_node;

	sorted = 0;
	while(sorted == 0)
	{
		current_node = lst;
		sorted = 1;
		while(current_node && current_node->next)
		{
			if (!(cmp(current_node->data, current_node->next->data)))
						ft_swap_node(current_node, current_node->next);
			else
				sorted == 0;
			current_node = current_node->next;
		}
	}
	return (lst);
}
