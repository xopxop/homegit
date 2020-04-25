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
# include <sys/vlimit.h>

# include "shell_error.h"
# include "shell_grammar.h"
# include "struct.h"

char **env;

/*
**	Environ
*/

char			**ft_new_env(char *var_name, char *var_value, int step, char **env);
char			*ft_call_var(char *var_name);
char			*ft_call_value_of(char *var_name);

/*
**	Lexer
*/

// t_cmd			*lexer(char *input, t_cmd *cmds);
// char			**ft_strsplit_cmds(char *input);
// char			**ft_strsplit_args(char *input);

t_token	*lexer(char *input);

/*
**	Parser
*/

// void			ft_lstpush_cm_suffix(t_cmd_suffix *node, t_cmd_suffix **lst);
// void			ft_lstpush_simple_cmd(t_simple_cmd *node, t_simple_cmd **lst);
// t_pipe_sequence	*pipe_sequence(t_token *token);
// int				parser(t_token token, t_pipe_sequence *ps);

/*
**	Executor
*/

// void			executor(t_cmd *cmd, t_pipe_sequence *pipe);
// void			ft_replace_args_if_env_var(char **args);

/*
** internal_cmd
*/

// void			cd_cmd(char **tokens);
// void			echo_cmd(char **tokens);
// void			env_cmd(char **tokens);
// void			exit_cmd(char **tokens);
// void			setenv_cmd(char **tokens);
// void			unsetenv_cmd(char **tokens);

/*
** Utilities
*/

int				ft_input_contain_dquote(char *input);
int				is_open_dquote(char *input, int level);

// Error
void			ft_error_malloc(void);
void			ft_error_handle(char *first, char *second, char *third, char *fourth);

#endif
