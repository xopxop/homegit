/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:42:42 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 04:01:48 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/daemon.h"

// uid_t == unsigned int
/*
void	launchJobs(t_list *prgm_list)
{
	t_list *ptr;

	ptr = prgm_list;
	while (ptr)
	{
		ptr = ptr->next;
	}
}
*/

void parseConfigFile()
{
	loadConfigFile();
	getSection();
}

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

void init(int ac, char **av, char **env)
{
	initDefaultState(ac, av, env);
	printState();
	parseCommandLine(ac, av);
	printState();
	init_log();
	parseConfigFile();
	initSignal();
	creatDaemon();
	// initSocket();
	writeIntoLog("Taskmasterd is logging out.");
	close(g_denv.log_fd);
}

int	main(int ac, char **av, char **env)
{
	init(ac - 1, &av[1], env);
	// launchJobs(g_denv.prgm_list);
	return (EXIT_SUCCESS);
}