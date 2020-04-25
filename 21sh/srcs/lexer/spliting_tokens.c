/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliting_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 08:37:27 by dthan             #+#    #+#             */
/*   Updated: 2020/04/09 08:37:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


static void	ft_jump_dquote(char *str, int *i, int *inside_dquote)
{
	while (str[*i] != '"')
		(*i)++;
	(*i)++;
	*inside_dquote = 0;
}

static void	ft_jump_token(char *str, int *i)
{
	int inside_dquote;

	inside_dquote = 0;
	while (str[*i] && !ft_isspace(str[*i]))
	{
		if (str[*i] == '"')
		{
			inside_dquote = 1;
			(*i)++;
			ft_jump_dquote(str, i, &inside_dquote);
		}
		else
			(*i)++;
	}
}

static int	ft_get_nb_of_tokens(char *input)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (input[i])
	{
		if (!ft_isspace(input[i]))
		{
			size++;
			ft_jump_token(input, &i);
		}
		else
			i++;
	}
	return (size);
}

static char	*ft_get_single_token(char *input, int *tail)
{
	char	*str;
	int		head;

	head = *tail;
	while (input[(*tail)] && !ft_isspace(input[*tail]))
	{
		if (input[*tail] == '"')
		{
			while (input[++(*tail)])
				if (input[*tail] == '"')
					break ;
		}
		(*tail)++;
	}
	if (*tail <= head)
		return (NULL);
	str = ft_strndup(&input[head], *tail - head);
	while (input[(*tail)] && ft_isspace(input[*tail]))
		(*tail)++;
	return (str);
}

static void		ft_delete_dquote(char **tokens)
{
	int i;
	int j;

	i = -1;
	while (tokens[++i])
	{
		j = -1;
		while (tokens[i][++j])
			if (tokens[i][j] == '"')
			{
				ft_strcpy(&tokens[i][j], &tokens[i][j + 1]);
				j = -1;
			}
	}
}

static char	**ft_split_input(char *input)
{
	char	**tokens;
	int		size;
	int		i;
	int		pos_input;

	i = -1;
	pos_input = 0;
	size = ft_get_nb_of_tokens(input);
	tokens = (char**)malloc(sizeof(char*) * (size + 1)); //error mem
	while (++i < size)
		tokens[i] = ft_get_single_token(input, &pos_input);
	tokens[i] = NULL;
	ft_delete_dquote(tokens);
	return (tokens);
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

static t_type	ft_get_type(char *input)
{
	if (!ft_strcmp(input, "|"))
		return (T_PIPE);
	if (!ft_strcmp(input, ";"))
		return (T_SEMI);
	return (T_WORD);
}

static t_token *ft_get_token(char *input)
{
	t_token *node;

	node = (t_token*)malloc(sizeof(t_token));
	node->data = input;
	node->type = ft_get_type(input);
	node->next = NULL;
	return (node);
}

t_token	*lexer(char *input)
{
	char	**tokens;
	t_token	*lst_tokens;
	t_token *node;
	int		i;

	i = -1;
	lst_tokens = NULL;
	tokens = ft_split_input(input);
	while (tokens[++i])
	{
		node = ft_get_token(tokens[i]);
		ft_lstpush_token(node, &lst_tokens);
	}
	return (lst_tokens);
}
