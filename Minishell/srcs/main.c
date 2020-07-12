/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:18:23 by dthan             #+#    #+#             */
/*   Updated: 2020/07/12 11:42:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_promt(void)
{
	char *ptr_dir;

	ft_putstr("minishell:");
	ptr_dir = ft_strrchr(ft_call_value_of("PWD"), '/') + 1;
	if (*ptr_dir == '\0')
		ft_putchar('/');
	else if (!ft_strcmp(ft_call_value_of("HOME"), ft_call_value_of("PWD")))
		ft_putchar('~');
	else
		ft_putstr(ptr_dir);
	ft_putchar(' ');
	ft_putstr(ft_call_value_of("USER"));
	ft_putstr("$ ");
}

int		ft_internal_cmd(t_cmd *cmd)
{
	int			i;
	t_builtin	*get_built_in;

	get_built_in = (t_builtin[8]) {
		{"echo", echo_cmd},
		{"cd", cd_cmd},
		{"setenv", setenv_cmd},
		{"unsetenv", unsetenv_cmd},
		{"env", env_cmd},
		{"exit", exit_cmd},
		{NULL, NULL}
	};
	i = -1;
	while (get_built_in[++i].command)
		if (*cmd->args && ft_strcmp(cmd->args[0], get_built_in[i].command) == 0)
		{
			get_built_in[i].func(&cmd->args[1]);
			return (EXIT_SUCCESS);
		}
	return (EXIT_FAILURE);
}

int		ft_external_cmd(t_cmd *cmd)
{
	char **p;
	char *bin_path;

	if (access(cmd->args[0], F_OK) != -1)
	{
		ft_fork(cmd->args[0], cmd->args);
		return (EXIT_SUCCESS);
	}
	else
	{
		p = ft_strsplit(ft_call_value_of("PATH"), ':');
		while (p && *p)
		{
			bin_path = ft_strjoin(*p, "/");
			bin_path = ft_strjoin_and_free_string1(bin_path, cmd->args[0]);
			if (access(bin_path, F_OK) != -1)
			{
				ft_fork(bin_path, cmd->args);
				free(bin_path);
				ft_arraydel(p);
				return (EXIT_SUCCESS);
			}
			free(bin_path);
			p++;
		}
		ft_arraydel(p);
	}
	return (EXIT_FAILURE);
}

// void	ft_execute(char *input)
// {
// 	char *trimmed_input;
// 	char **cmds;
// 	char **tokens;
// 	int i;

// 	if (input)
// 	{
// 		i = -1;
// 		trimmed_input = ft_strtrim(input);
// 		cmds = ft_strsplit(trimmed_input, ';');
// 		while (cmds[++i])
// 		{
// 			tokens = ft_strsplit(cmds[i], ' ');
// 			if (is_env_var(&tokens[1]) == EXIT_SUCCESS)
// 				tokens = ft_change_tokens(tokens);
// 			if (ft_internal_cmd(tokens) == EXIT_FAILURE && ft_external_cmd(tokens) == EXIT_FAILURE)
// 				ft_printf("minishell: command not found: %s\n", cmds[i]);
// 			ft_arraydel(tokens);
// 		}
// 		ft_arraydel(cmds);
// 		free(trimmed_input);
// 	}
// }

// void	free_cmd_node(t_cmd *node)
// {


// }

void	ft_execute(char *input)
{
	t_cmd	*cmd;
	char	*trimmed_input;
	// t_cmd	*temp;

	cmd = NULL;
	trimmed_input = ft_strtrim(input);
	if (trimmed_input)
	{
		if (trimmed_input[0] != ';')
		{
			cmd = ft_split_cmds(trimmed_input, cmd);
			while (cmd)
			{
				ft_replace_args_if_env_var(cmd->args);
				if (ft_internal_cmd(cmd) == EXIT_FAILURE && \
					ft_external_cmd(cmd) == EXIT_FAILURE)
					ft_error_handle(SYNTAX_CMDNF, cmd->args[0], NULL, NULL);
				// temp = cmd;
				cmd = cmd->next;
				// free_cmd_node(temp);
			}
			//remove the linked list
		}
		else
			ft_error_handle(SYNTAX_SEMICOLON, NULL, NULL, NULL);
		free(trimmed_input);
	}
}

void	signal_handeler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		ft_promt();
		signal(SIGINT, signal_handeler);
	}
}

char	*get_input(int level)
{
	char *line;

	if ((get_next_line(STDOUT_FILENO, &line)) <= 0)
		return (NULL);
	if (is_open_dquote(line, level))
	{
		ft_putstr("dquote> ");
		line = ft_strjoin_and_free_string1(line, "\n");
		line = ft_strjoin_and_free_string2(line, get_input((int)2));
	}
	return (line);
}

void	free_env()
{
	int i;

	i = -1;
	while(env[++i])
		free(env[i]);
	free(env);
}

int		main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	env = ft_new_env(NULL, NULL, 0, envp);
	while (1)
	{
		ft_promt();
		//signal(SIGINT, signal_handeler);
		input = get_input((int)1);
		ft_execute(input);
		free(input);
	}
	free_env();
	return (EXIT_SUCCESS);
}
