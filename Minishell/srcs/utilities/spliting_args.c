/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliting_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:14:09 by dthan             #+#    #+#             */
/*   Updated: 2020/07/13 11:47:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** this function will be used to jump if it hit the "
*/

void	ft_jump_dquote(char *str, int *i, int *inside_dquote)
{
	while (str[*i] != '"')
		(*i)++;
	(*i)++;
	*inside_dquote = 0;
}

/*
** this function will be used to jump to the next argument
*/

void	ft_jump_arg(char *str, int *i)
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

int		ft_get_nb_of_args(char *input)
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

char	*ft_get_single_arg(char *input, int *tail)
{
	char	*str;
	int		head;

	head = -1;
	while (input[(*tail)])
	{
		if (!ft_isspace(input[*tail]))
		{
			head = *tail;
			ft_jump_arg(input, tail);
			break ;
		}
		(*tail)++;
	}
	if (head == -1)
		return (NULL);
	str = ft_strndup(&input[head], *tail - head);
	return (str);
}

char	**ft_strsplit_args(char *input)
{
	char	**tokens;
	int		size;
	int		i;
	int		pos_input;
	char	*temp;

	i = -1;
	pos_input = 0;
	size = ft_get_nb_of_args(input);
	if (size == 0)
		return (NULL);
	if (!(tokens = (char**)malloc(sizeof(char*) * (size + 1))))
		ft_error_handle(MY_ENOMEM, NULL, NULL, NULL);
	while (++i < size)
	{
		temp = ft_get_single_arg(input, &pos_input);
		if (temp == NULL)
		{
			i--;
			continue ;
		}
		tokens[i] = temp;
	}
	tokens[i] = NULL;
	return (tokens);
}
