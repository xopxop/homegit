/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 02:04:31 by dthan             #+#    #+#             */
/*   Updated: 2020/08/20 02:05:02 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

void parseCommandLine(int ac, char **av)
{
	int i;

	i = -1;
	while (++i < ac)
	{
		if(av[i][0] == '-' && av[i][1])
		{
			if (!independentOp(av[i]) && !dependentOp(av, &i))
			{
				error_notRecognized(av[i]);
				exit(EXIT_FAILURE);
			}
		}
		else 
		{
			error_notSupported(&av[i]);
			exit(EXIT_FAILURE);
		}
	}
}
