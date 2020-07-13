/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliting_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 00:13:56 by dthan             #+#    #+#             */
/*   Updated: 2020/07/13 11:03:36 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_get_single_shell(char *input, int *tail)
{
	char	*str;
	int		head;

	head = *tail + 1;
	while (input[++(*tail)] && input[*tail] != ';')
	{
		if (input[*tail] == '"')
		{
			while (input[++(*tail)])
				if (input[*tail] == '"')
					break ;
		}
	}
	str = ft_strndup(&input[head], *tail - head);
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
		if (input[i] == ';' && input[i + 1] && \
		input[i + 1] != ';' && !inside_dquote)
			ct++;
	}
	return (ct);
}

static char	**ft_strsplit_shell(char *input)
{
	char	**shell;
	int		size;
	int		i;
	int		pos_input;

	i = -1;
	pos_input = -1;
	size = ft_get_size_shell(input);
	if (!(shell = (char**)malloc(sizeof(char*) * (size + 1))))
		ft_error_handle(MY_ENOMEM, NULL, NULL, NULL);
	while (++i < size)
		shell[i] = ft_get_single_shell(input, &pos_input);
	shell[i] = NULL;
	return (shell);
}

static void	ft_delete_dquote(t_cmd *lst)
{
	int i;
	int j;

	while (lst)
	{
		i = -1;
		while (lst->args[++i])
			if (ft_input_contain_dquote(lst->args[i]))
			{
				j = -1;
				while (lst->args[i][++j])
					if (lst->args[i][j] == '"')
					{
						ft_strcpy(&lst->args[i][j], &lst->args[i][j + 1]);
						j = -1;
					}
			}
		lst = lst->next;
	}
}

t_cmd		*ft_split_cmds(char *input, t_cmd *cmds)
{
	char	**shell;
	t_cmd	*node;
	int		i;

	i = -1;
	shell = ft_strsplit_shell(input);
	while (shell[++i])
	{
		node = ft_get_arg(shell[i], node);
		ft_push_node(&cmds, node);
	}
	ft_delete_dquote(cmds);
	filter_cmds_list(cmds);
	ft_arraydel(shell);
	return (cmds);
}
