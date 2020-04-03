/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:25:10 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 02:25:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_cmd(char **tokens)
{
	int i;

	(void)tokens;
	i = -1;
	while (env[++i])
	{
		ft_putstr(env[i]);
		ft_putchar('\n');
	}
}
