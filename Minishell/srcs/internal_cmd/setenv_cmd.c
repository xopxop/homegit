/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:24:43 by dthan             #+#    #+#             */
/*   Updated: 2020/07/13 12:04:06 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_var(char *old_value, char *new_value)
{
	if (ft_strcmp(old_value, new_value))
		ft_strcpy(old_value, new_value);
}

void	setenv_cmd(char **tokens)
{
	int		len;
	int		i;
	char	**ptr;

	if (tokens[0] && tokens[1])
	{
		len = ft_strlen(tokens[0]);
		i = -1;
		while (g_env[++i])
			if (!ft_strncmp(tokens[0], g_env[i], len) && g_env[i][len] == '=')
			{
				change_var(g_env[i] + len + 1, tokens[1]);
				return ;
			}
		if (g_env[i] == NULL)
		{
			ptr = g_env;
			g_env = ft_new_env(tokens[0], tokens[1], 1, g_env);
			ft_arraydel(ptr);
		}
	}
}
