/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:42:42 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 03:11:23 by dthan            ###   ########.fr       */
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

void init(int ac, char **av, char **env)
{
	initDefaultState(ac, av, env);
	printState();
	parseCommandLine(ac, av);
	printState();
	parseConfigFile();
	// initSignal();
	// initDaemon();
	// initSocket();
}

int	main(int ac, char **av, char **env)
{
	init(ac - 1, &av[1], env);
	// launchJobs(g_denv.prgm_list);
	return (EXIT_SUCCESS);
}