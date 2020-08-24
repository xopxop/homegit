/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 03:08:48 by dthan             #+#    #+#             */
/*   Updated: 2020/07/29 20:36:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_fork(char *path, char **arguments)
{
	pid_t pid;

	pid = fork();
	signal(SIGINT, provoke_signal_handeler);
	if (pid == 0)
		execve(path, arguments, g_env);
	else if (pid < 0)
		ft_putstr(FORK_ERROR);
	wait(&pid);
	return (EXIT_SUCCESS);
}

void	free_env(void)
{
	int i;

	i = -1;
	while (g_env[++i])
		free(g_env[i]);
	free(g_env);
}

void	filter_cmds_list(t_cmd *list)
{
	t_cmd *temp;

	while (list)
	{
		temp = list;
		list = list->next;
		if (temp->args == NULL)
			free(temp);
	}
}

void	signal_handeler(int signo)
{
	if (signo == SIGINT)
	{
		line_signal = 1;
		ft_putchar_fd('\n', STDOUT_FILENO);
		ft_promt();
		signal(SIGINT, signal_handeler);
	}
}

void	provoke_signal_handeler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		signal(SIGINT, provoke_signal_handeler);
	}
}
