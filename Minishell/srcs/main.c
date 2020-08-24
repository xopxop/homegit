/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:18:23 by dthan             #+#    #+#             */
/*   Updated: 2020/07/29 20:34:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_internal_cmd(t_cmd *cmd)
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

static int	ft_external_cmd(t_cmd *cmd)
{
	char	**p;
	char	*bin_path;
	int		i;

	if (access(cmd->args[0], F_OK) != -1)
		return (ft_fork(cmd->args[0], cmd->args));
	else
	{
		p = ft_strsplit(ft_call_value_of("PATH"), ':');
		i = -1;
		while (p && p[++i])
		{
			bin_path = ft_3strjoin(p[i], "/", cmd->args[0]);
			if (access(bin_path, F_OK) != -1)
			{
				ft_fork(bin_path, cmd->args);
				free(bin_path);
				ft_arraydel(p);
				return (EXIT_SUCCESS);
			}
			free(bin_path);
		}
		ft_arraydel(p);
	}
	return (EXIT_FAILURE);
}

static void	ft_execute(char *input)
{
	t_cmd	*cmd;
	char	*trimmed_input;
	t_cmd	*temp;

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
				if (ft_internal_cmd(cmd) && ft_external_cmd(cmd))
					ft_error_handle(SYNTAX_CMDNF, cmd->args[0], NULL, NULL);
				temp = cmd;
				cmd = cmd->next;
				free_cmd_node(temp);
			}
		}
		else
			ft_error_handle(SYNTAX_SEMICOLON, NULL, NULL, NULL);
		free(trimmed_input);
	}
}

static char	*get_input(int level)
{
	char *line;

	if ((get_next_line(STDOUT_FILENO, &line)) <= 0)
		return (NULL);
	if (is_open_dquote(line, level) && line_signal == 0)
	{
		ft_putstr("dquote> ");
		line = ft_strjoin_and_free_string1(line, "\n");
		line = ft_strjoin_and_free_2strings(line, get_input((int)2));
	}
	return (line);
}

int			main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	g_env = ft_new_env(NULL, NULL, 0, envp);
	while (1)
	{
		ft_promt();
		signal(SIGINT, signal_handeler);
		line_signal = 0;
		input = get_input((int)1);
		line_signal = 1;
		ft_execute(input);
		free(input);
	}
	free_env();
	return (EXIT_SUCCESS);
}
