/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:29:15 by dthan             #+#    #+#             */
/*   Updated: 2019/10/16 10:10:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display(char *filename)
{
	int		file;
	char	c;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return ;
	while (read(file, &c, 1))
		write(1, &c, 1);
	close(file);
}

int		main(int argc, char *argv[])
{
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		display(argv[1]);
	return (0);
}
