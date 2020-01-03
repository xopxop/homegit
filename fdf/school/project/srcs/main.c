/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:35:38 by dthan             #+#    #+#             */
/*   Updated: 2020/01/03 15:41:20 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int error_handle(char* reason)
{
	ft_putendl(reason);
	return (1);
}

int main(int ac, char **av)
{
	void *mlx_ptr;
	void *win_ptr;
	int fd;

	if (ac < 2)
		return (error_handle("Error"));
	//open file, no need to close because the mlx_loop is an infinite loop
	fd = open(av[1], O_RDONLY);
	if(fd < 0 || !read_file(fd, &map))
		return (error_handle("ERROR"));
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}
