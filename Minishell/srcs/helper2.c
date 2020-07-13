/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:43:26 by dthan             #+#    #+#             */
/*   Updated: 2020/07/13 11:47:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_promt(void)
{
	char *ptr_dir;

	ft_putstr("minishell:");
	ptr_dir = ft_strrchr(ft_call_value_of("PWD"), '/') + 1;
	if (*ptr_dir == '\0')
		ft_putchar('/');
	else if (!ft_strcmp(ft_call_value_of("HOME"), ft_call_value_of("PWD")))
		ft_putchar('~');
	else
		ft_putstr(ptr_dir);
	ft_putchar(' ');
	ft_putstr(ft_call_value_of("USER"));
	ft_putstr("$ ");
}

void	free_cmd_node(t_cmd *node)
{
	int i;

	i = -1;
	while (node->args[++i])
		free(node->args[i]);
	free(node->args);
	free(node);
}

void	ft_push_node(t_cmd **head, t_cmd *node)
{
	t_cmd *ptr;

	if (*head == NULL)
		*head = node;
	else
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = node;
	}
}

t_cmd	*ft_get_arg(char *token_cmd, t_cmd *cmd)
{
	char	**tokens_args;
	int		i;

	i = -1;
	tokens_args = ft_strsplit_args(token_cmd);
	if (tokens_args == NULL)
		return (NULL);
	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_error_handle(MY_ENOMEM, NULL, NULL, NULL);
	if (!(cmd->args = (char**)malloc(sizeof(char*) * \
		(ft_arrayct(tokens_args) + 1))))
		ft_error_handle(MY_ENOMEM, NULL, NULL, NULL);
	while (tokens_args[++i])
	{
		if (!(cmd->args[i] = (char*)ft_memalloc(sizeof(char) * ARG_MAX)))
			ft_error_handle(MY_ENOMEM, NULL, NULL, NULL);
		cmd->args[i] = ft_strcpy(cmd->args[i], tokens_args[i]);
	}
	cmd->args[i] = NULL;
	cmd->next = NULL;
	ft_arraydel(tokens_args);
	return (cmd);
}
