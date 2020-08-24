/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daemon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:51:57 by dthan             #+#    #+#             */
/*   Updated: 2020/08/19 12:28:29 by dthan            ###   ########.fr       */
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

t_denv g_denv;

#endif
