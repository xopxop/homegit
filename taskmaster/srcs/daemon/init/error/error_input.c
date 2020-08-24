/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 02:10:40 by dthan             #+#    #+#             */
/*   Updated: 2020/08/20 02:12:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

void error_requireArgument(char *av)
{
	ft_putstr_fd("Error: option ", STDERR_FILENO);
	ft_putstr_fd(av, STDERR_FILENO);
	ft_putstr_fd(" requires argument\nFor help, use taskmaster -h\n", STDERR_FILENO);
}

void error_notRecognized(char *av)
{
	ft_putstr_fd("Error: option ", STDERR_FILENO);
	ft_putstr_fd(av, STDERR_FILENO);
	ft_putstr_fd(" not recognized\nFor help, use taskmaster -h\n", STDERR_FILENO);
}

void error_notSupported(char **av)
{
	int i;
	i = -1;
	
	ft_putstr_fd("Error: positional arguments are not supported: [", STDERR_FILENO);
	while (av[++i])
	{
		if (i > 0)
			ft_putstr_fd(", ", STDERR_FILENO);
		ft_dprintf(STDERR_FILENO, "'%s'", av[i]);
	}
	ft_putstr_fd("]\nFor help, use taskmaster -h\n", STDERR_FILENO);
}
