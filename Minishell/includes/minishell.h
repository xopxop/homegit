/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 11:22:29 by dthan             #+#    #+#             */
/*   Updated: 2020/03/26 11:25:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include <limits.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/stat.h>

# define MY_ENOMEM "Out of memory"
# define CD_ENOTDIR "cd: not a directory: "
# define CD_ENOENT "cd: no such file or directory: "
# define CD_EACCES "cd: permission dinied: "
# define CD_EMARG "cd: too many arguments "
# define CD_ENOPWD "cd: string not in pwd: "

typedef struct	s_command
{
	char	*command;
	char	**(*func)(char**, char**);
}		t_command;

// Error
void ft_error_malloc(void);
void	ft_error_handle(char *first, char *second, char *third);

// Helper

char	*ft_find_env(char *name, char **env);
void	ft_fork(char *path, char **arguments, char **env);
void	ft_free_old_env(char **old_env);
char	*ft_call_var(char *var_name, char **env);

// internal
char	**cd_cmd(char **tokens, char **env);
char	**echo_cmd(char **tokens, char **env);
char	**env_cmd(char **tokens, char **env);
char	**exit_cmd(char **tokens, char **env);
char	**setenv_cmd(char **tokens, char **env);
char	**unsetenv_cmd(char **tokens, char **env);


char	*change_env(char *var_name, char *var_value, char *old_var);

#endif
