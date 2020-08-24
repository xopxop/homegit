/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_socket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 01:54:59 by dthan             #+#    #+#             */
/*   Updated: 2020/08/20 01:58:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/daemon.h"

int socketCreation(void)
{
	// creating socket fd
	int server_fd;

	server_fd = socket(PF_UNIX, SOCK_STREAM, 0);
	if (server_fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	// do sth here too
	return (server_fd);
}

void	bindSocket(int server_fd, struct sockaddr *addr)
{
	if ((bind(server_fd, addr, sizeof(addr))) == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
}

void	socketListen(int server_fd)
{
	if ((listen(server_fd, MAX_CLIENT)) == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
}

void initSocket(void)
{
	g_denv.unix_socket = socketCreation();
	bindSocket(g_denv.unix_socket, g_denv.addr);
	socketListen(g_denv.unix_socket);
}
