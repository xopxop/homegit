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

// this function will be used to jump if it hit the "

static void	ft_jump_dquote(char *str, int *i, int *inside_dquote)
{
	while (str[*i] != '"')
		(*i)++;
	(*i)++;
	*inside_dquote = 0;
}

// this function will be used to jump to the next argument

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
	char *str;
	int head;

	head = *tail + 1;
	while(input[++(*tail)] && !ft_isspace(input[*tail]))
	{
		if (input[*tail] == '"')
		{
			while(input[++(*tail)])
				if (input[*tail] == '"')
					break ;
		}
	}
	if (*tail <= head)
		return (NULL);
	str = ft_strndup(&input[head], *tail - head);
	*tail = *tail + 1;
	return (str);
}

static char	**ft_strsplit_args(char *input)
{
	char **tokens;
	int size;
	int i;
	int pos_input;

	i = -1;
	pos_input = -1;
	size = ft_get_nb_of_args(input);
	tokens = (char**)malloc(sizeof(char*) * (size + 1)); //need to add ERR
	while (++i < size)
		tokens[i] = ft_get_single_arg(input, &pos_input); // for sure the str never return NULL because the function was guard with size
	tokens[i] = NULL;
	return (tokens);
}

t_cmd	*ft_get_arg(char *token_cmd, t_cmd *cmd)
{
	char **tokens_args;
	int i;

	if (!token_cmd)
		return (NULL);
	i = -1;
	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	tokens_args = (ft_input_contain_dquote(token_cmd)) ? ft_strsplit_args(token_cmd) : ft_strsplit(token_cmd, ' '); // ' ' need to replace with white space
	cmd->args = (char**)malloc(sizeof(char*) * (ft_arrayct(tokens_args) + 1));
	while (tokens_args[++i])
	{
		cmd->args[i] = (char*)ft_memalloc(sizeof(char) * sysconf(_SC_ARG_MAX));
		cmd->args[i] = ft_strcpy(cmd->args[i], tokens_args[i]);
	}
	cmd->args[i] = NULL;
	cmd->next = NULL;
	ft_arraydel(tokens_args);
	return (cmd);
}

void	ft_get_lst_cmds(char **tokens_cmd, t_cmd *cmd)
{
	int i;

	i = -1;
	while (tokens_cmd[++i])
	{
		cmd = ft_get_arg(tokens_cmd[i], cmd);
		cmd = cmd->next;
	}
}