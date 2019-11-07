/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 00:37:25 by dthan             #+#    #+#             */
/*   Updated: 2019/11/06 22:46:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	int	linenbr;

	linenbr = 0;
	if (argc == 2)
	{
		fd = open(argv[1], ORDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("Return: %d, Line #%d: %s\n", ret, linenbr++, line);
			free(line);
		}
		printf("Return: %d, Line #%d: %s\n", ret, linenbr++, line);
		if (ret == -1)
			printf("--------------\nError\n");
		else if (ret == 0)
			printf("--------------\nEnd of File\n");
		close(fd);
	}
	if (argc == 1)
	{
		while((ret = get_next_line(0, &line)) > 0)
			printf("[Return: %d] Line#%d: %s\n", ret, line++, line);
		if (ret == -1)
			printf("--------------\nError\n");
		else if (ret == 0)
			printf("--------------\nEnd of File\n");
		close(fd);
	}
	return (0);
}
