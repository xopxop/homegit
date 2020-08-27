/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daemon_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 01:39:45 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 03:23:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

// pid_t set_uid(void)
// {
// 	pid_t sid;

// 	sid = setsid();
// 	if (sid < 0)
// 	{
// 		strerror(errno);
// 		exit(EXIT_FAILURE);
// 	}
// 	return (sid);
// }

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
	{
		ft_printf("parent id: %d\n", pid);
		exit(EXIT_SUCCESS);
	}
	ft_printf("child id: %d\n", getsid(0));
}

void	creatDaemon(void)
{
	forkingTheParrentProcess();
	umask(0);
	close_standardfd();
	int fd;
	fd = open("/home/dthan/Projects/homegit/taskmaster/output.txt", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		write(fd, "daemon initialized\n", 19);
		sleep(5);
		break;
	}
	write(fd, "daemon finished\n", 16);
	close(fd);
}