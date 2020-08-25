/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_config_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 02:09:14 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 02:59:38 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

void print_program(t_program pro)
{
	ft_printf("name: %s\n", pro.name);
	ft_printf("command: %s\n", pro.command);
	ft_printf("numprocs: %d\n", pro.numprocs);
	ft_printf("autostart: %d\n", pro.autostart);
	ft_printf("autorestart: %d\n", pro.autorestart);
	ft_printf("startsecs: %d\n", pro.startsecs);
	ft_printf("startretries: %d\n", pro.startretries);
	ft_printf("stopwaitsecs: %d\n", pro.stopwaitsecs);
	ft_printf("stopsignal: %s\n", pro.stopsignal);
	ft_printf("directory: %s\n", pro.directory);
	ft_printf("stdout_logfile: %s\n", pro.stdout_logfile);
	ft_printf("stderr_logfile: %s\n", pro.stderr_logfile);
	ft_printf("umask: %d\n", pro.umask);
}
