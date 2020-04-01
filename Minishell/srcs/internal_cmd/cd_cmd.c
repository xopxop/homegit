/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:24:33 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 02:24:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_goto_dir_helper(char **subdir)
{
	int ct;

	ct = 0;
	if (subdir)
	{
		while (*subdir)
		{
			ct = ft_strlen(*subdir) + 1;
			subdir++;
		}
	}
	return (ct);
}

char	*ft_goto(char *token, char *current_path, char *new_path)
{	
	char **subdir;
	char **ptr_free;
	int size;

	token = (!ft_strcmp("$HOME", token)) ? NULL : token;
	(token != NULL) ? token++ : 0;
	subdir = ft_strsplit(token, '/');
	size = ft_strlen(current_path) + ft_goto_dir_helper(subdir);
	if (!(new_path = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		ft_error_malloc();
	new_path = ft_strcpy(new_path, current_path);
	if (subdir)
	{
		ptr_free = subdir;
		while (*subdir)
		{	
			new_path = ft_strcat(new_path, "/");
			new_path = ft_strcat(new_path, *subdir);
			subdir++;
		}
		ft_free_old_env(ptr_free); // will change later, it should be called free 2D array
	}
	return (new_path);
}

char	**cd_cmd(char **tokens, char **env)
{
	char *path;
	struct stat s;

	
	if (tokens[1] == NULL)
	{	
		path = NULL;
		if (*tokens != NULL && *tokens[0] != '~' && *tokens[0] != '/' \
				&& (ft_strcmp("$HOME", *tokens)))
			path = *tokens;
		else
			path = ft_goto(*tokens, (*tokens[0] == '/') ? \
				"/" : ft_call_var("HOME", env) + 5, path);
		if (access(path, F_OK) == 0)
		{
			lstat(path, &s);
			if (S_ISDIR(s.st_mode))
				if (access(path, R_OK) == 0)
				{
					chdir(path);
					ft_strcpy(ft_call_var("OLDPWD", env) + 7, ft_call_var("PWD", env) + 4);
					getcwd(ft_call_var("PWD", env) + 4, PATH_MAX);
				}
				else
					ft_error_handle(CD_EACCES, path, "\n");
			else
				ft_error_handle(CD_ENOTDIR, path, "\n");
		}
		else
			ft_error_handle(CD_ENOENT, *tokens, "\n");
		free(path);
	}
	else
		ft_error_handle(CD_ENOPWD, "\n", NULL);
	return (env);
}
