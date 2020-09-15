/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:42:42 by dthan             #+#    #+#             */
/*   Updated: 2020/09/15 17:17:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/daemon.h"

void parseConfigFile()
{
	loadConfigFile();
	getSection();
}

void socketCreation(void)
{
	int sockfd;

	sockfd = socket(PF_UNIX, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		writeIntoLog("CREAT");
		writeIntoLog(strerror(errno));
		exit(EXIT_FAILURE);
	}
	// int opt = 1;
	// // need to check later
	// if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt)) == -1)
	// {
	// 	writeIntoLog("SET");
	// 	writeIntoLog(strerror(errno));
	// 	cleaner();
	// 	exit(EXIT_FAILURE);
	// }
	g_denv.socketfd = sockfd;
	ft_memset(&g_denv.addr, 0, sizeof(g_denv.addr));
	g_denv.addr.sun_family = AF_UNIX;
	ft_strcpy(g_denv.addr.sun_path, DEFAULT_SOCKET);
}

void bindSocket(void)
{
	// need to creat /tmp/taskmaster.d directory
	if ((bind(g_denv.socketfd, (struct sockaddr*)&g_denv.addr, sizeof(g_denv.addr))) == -1)
	{
		writeIntoLog("HERE");
		writeIntoLog("BIND");
		if (errno != EADDRINUSE)
		{
			writeIntoLog(strerror(errno));
			cleaner();
			exit(EXIT_FAILURE);
		}
		writeIntoLog("Unlinking existing socket");
		unlink(DEFAULT_SOCKET);
		if ((bind(g_denv.socketfd, (struct sockaddr*)&g_denv.addr, sizeof(g_denv.addr))) == -1)
		{
			writeIntoLog("rebind socket failed");
			cleaner();
			exit(EXIT_FAILURE);
		}
		writeIntoLog("rebind sucessfully");
	}
}

void listenSocket(void)
{
	if(listen(g_denv.socketfd, MAX_CLIENT) == -1)
	{
		writeIntoLog("LISTEN");
		writeIntoLog(strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void initSocket(void)
{
	socketCreation();
	bindSocket();
	listenSocket();
	writeIntoLog("Socket is now up and running");
	// acceptSocket();
}

void init(int ac, char **av, char **env)
{
	initDefaultState(ac, av, env);
	// printState();
	parseCommandLine(ac, av);
	// printState();
	init_log();
	parseConfigFile();
	initSignal();
	// creatDaemon();
	initSocket();
}

/*
void initInstance(t_instance *inst, int id, char *name)
{
	ft_memset(inst, 0, sizeof(t_instance));
	inst->id = id;
	inst->name = name;
	inst->state = E_STOPPED;
	inst->fd[0] = -1;
	inst->fd[1] = -1;
	inst->fd[2] = -1;
}

void launchInstance(t_program *prog, int inst_nb)
{
	t_instance inst;

	initInstance(&inst, inst_nb, prog->name);
	addInstance();
	if (prog->autostart == true)
	{
		startInstance();
	}
}

void launchJobs(void)
{
	t_list *ptr;
	t_program *prog;
	int inst_nb;
	
	ptr = g_denv.prgm_list;
	while (ptr)
	{
		inst_nb = 0;
		prog = ptr->content;
		while (inst_nb < prog->numprocs)
		{
			launchInstance(prog, inst_nb);
			inst_nb++;
		}
		ptr = ptr->next;
	}
}
*/
int	main(int ac, char **av, char **env)
{
	init(ac - 1, &av[1], env);
	// launchJobs();
	writeIntoLog("Taskmasterd is logging out.");
	cleaner();
	return (EXIT_SUCCESS);
}