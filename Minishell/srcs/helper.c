/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 03:08:48 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 03:08:49 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_fork(char *path, char **arguments)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(path, arguments, env); // execve(argment[0], arguments, env);
	else if (pid < 0)
		ft_printf("can not fork\n");
	wait(&pid);
}
