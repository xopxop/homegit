/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:18:23 by dthan             #+#    #+#             */
/*   Updated: 2020/03/27 22:25:51 by dthan            ###   ########.fr       */
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

int		ft_internal_cmd(char **tokens)
{
	int			i;
	t_command	*get_built_in;

	get_built_in = (t_command[8]) {
		{"echo", echo_cmd},
		{"cd", cd_cmd},
		{"setenv", setenv_cmd},
		{"unsetenv", unsetenv_cmd},
		{"env", env_cmd},
		{"exit", exit_cmd},
		{NULL, NULL}
	};
	i = 0;
	while (get_built_in[i].command)
	{
		if (ft_strcmp(tokens[0], get_built_in[i].command) == 0)
		{
			get_built_in[i].func(tokens + 1);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

int		ft_external_cmd(char **tokens)
{
	char **p;
	char *bin_path;

	p = ft_strsplit(ft_call_value_of("PATH"), ':');
	while (*p)
	{
		bin_path = ft_strjoin(*p, "/");
		bin_path = ft_strjoin_and_free_string1(bin_path, *tokens);
		if (access(bin_path, F_OK) != -1)
		{
			ft_fork(bin_path, tokens);
			free(bin_path);
			return (EXIT_SUCCESS);
		}
		free(bin_path);
		p++;
	}
	// need to free p
	return (EXIT_FAILURE);
}

/*
** need to change the ft_find_built_in
*/

void	ft_execute(char **tokens)
{

	if (*tokens != NULL)
		if (ft_internal_cmd(tokens) == EXIT_FAILURE && ft_external_cmd(tokens) == EXIT_FAILURE)
			ft_printf("minishell: command not found: %s\n", *tokens);
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
	if (open_d_quote(line, level))
	{
		ft_putstr("dquote> ");
		line = ft_strjoin_and_free_string1(line, "\n");
		line = ft_strjoin_and_free_string2(line, get_input((int)2));
	}
	return (line);
}

int		minishell()
{
	char	*input;

	while (1)
	{
		ft_promt();
		signal(SIGINT, signal_handeler);
		input = get_input((int)1);
		ft_execute(&input);
		free(input);
	}
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	env = ft_new_env(NULL, NULL, 0, envp);
	return (minishell());
}
