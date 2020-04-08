/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliting_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:14:09 by dthan             #+#    #+#             */
/*   Updated: 2020/04/06 00:14:10 by dthan            ###   ########.fr       */
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

static void	ft_jump_arg(char *str, int *i)
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

static int	ft_get_nb_of_args(char *input)
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
			ft_jump_arg(input, &i);
		}
		else
			i++;
	}
	return (size);
}

static char	*ft_get_single_arg(char *input, int *tail)
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

char	**ft_strsplit_args(char *input)
{
	char	**tokens;
	int		size;
	int		i;
	int		pos_input;

	i = -1;
	pos_input = 0;
	size = ft_get_nb_of_args(input);
	if (!(tokens = (char**)malloc(sizeof(char*) * (size + 1))))
		ft_error_handle(MY_ENOMEM, NULL, NULL, NULL);
	while (++i < size)
		tokens[i] = ft_get_single_arg(input, &pos_input);
	tokens[i] = NULL;
	return (tokens);
}
