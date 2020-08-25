/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_init_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 03:04:38 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 03:05:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

void printState(void)
{
	ft_printf("----------------------");
	ft_printf("g_denv.opt.str[CONFIGURATION] = %s\n", g_denv.opt.str[CONFIGURATION]);
	ft_printf("g_denv.opt.str[USER] = %s\n", g_denv.opt.str[USER]);
	ft_printf("g_denv.opt.str[DIRECTORY] = %s\n", g_denv.opt.str[DIRECTORY]);
	ft_printf("g_denv.opt.str[LOGFILE] = %s\n", g_denv.opt.str[LOGFILE]);
	ft_printf("g_denv.opt.str[LOGLEVEL] = %s\n", g_denv.opt.str[LOGLEVEL]);
	ft_printf("g_denv.opt.str[CHILDLOGDIR] = %s\n", g_denv.opt.str[CHILDLOGDIR]);
	ft_printf("g_denv.opt.umask = %d\n", g_denv.opt.umask);
	ft_printf("----------------------");
}
