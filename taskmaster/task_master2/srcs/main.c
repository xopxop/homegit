/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:45:29 by dthan             #+#    #+#             */
/*   Updated: 2020/08/10 08:04:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/taskmaster.h"

void get_abs_path_name(t_vector *name)
{
	char	cwd[PATH_MAX];
	char	*path_name;

	if (name != NULL && name->str != NULL && name->str[0] != '/')
	{

	}
}

void init(int ac, char **av, char **environ)
{
	int i;

	ft_bzero(g_denv, sizeof(t_denv));
	g_denv->environ_tab = environ;
	g_denv->av = (t_vector **)malloc(sizeof(t_vector*) * (ac + 1));
	if (g_denv->av != NULL)
	{
		g_denv->av[ac] = NULL;
		i = 0;
		while (i < ac)
		{
			g_denv->av[i]->str = ft_strnew(av[i]);
			g_denv->av[i]->len = ft_strlen(av[i]);
			i++;
		}
		g_denv->av[i] = NULL;
		g_denv->ac = ac;
		get_abs_path_name(g_denv->av[0]);
	}
}

int	main(int ac, char **av, char **environ)
{
	t_denv env;

	g_denv = &env;
	g_tmpenv = NULL;
	init(ac, av, environ);
	return (EXIT_SUCCESS);
}
