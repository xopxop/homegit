/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliting_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:13:56 by dthan             #+#    #+#             */
/*   Updated: 2020/04/06 00:13:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_get_single_shell(char *input, int *tail)
{
	char *str;
	int head;

	head = *tail + 1;
	while(input[++(*tail)] && input[*tail] != ';')
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

static int	ft_get_size_shell(char *input)
{
	int ct;
	int i;
	int inside_dquote;

	ct = 1;
	i = -1;
	inside_dquote = 0;
	while (input[++i])
	{
		inside_dquote = (input[i] && (inside_dquote % 2 == 1)) ? 1 : 0;
		if (input[i] == ';' && input[i + 1] && !inside_dquote)
			ct++;
	}
	return (ct);
}

static char	**ft_strsplit_shell(char *input)
{
	char **shell;
	int size;
	int i;
	int pos_input;

	i = -1;
	pos_input = -1;
	size = ft_get_size_shell(input);
	shell = (char**)malloc(sizeof(char*) * (size + 1)); //need to add ERR
	while (++i < size)
		shell[i] = ft_get_single_shell(input, &pos_input); // for sure the str never return NULL because the function was guard with size
	shell[i] = NULL;
	return (shell);
}

t_cmd	*ft_split_cmds(char *input, t_cmd *cmds)
{
	char **shell;
	t_cmd *head;

	shell = (ft_input_contain_dquote(input)) ? ft_strsplit_shell(input) : ft_strsplit(input, ';');
	cmds = ft_get_arg(shell[0], cmds);
	head = cmds;
	ft_get_lst_cmds(&shell[1], cmds);
	ft_arraydel(shell);
	return (head);
}
