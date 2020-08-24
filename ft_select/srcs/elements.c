/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 08:24:40 by dthan             #+#    #+#             */
/*   Updated: 2020/07/15 23:45:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		ft_finding_longest_elem(t_lst *lst)
{
	int maxsize;

	maxsize = 0;
	while (lst)
	{
		if (maxsize < lst->elem.max_length)
			maxsize = lst->elem.max_length;
		lst = lst->next;
	}
	return (maxsize);
}

int		count_selected_elem(t_lst *head)
{
	int ct;

	ct = 0;
	while (head)
	{
		if (head->elem.selected == true)
			ct++;
		head = head->next;
	}
	return (ct);
}

int		ft_count_elems(t_lst *lst)
{
	int ct;

	ct = 0;
	while (lst)
	{
		lst = lst->next;
		ct++;
	}
	return (ct);
}

void	ft_remove_elem(t_lst **head)
{
	t_lst *q;
	t_lst *p;

	q = *head;
	p = (*head)->next;
	if (q->elem.position == true)
	{
		move_right(*head);
		*head = p;
		if (*head != NULL)
			(*head)->previous = NULL;
		free(q);
	}
	else
	{
		while (p->elem.position != true)
		{
			p = p->next;
			q = q->next;
		}
		if (p->next == NULL)
		{
			move_left(p);
			q->next = NULL;
			free(p);
		}
		else
		{
			move_right(*head);
			q->next = p->next;
			p->next->previous = q;
			free(p);
		}
	}
}

t_lst	*ft_creat_elem(char *input)
{
	t_lst *node;

	node = (t_lst*)malloc(sizeof(t_lst));
	node->elem.av = input;
	node->elem.max_length = ft_strlen(input);
	node->elem.selected = false;
	node->elem.position = false;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	free_elems(t_lst **head, t_lst **last)
{
	t_lst *ptr;

	*last = NULL;
	while (*head)
	{
		ptr = *head;
		*head = (*head)->next;
		free(ptr);
	}
}
