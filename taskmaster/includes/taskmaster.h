/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskmaster.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:46:05 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 03:41:20 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASKMASTER_H
# define TASKMASTER_H
# include "../libft/includes/libft.h"
# include "../iniparser/src/iniparser.h"
# include "../iniparser/src/dictionary.h"
# include <sys/un.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/file.h>
# include <sys/stat.h>
# include <signal.h>
# include <assert.h>
# include <ftw.h>
# include <stdbool.h>

/*
********************EXIT ROUTINE
*/

# define NO_MSG			0x00
# define EXIT_EOF		0x01
# define ERR			0x02

/*
********************OPTIONS & INI
*/

# define NO_OPT				0x000
# define OPT_HELP			0x001
# define OPT_NODAEMON		0x002
# define OPT_VERSION		0x004
# define OPT_CONFIG			0x008
# define OPT_USER			0x010
# define OPT_DIRECTORY		0x020
# define OPT_LOGFILE		0x040
# define OPT_LOGLVL			0x080
# define OPT_CHILDLOGDIR	0x010

# define NB_OPT				22
# define OPT_WITHOUT_ARG	6

# define CONFIGURATION	0
# define USER			1
# define DIRECTORY		2
# define LOGFILE		3
# define LOGLEVEL		4
# define CHILDLOGDIR	5

# define unexpected 2
/*
*******************DEFAULT-SETUP***********************
*/
// # define DEFAULT_CONFIGURATION	"/tmp/taskmaster.d/taskmasterd.conf"
# define DEFAULT_CONFIGURATION "/home/dthan/Projects/homegit/taskmaster/testfile/basic.conf"
// # define DEFAULT_LOGFILE		"/tmp/taskmaster.d/taskmaster.log"
# define DEFAULT_LOGFILE		"/home/dthan/Projects/homegit/taskmaster/log/taskmaster.log"
# define DEFAULT_LOGLVL			"info"
# define DEFAULT_CHILDLOGDIR	"/tmp/taskmaster.d/childlog"

# define DEFAULT_WORKDIR		"/tmp/taskmaster.d/"
# define DEFAULT_SOCKET			"/tmp/taskmaster.d/taskmasterd.sock"
# define DEFAULT_LOCK			"/tmp/taskmaster.d/taskmasterd.lock"

# define DEFAULT_UMASK			022

/*
**********************NETWORKING***********************
*/

# define MAX_CLIENT 1

/*
*******************************************************
*/

typedef struct					s_options
{
	uint64_t					optmask;
	mode_t						umask;
	uint32_t					padding;
	char						*str[8];
	char						*environ;
}								t_options;

typedef struct		s_program
{
	char			*name;
	char			*command;
	int				numprocs;
	int				piority;
	int			autostart;
	int				startsecs;
	int				startretries;
	int			autorestart;
	int				exitcodes;
	char				*stopsignal;
	int				stopwaitsecs;
	char			*user; // not used yet
	char			*stdout_logfile;
	char			*stderr_logfile;
	char			*directory;
	int				umask;
}					t_program;

typedef struct		s_denv
{
	int				sig_tmp;
	volatile __sig_atomic_t		sigint;
	char						*dfl_socket;
	int						unix_socket;
	int32_t						log_fd;
	t_list						*environ;
	t_list						*prgm_list;
	dictionary					*dict;
	t_options					opt;
	struct sockaddr			*addr;
	uint8_t						client_connected;
	int8_t						lock;
	uint8_t						shutdown;
	char						pad[7];
	char						**env;
	char					**av;
	int							ac;
	char						padd[4];
}								t_denv;

#endif