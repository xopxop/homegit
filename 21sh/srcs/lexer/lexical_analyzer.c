/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 09:14:40 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 09:14:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_type	ft_get_type(char *input)
{
	if (!ft_strcmp(input, "|"))
		return (T_PIPE);
	return (T_WORD);
}

static void ft_lstpush_token(t_token *node, t_token **head)
{
	t_token *p;

	if (*head == NULL)
		*head = node;
	else
	{
		p = *head;
		while (p->next)
			p = p->next;
		p->next = node;
	}
}

static t_token *ft_get_token(char *token, int pos)
{
	t_token *node;

	node = (t_token*)malloc(sizeof(t_token));
	node->data = token;
	node->pos_args = pos;
	node->type = ft_get_type(token);
	node->next = NULL;
	return (node);
}

static t_cmd 	*ft_get_cmd(char *input, t_cmd *node)
{
	char	**split;
	int		i;

	i = -1;
	split = (ft_input_contain_dquote(input)) ? \
		ft_strsplit_args(input) : ft_strsplit(input, ' ');
	node = (t_cmd*)malloc(sizeof(t_cmd)); //memerr
	node->argv = (char**)malloc(sizeof(char*) * \
		(ft_arrayct(split) + 1));
	while (split[++i])
	{
		node->argv[i] = (char*)ft_memalloc(sizeof(char) * \
			sysconf(_SC_ARG_MAX));
		ft_strcpy(node->argv[i], split[i]);
		ft_lstpush_token(ft_get_token(node->argv[i], i), &node->token);
	}
	node->argv[i] = NULL;
	node->next = NULL;
	ft_arraydel(split);
	return (node);
}

static void		ft_delete_dquote(t_cmd *cmd)
{
	int i;
	int j;

	while (cmd)
	{
		i = -1;
		while (cmd->argv[++i])
			if (ft_input_contain_dquote(cmd->argv[i]))
			{
				j = -1;
				while (cmd->argv[i][++j])
					if (cmd->argv[i][j] == '"')
					{
						ft_strcpy(&cmd->argv[i][j], &cmd->argv[i][j + 1]);
						j = -1;
					}
			}
		cmd = cmd->next;
	}
}

static void		ft_push_t_cmd_node(t_cmd **head, t_cmd *node)
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

t_cmd			*lexer(char *input, t_cmd *cmds)
{
	t_cmd	*node;
	char	**split;
	int		i;

	i = -1;
	split = (ft_input_contain_dquote(input)) ? \
		ft_strsplit_cmds(input) : ft_strsplit(input, ';');
	while (split[++i])
	{
		node = ft_get_cmd(split[i], node);
		ft_push_t_cmd_node(&cmds, node);
	}
	ft_delete_dquote(cmds);
	ft_arraydel(split);
	return (cmds);
}
