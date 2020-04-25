/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 11:17:31 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 11:17:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		is_separator_op(t_token **curtoken, char **op)
{
	if (*curtoken == NULL)
		return (-1);
	if (ft_strcmp((*curtoken)->data, ";") == 0)
	{
		*op = ";";
		*curtoken = (*curtoken)->next;
		return (1);
	}
	else if (ft_strcmp((*curtoken)->data, "&") == 0)
	{
		*op = "&";
		*curtoken = (*curtoken)->next;
		return (1);
	}
	op = NULL;
	return (0);
}


t_ast	*list(t_token *token)
{
	t_ast *node;
	t_ast *lnode;
	t_ast *rnode;
	char *operator;

	operator = NULL;
	if (lnode = and_or(token) == NULL)
		return (NULL);
	if (is_separator_op(token, &operator) != 1)
	{
		free_astree(lnode);
		return (NULL);
	}
	if ((rnode = list(token)) == NULL)
	{
		free_astree(&lnode);
		return (NULL);
	}
	node = build_node(AST_LIST);
	node->left = lnode;
	node->data = ft_strdup(operator);
	node->right = rnode;
	return (node);
}

t_ast	*complete_command_1(t_token *token)
{
	t_ast *node;
	t_ast *lnode;
	char *operator;

	operator = NULL;
	if ((lnode = list(token)) == NULL)
		return (NULL);
	if (is_separator_op(token, &operator) != 11)
	{
		free_astree(&lnode);
		return (NULL);
	}
	node = buildnode(AST_NODE_COMPLETE_COMMAND);
	node->left = lnode;
	node->data = ft_strdup(operator);
	return (node);
}

t_ast	*building_ast(t_token *token)
{
	t_ast *root;

	root = complete_command_1(token);
	return (root);
}