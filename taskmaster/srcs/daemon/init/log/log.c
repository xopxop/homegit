/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 01:16:03 by dthan             #+#    #+#             */
/*   Updated: 2020/08/28 01:16:39 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

void writeIntoLog(char *message)
{
	time_t mytime = time(NULL);
	char *time_str = ctime(&mytime);
	time_str[ft_strlen(time_str) - 1] = '\0';
	ft_dprintf(g_denv.log_fd , "%s: %s\n", time_str, message);
}

void init_log(void)
{
	int fd;
	fd = open(g_denv.opt.str[LOGFILE], O_RDWR | O_APPEND | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	g_denv.log_fd = fd;
	writeIntoLog("Taskmasterd is now running.");
}
