/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daemon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:51:57 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 03:02:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAEMON_H
# define DAEMON_H
# include "../libft/includes/libft.h"
# include "taskmaster.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <sys/socket.h>
# include <signal.h>
# include <string.h>
# include <syslog.h>

t_denv g_denv;
//--------------init/input
//set_default.c
void initDefaultState(int ac, char **av, char **env);
//parse_command_line.c
void parseCommandLine(int ac, char **av);
//--------------init/error
//error_input.c
void error_requireArgument(char *av);
void error_notRecognized(char *av);
void error_notSupported(char **av);
//--------------init/config_file
//load_config_file.c
void loadConfigFile(void);
//collect_info_from_config_file.c
void getSection(void);
//-------------init/debug
//for_config_file.c
void print_program(t_program pro);
//for_init_input.c
void printState(void);
//-------------init/signal
void initSignal(void);
//-------------init/daemon
//daemon_builder.c
void	creatDaemon(void);
#endif
