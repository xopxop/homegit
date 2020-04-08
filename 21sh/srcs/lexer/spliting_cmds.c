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

static char	*ft_get_single_cmd(char *input, int *tail)
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
	if (*tail <= head)
		return (NULL);
	str = ft_strndup(&input[head], *tail - head);
	*tail = *tail + 1;
	return (str);
}

static int	ft_get_nb_cmds(char *input)
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

char		**ft_strsplit_cmds(char *input)
{
	char	**cmds;
	int		size;
	int		i;
	int		pos_input;

	i = -1;
	pos_input = -1;
	size = ft_get_nb_cmds(input);
	if (!(cmds = (char**)malloc(sizeof(char*) * (size + 1))))
		ft_error_handle(MY_ENOMEM, NULL, NULL, NULL);
	while (++i < size)
		cmds[i] = ft_get_single_cmd(input, &pos_input);
	cmds[i] = NULL;
	return (cmds);
}
