/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_config_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 02:02:03 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 02:02:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

void loadConfigFile(void)
{
	g_denv.dict = iniparser_load(g_denv.opt.str[CONFIGURATION]);
	if (g_denv.dict == NULL)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
}
