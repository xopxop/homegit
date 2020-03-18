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
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

int error_handle(char* reason)
{
	ft_putendl(reason);
	return (1);
}

int main(int ac, char **av)
{
//	void *mlx_ptr;
//	void *win_ptr;
	t_map map;
	int fd;

	if (ac < 2)
		return (error_handle("Error"));
	//open file, no need to close because the mlx_loop is an infinite loop
	fd = open(av[1], O_RDONLY);
	if(fd < 0 || read_file(fd, &map))
		return (error_handle("ERROR"));
//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, ft_strjoin("FDF - ", av[1]));
//	drawingline();
//	mlx_key_hook(int keycode, void *param);
//	mlx_mouse_hook(int button, int x, int y, void *param)
//	mlx_loop(mlx_ptr);
}


/*
** param is the address specified in the mlx_*_hook calls. This adress is never used nor
** modified by the MiniLibx. On the key and mouse events, additional information is passed:
** keycode tells you which key is pressed (look for the X11 include file keysymdef.h),
** x, y are the coordinates of the mouse clock in the window, adn button tells you which mouse
** button was pressed
*/