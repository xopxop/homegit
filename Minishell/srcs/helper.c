/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 03:08:48 by dthan             #+#    #+#             */
/*   Updated: 2020/07/12 18:34:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_fork(char *path, char **arguments)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(path, arguments, env); // execve(argment[0], arguments, env);
	else if (pid < 0)
		ft_printf("can not fork\n");
	wait(&pid);
	return (EXIT_SUCCESS);
}
