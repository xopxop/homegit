/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 08:20:46 by dthan             #+#    #+#             */
/*   Updated: 2020/07/15 16:01:06 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	move_right(t_lst *head)
{
	t_lst *curr;

	curr = head;
	while (curr->next)
	{
		if (curr->elem.position == true)
		{
			curr->elem.position = false;
			curr->next->elem.position = true;
			return ;
		}
		curr = curr->next;
	}
	curr->elem.position = false;
	head->elem.position = true;
}

void	move_left(t_lst *last)
{
	t_lst *curr;

	curr = last;
	while (curr->previous)
	{
		if (curr->elem.position == true)
		{
			curr->elem.position = false;
			curr->previous->elem.position = true;
			return ;
		}
		curr = curr->previous;
	}
	curr->elem.position = false;
	last->elem.position = true;
}

void	move_down(t_lst *head)
{
	t_lst			*curr_position;
	int				able_to_move_down;
	int				cols;
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	cols = w.ws_col / (ft_finding_longest_elem(head) + 1);
	able_to_move_down = -1;
	while (head->next)
	{
		if (head->elem.position == true)
		{
			curr_position = head;
			while (++able_to_move_down < cols && head->next)
				head = head->next;
			if ((able_to_move_down == cols) == true)
			{
				curr_position->elem.position = false;
				head->elem.position = true;
			}
			return ;
		}
		else
			head = head->next;
	}
}

void	move_up(t_lst *last, t_lst *head)
{
	t_lst			*curr_position;
	int				able_to_move_up;
	int				cols;
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	cols = w.ws_col / (ft_finding_longest_elem(head) + 1);
	able_to_move_up = -1;
	while (last->previous)
	{
		if (last->elem.position == true)
		{
			curr_position = last;
			while (++able_to_move_up < cols && last->previous)
				last = last->previous;
			if ((able_to_move_up == cols) == true)
			{
				curr_position->elem.position = false;
				last->elem.position = true;
			}
			return ;
		}
		else
			last = last->previous;
	}
}

void	ft_move(char *buf)
{
	if (UPWARDS_ARROW(buf))
		move_up(g_select.last, g_select.head);
	else if (DOWNWARDS_ARROW(buf))
		move_down(g_select.head);
	else if (RIGHTWARDS_ARROW(buf))
		move_right(g_select.head);
	else if (LEFTWARDS_ARROW(buf))
		move_left(g_select.last);
}
