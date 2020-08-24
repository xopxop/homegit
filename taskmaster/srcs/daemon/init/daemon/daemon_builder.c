/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daemon_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 01:39:45 by dthan             #+#    #+#             */
/*   Updated: 2020/08/20 02:00:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/daemon.h"

uid_t set_uid(void)
{
	uid_t sid;

	sid = setsid();
	if (sid < 0)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	return (sid);
}

void	close_standardfd(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void	forkingTheParrentProcess(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	if (pid > 0)
		exit(EXIT_SUCCESS);
}

void	creat_daemon(void)
{
	pid_t sid;

	forkingTheParrentProcess();
	umask(0);
	close_standardfd();
}