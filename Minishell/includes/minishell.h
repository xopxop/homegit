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
# include <sys/signal.h>

# define MY_ENOMEM "Out of memory"
# define CD_ENOTDIR "cd: not a directory: "
# define CD_ENOENT "cd: no such file or directory: "
# define CD_EACCES "cd: permission dinied: "
# define CD_EMARG "cd: too many arguments "
# define CD_ENOPWD "cd: string not in pwd: "

char **env;

typedef struct	s_command
{
	char	*command;
	void	(*func)(char**);
}		t_command;

// Error
void	ft_error_malloc(void);
void	ft_error_handle(char *first, char *second, char *third);

// Helper

char	**ft_new_env(char *var_name, char *var_value, int step, char **variable);
char	*ft_call_var(char *var_name);
char	*ft_call_value_of(char *var_name);
void	ft_fork(char *path, char **arguments);
void	ft_free_old_env(char **old_env);
int		open_d_quote(char *input, int level);

// internal
void	cd_cmd(char **tokens);
void	echo_cmd(char **tokens);
void	env_cmd(char **tokens);
void	exit_cmd(char **tokens);
void	setenv_cmd(char **tokens);
void	unsetenv_cmd(char **tokens);


void	change_var(char *old_value, char *new_value);

#endif
