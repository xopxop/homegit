/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:59:02 by dthan             #+#    #+#             */
/*   Updated: 2020/01/04 17:59:39 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

/*
** Case 2: deltaY > deltaX
*/

void ft_draw_dy()
{
    int x;
    int y;
    int i;

    i = 0;
    x = point->x0
    y = point->y0 + step;
    mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color)
    while (i < dy)
    {
        mlx_pixel_put(mlx_ptr, wind_ptr, x, y, color);
        y += step;
        i++;
    }
}

/*
** Case 1: deltaX > deltaY
*/

void	ft_draw_dx(t_point *point)
{
    int x;
    int y;
    int i;

    i = 0;
    x = point->x + step_x;
    y = point->y;
    mlx_pixel_put(mlx_ptr, win_ptr, point->x, point->y, color);
    while(i <= point->dx)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
        x += step_x;
        i++;
    }
}
/*
** Case 1: deltaX(x1 - x0) > deltaY(y1 - y0)
** Case 2: deltaX(x1 - x0) < deltaY(y1 - y0)
*/

void bresenham_algorithm()
{
    int dx;
    int dy;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    if (dx > dy)
        case 1;
    else
        case 2;
}
