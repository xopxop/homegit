/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_for_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 06:16:45 by dthan             #+#    #+#             */
/*   Updated: 2020/07/13 12:02:38 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_new_env(char *var_name, char *var_value, int step, char **env)
{
	char	**new_env;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_env = (char**)malloc(sizeof(char*) * (ft_arrayct(env) + step + 1));
	while (env[++i])
	{
		if (step == -1 && !ft_strncmp(var_name, env[i], ft_strlen(var_name)))
			continue ;
		new_env[++j] = (char*)ft_memalloc(sizeof(char) * ARG_MAX);
		new_env[j] = ft_strcpy(new_env[j], env[i]);
	}
	if (var_name && var_value && step == 1)
	{
		new_env[++j] = (char*)ft_memalloc(sizeof(char) * ARG_MAX);
		new_env[j] = ft_strcpy(new_env[j], var_name);
		new_env[j] = ft_strcat(new_env[j], "=");
		new_env[j] = ft_strcat(new_env[j], var_value);
	}
	new_env[++j] = NULL;
	return (new_env);
}

char	*ft_call_var(char *var_name)
{
	int i;
	int len;

	i = -1;
	while (g_env[++i])
	{
		len = ft_strlen(var_name);
		if (!ft_strncmp(var_name, g_env[i], len))
			if (g_env[i][len] == '=')
				return (g_env[i]);
	}
	return (NULL);
}

char	*ft_call_value_of(char *var_name)
{
	char *p;

	return ((p = ft_call_var(var_name)) != NULL) ? \
	&*(p + ft_strlen(var_name) + 1) : NULL;
}
