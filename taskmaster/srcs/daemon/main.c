/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:42:42 by dthan             #+#    #+#             */
/*   Updated: 2020/08/21 15:50:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/daemon.h"

// uid_t == unsigned int

void	launchJobs(t_list *prgm_list)
{
	t_list *ptr;

	ptr = prgm_list;
	while (ptr)
	{
		ptr = ptr->next;
	}
}

void initDefaultState(int ac, char **av, char **env)
{
	g_denv.ac = ac;
	g_denv.av = av;
	g_denv.env = env;
	g_denv.opt.str[CONFIGURATION] = DEFAULT_CONFIGURATION;
	g_denv.opt.str[USER] = NULL;
	g_denv.opt.str[DIRECTORY] = NULL;
	g_denv.opt.str[LOGFILE] = DEFAULT_LOGFILE;
	g_denv.opt.str[LOGLEVEL] = DEFAULT_LOGLVL;
	g_denv.opt.str[CHILDLOGDIR] = DEFAULT_CHILDLOGDIR;
	g_denv.opt.umask = DEFAULT_UMASK;
	g_denv.opt.environ = NULL;
	// need to check default derectory
}

t_program *get_program(dictionary *dict, char *programName)
{
	t_program *new;

	new = (t_program*)ft_memalloc(sizeof(t_program));
	new->name = ft_strsub(programName, 8, ft_strlen(programName) - 8);
	new->command = iniparser_getstring(dict, ":command", NULL);
	new->numprocs = iniparser_getint(dict, ":numprocs", 1);
	new->autostart = iniparser_getboolean(dict, ":autostart", 1); // need to check
	new->autorestart = iniparser_getboolean(dict, ":autostart", 1);
	new->startsecs = iniparser_getint(dict, ":startsecs:", 1);
	new->startretries = iniparser_getint(dict, ":startretries", 1);
	// exit_code
	new->stopwaitsecs = iniparser_getint(dict, ":stopwaitsecs", 10);
	new->stopsignal = iniparser_getstring(dict, ":stopsignal" ,"TERM");
	new->directory = iniparser_getstring(dict, ":stopsignal" ,"TERM");;
	new->piority = ;
	new->stdout_logfile = iniparser_getstring(dict, ":stdout_logfile", NULL);
	new->stderr_logfile = iniparser_getstring(dict, ":stderr_logfile", NULL);
	new->umask = iniparser_getint(dict, ":umask", 0);
}

void push_to_list(t_program *pro)
{
	t_list *new;

	new = ft_lstnew(pro, sizeof(t_program));
	ft_lstadd(&g_denv.prgm_list, new);
}

void loadConfigFile(void)
{
	g_denv.dict = iniparser_load(g_denv.opt.str[CONFIGURATION]);
	if (g_denv.dict == NULL)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
}

void getSection(void)
{
	int sections;
	char *secname;
	int i;
	t_program *program;

	i = -1,
	sections = iniparser_getnsec(g_denv.dict);
	if (sections == -1)
		ft_dprintf(STDERR_FILENO, "Error section:\n");
	while (i < sections)
	{
		secname = (char*)iniparser_getsecname(g_denv.dict, i);
		if (ft_strnequ(secname, "program:", 8))
		{
			program = get_program(g_denv.dict, secname);
			push_to_list(program);
		}
	}
}

void parseConfigFile()
{
	loadConfigFile();
	getSection();
}

void init(int ac, char **av, char **env)
{
	initDefaultState(ac, av, env);
	parseCommandLine(ac, av);
	parseConfigFile();
	initSignal();
	initDaemon();
	initSocket();
}

int	main(int ac, char **av, char **env)
{
	init(ac - 1, &av[1], env);
	
	//init
	//creat daemon






	launchJobs(g_denv.prgm_list);
	//listen
	return (EXIT_SUCCESS);
}