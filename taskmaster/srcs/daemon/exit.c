/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:47:49 by dthan             #+#    #+#             */
/*   Updated: 2020/09/15 17:17:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/daemon.h"

void cleaner(void)
{
	close(g_denv.log_fd);
	close(g_denv.socketfd);
	//if dfl_socket != NULL
	unlink(DEFAULT_SOCKET);
}
