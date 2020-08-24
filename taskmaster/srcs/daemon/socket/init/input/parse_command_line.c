/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 02:04:31 by dthan             #+#    #+#             */
/*   Updated: 2020/08/20 02:11:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

void getRequiredArgument(char *opt, char *argument)
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

int dependentOp(char **av, int *i)
{
	char *opts[] = {"-c", "--configuration",
					"-u", "--user",
					"-d", "--directory",
					"-l", "--logfile",
					"-e", "--loglevel",
					"-q", "--childlogdir"};
	int j;

	j = -1;
	while (opts[++j])
	{
		if (ft_strequ(opts[j], av[*i]))
		{
			if (av[*i + 1])
			{
				getRequiredArgument(av[*i], av[*i + 1]);
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

int independentOp(char *av)
{
	char *opts[] = {"-h", "--help"
					"-n", "--nodaemon"};
	int i;

	i = -1;
	while (opts[++i])
		if (ft_strequ(opts[i], av)); // missing here
			return (1);
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
