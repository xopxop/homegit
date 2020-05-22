/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 08:23:11 by dthan             #+#    #+#             */
/*   Updated: 2020/05/22 17:36:48 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	ft_space_key(t_lst *head)
{
	t_lst *copy;

	copy = head;
	while (head->next)
	{
		if (head->elem.position == true)
		{
			head->elem.selected = (head->elem.selected == false) ? true : false;
			move_right(copy);
			return ;
		}
		else
			head = head->next;
	}
	head->elem.selected = (head->elem.selected == false) ? true : false;
	move_right(copy);
}
