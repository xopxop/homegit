/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 03:06:58 by dthan             #+#    #+#             */
/*   Updated: 2020/09/15 17:15:22 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

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
