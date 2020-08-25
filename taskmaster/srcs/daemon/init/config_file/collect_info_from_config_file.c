/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_info_from_config_file.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 02:00:28 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 02:59:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

static char *getCommand(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":command");
	return (char*)iniparser_getstring(dict, buf, NULL);
}

static int getNumprocs(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":numprocs");
	return iniparser_getint(dict, buf, 1);
}

static int getAutostart(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":autostart");
	return iniparser_getboolean(dict, buf, true);
}

static int getAutorestart(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":autorestart");
	return iniparser_getboolean(dict, buf, unexpected);
}

static int getStartsecs(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":startsecs");
	return iniparser_getint(dict, buf, 1);
}

static int getStartretries(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":startretries");
	return iniparser_getint(dict, buf, 3);
}

static int getStopwaitsecs(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":stopwaitsecs");
	return iniparser_getint(dict, buf, 10);
}

static char *getStopsignal(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":stopsignal");
	return (char*)iniparser_getstring(dict, buf, "TERM");
}

static char *getDirectory(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":directory");
	return (char*)iniparser_getstring(dict, buf, NULL);
}

static char *getStdout_logfile(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":stdout_logfile");
	return (char*)iniparser_getstring(dict, buf, "AUTO");
}

static char *getStderr_logfile(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":stderr_logfile");
	return (char*)iniparser_getstring(dict, buf, "AUTO");
}

static int getUmask(dictionary *dict, char *programName)
{
	char buf[256];

	ft_bzero(buf, 256);
	ft_strcpy(buf, programName);
	ft_strcat(buf, ":umask");
	return iniparser_getint(dict, buf, DEFAULT_UMASK);
}

static t_program *get_program(dictionary *dict, char *programName)
{
	t_program *new;

	new = (t_program*)ft_memalloc(sizeof(t_program));
	new->name = ft_strsub(programName, 8, ft_strlen(programName) - 8);
	new->command = getCommand(dict, programName);
	new->numprocs = getNumprocs(dict, programName);
	new->autostart = getAutostart(dict, programName); // need to check
	new->autorestart = getAutorestart(dict, programName);
	new->startsecs = getStartsecs(dict, programName);
	new->startretries = getStartretries(dict, programName);
	// exit_code
	new->stopwaitsecs = getStopwaitsecs(dict, programName);
	new->stopsignal = getStopsignal(dict, programName);
	new->directory = getDirectory(dict, programName);
	// new->piority = ;
	new->stdout_logfile = getStdout_logfile(dict, programName);
	new->stderr_logfile = getStderr_logfile(dict, programName);
	new->umask = getUmask(dict, programName);
	return (new);
}

static void push_to_list(t_program *pro)
{
	t_list *new;

	new = ft_lstnew(pro, sizeof(t_program));
	ft_lstadd(&g_denv.prgm_list, new);
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
	while (++i < sections)
	{
		secname = (char*)iniparser_getsecname(g_denv.dict, i);
		if (ft_strnequ(secname, "program.", 8))
		{
			program = get_program(g_denv.dict, secname);
			print_program(*program); // for debug
			push_to_list(program);
		}
	}
}
