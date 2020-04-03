/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 03:08:48 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 03:08:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_new_env(char *var_name, char *var_value, int step, char **env)
{
	char **ptr_new_env;
	char **new_env;
	int i;

	i = -1;
	ptr_new_env = NULL;
	if (!(new_env = (char**)malloc(sizeof(char*) * (ft_string_count(env) + step + 1))))
		ft_error_malloc();
	ptr_new_env = new_env;
	while (env[++i])
	{
		if (step == -1 && !ft_strncmp(var_name, env[i], ft_strlen(var_name)))
			continue ;
		*new_env = (char*)ft_memalloc((sizeof(char) * (NAME_MAX + PATH_MAX + 2)));
		*new_env = ft_strcpy(*new_env, env[i]);
		new_env++;
	}
	if (var_name && var_value && step == 1)
	{
		*new_env = (char*)ft_memalloc((sizeof(char) * (NAME_MAX + PATH_MAX + 2)));
		*new_env = ft_strcpy(*new_env, var_name);
		*new_env = ft_strcat(*new_env, "=");
		*new_env = ft_strcat(*new_env, var_value);
		new_env++;
	}
	new_env = NULL;
	return (ptr_new_env);
}

char	*ft_call_var(char *var_name)
{
	int i;
	int len;

	i = -1;
	while (env[++i])
	{
		len = ft_strlen(var_name);
		if (!ft_strncmp(var_name, env[i], len))
			if (env[i][len] == '=')
				return (env[i]);
	}
	return (NULL);
}

char	*ft_call_value_of(char *var_name)
{
	char *p;

	return ((p = ft_call_var(var_name)) != NULL) ? &*(p + ft_strlen(var_name) + 1) \
												: &*p;
}

void	ft_fork(char *path, char **arguments)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(path, arguments, env);
	else if (pid < 0)
		ft_printf("can not fork\n");
	wait(&pid);
}

void	ft_free_old_env(char **old_env)
{
	char *ptr;

	while (*old_env)
	{
		ptr = *old_env;
		old_env++;
		free(ptr);
	}
	ptr = *old_env;
	free(ptr);
}

int		open_d_quote(char *input, int level)
{
	int matched;
	int i;

	i = -1;
	matched = 0;
	while (input[++i])
		if (input[i] == '"')
			matched++;
	if (level == 1)
		return (((matched % 2) == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
	return (((matched % 2) == 0) ? EXIT_FAILURE : EXIT_SUCCESS);
}