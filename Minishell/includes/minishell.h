/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 11:22:29 by dthan             #+#    #+#             */
/*   Updated: 2020/07/29 20:16:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"

/*
** For Linux
** # include <linux/limits.h>
*/
# include <linux/limits.h>
# include <limits.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/signal.h>

# define FORK_ERROR "minishell: forking fail\n"
# define MY_ENOMEM "Out of memory"
# define CD_ENOTDIR "cd: not a directory: "
# define CD_ENOENT "cd: no such file or directory: "
# define CD_EACCES "cd: permission dinied: "
# define CD_EMARG "cd: too many arguments"
# define CD_ENOPWD "cd: string not in pwd: "
# define SYNTAX_SEMICOLON "minishell: syntax error near unexpected token \';\'"
# define SYNTAX_CMDNF "minishell: command not found : "

char				**g_env;
int					line_signal;

typedef struct		s_builtin
{
	char			*command;
	void			(*func)(char**);
}					t_builtin;

typedef struct		s_cmd
{
	char			**args;
	int				dquote;
	struct s_cmd	*next;
}					t_cmd;

/*
** ============================================================================
*/

/*
** Error
*/

void				ft_error_malloc(void);
void				ft_error_handle(char *first, char *second, char *third, \
					char *fourth);

/*
** Helper 1
*/

int					ft_fork(char *path, char **arguments);
void				free_env(void);
void				filter_cmds_list(t_cmd *list);
void				signal_handeler(int signo);
void				provoke_signal_handeler(int signo);

/*
** Helper 2
*/

void				ft_promt(void);
void				ft_push_node(t_cmd **head, t_cmd *node);
void				free_cmd_node(t_cmd *node);
t_cmd				*ft_get_arg(char *token_cmd, t_cmd *cmd);

/*
** =========================  Internal_cmd    =================================
*/

void				cd_cmd(char **tokens);
void				echo_cmd(char **tokens);
void				env_cmd(char **tokens);
void				exit_cmd(char **tokens);
void				setenv_cmd(char **tokens);
void				unsetenv_cmd(char **tokens);

/*
** =========================    Utilities     =================================
*/

/*
** change tokens
*/

char				**ft_replace_tokens_only(char **tokens);
char				**ft_creat_new_and_replace_tokens(char **tokens, int size);
char				**ft_change_tokens(char **tokens);

/*
** tool for env/ env variable
*/

char				**ft_new_env(char *var_name, char *var_value, int step, \
					char **variable);
char				*ft_call_var(char *var_name);
char				*ft_call_value_of(char *var_name);

/*
** tool for checking
*/

int					is_open_dquote(char *input, int level);
int					ft_input_contain_dquote(char *input);

/*
** tool for spliting into single cmds
*/

t_cmd				*ft_split_cmds(char *input, t_cmd *cmds);

/*
** tool for spliting into single arguments
*/

void				ft_jump_dquote(char *str, int *i, int *inside_dquote);
void				ft_jump_arg(char *str, int *i);
int					ft_get_nb_of_args(char *input);
char				*ft_get_single_arg(char *input, int *tail);
char				**ft_strsplit_args(char *input);

/*
** replace argument
*/

void				ft_replace_args_if_env_var(char **args);

#endif
