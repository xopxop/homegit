/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 02:04:31 by dthan             #+#    #+#             */
/*   Updated: 2020/08/24 18:09:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

void printHelp(void)
{
	ft_putendl("supervisord -- run a set of applications as daemons");
	ft_putendl("");
	ft_putendl("Usage: /usr/bin/supervisord [options]");
	ft_putendl("");
	ft_putendl("Options:");
	ft_putendl("-c/--configuration FILENAME -- configuration file path (searches if not given");
	ft_putendl("-n/--nodaemon -- run in the foreground (same as 'nodaemon=true' in config gile)");
	ft_putendl("-h/--help -- print this usage message and exit");
	ft_putendl("-v/--version -- print supervisord version number and exit");
	ft_putendl("-u/--user USER -- run supervisord as this user (or numeric uid)");
	ft_putendl("-m/--umask UMASK -- use this umask for daemon subprocess (default is 022)");
	ft_putendl("-d/--directory DIRECTORY -- directory to chdir to when daemonized");
	ft_putendl("-l/--logfile FILENAME -- use FILENAME as logfile path");
	ft_putendl("-y/--logfile_maxbytes BYTES -- use BYTES to limit the max size of logfile");
	ft_putendl("-z/--logfile_backups NUM -- number of backups to keep when max bytes reached");
	ft_putendl("-e/--loglevel LEVEL -- use LEVEL as log level (debug,info,warn,error,critical)");
	ft_putendl("-j/--pidfile FILENAME -- write a pid file for the daemon process to FILENAME");
	ft_putendl("-i/--identifier STR -- identifier used for this instance of supervisord");
	ft_putendl("-q/--childlogdir DIRECTORY -- the log directory for child process logs");
	ft_putendl("-k/--nocleanup --  prevent the process from performing cleanup (removal of old automatic child log files) at startup.");
	ft_putendl("-a/--minfds NUM -- the minimum number of file descriptors for start success");
	ft_putendl("-t/--strip_ansi -- strip ansi escape codes from process output");
	ft_putendl("--minprocs NUM  -- the minimum number of processes available for start success");
	ft_putendl("--profile_options OPTIONS -- run supervisord under profiler and output results based on OPTIONS, which  is a comma-sep'd list of 'cumulative', 'calls', and/or 'callers', e.g. 'cumulative,callers')");
}

static void getRequiredArgument(char *opt, char *argument)
{
	if (ft_strequ("-c", opt) || ft_strequ("--configuration", opt))
		g_denv.opt.str[CONFIGURATION] = argument;
	else if (ft_strequ("-u", opt) || ft_strequ("--user", opt))
		g_denv.opt.str[USER] = argument;
	else if (ft_strequ("-d", opt) || ft_strequ("--directory", opt))
		g_denv.opt.str[DIRECTORY] = argument;
	else if (ft_strequ("-l", opt) || ft_strequ("--logfile", opt))
		g_denv.opt.str[LOGFILE] = argument;
	else if (ft_strequ("-e", opt) || ft_strequ("--loglevel", opt))
		g_denv.opt.str[LOGLEVEL] = argument;
	else if (ft_strequ("-q", opt) || ft_strequ("--childlogdir", opt))
		g_denv.opt.str[CHILDLOGDIR] = argument;
}

static int dependentOp(char **av, int *i)
{
	char *opts[] = {"-c", "--configuration",
					"-u", "--user",
					"-d", "--directory",
					"-l", "--logfile",
					"-e", "--loglevel",
					"-q", "--childlogdir",
					NULL};
	int j;

	j = -1;
	while (opts[++j])
	{
		if (ft_strequ(opts[j], av[*i]))
		{
			if (av[*i + 1])
			{
				getRequiredArgument(av[*i], av[*i + 1]);
				(*i)++;
				return (1);
			}
			else
			{
				error_requireArgument(av[*i]);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}

static int independentOp(char *av)
{
	char *opts[] = {"-h", "--help",
					"-n", "--nodaemon", NULL};
	int i;

	i = -1;
	while (opts[++i])
	{
		if (ft_strequ(opts[i], av))
		{
			if (i == 0 || i == 1)
			{
				printHelp();
				exit(EXIT_SUCCESS);
			}
			else
				return (1); // need to add nodaemon
		}
	}
	return (0);
}

void parseCommandLine(int ac, char **av)
{
	int i;

	i = -1;
	while (++i < ac)
	{
		if(av[i][0] == '-' && av[i][1])
		{
			if (!independentOp(av[i]) && !dependentOp(av, &i))
			{
				error_notRecognized(av[i]);
				exit(EXIT_FAILURE);
			}
		}
		else 
		{
			error_notSupported(&av[i]);
			exit(EXIT_FAILURE);
		}
	}
}
