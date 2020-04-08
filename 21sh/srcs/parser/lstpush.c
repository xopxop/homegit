/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstpush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:52:27 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 14:52:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lstpush_cm_suffix(t_cmd_suffix *node, t_cmd_suffix **lst)
{
	t_cmd_suffix *p;

	p = *lst;
	while (p)
		p = p->next;
	p = node;
}

void	ft_lstpush_simple_cmd(t_simple_cmd *node, t_simple_cmd **lst)
{
	t_simple_cmd *p;

	p = *lst;
	while (p)
		p = p->next;
	p = node;
}
