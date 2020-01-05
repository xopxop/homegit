# include "mlx.h"
#include <stdlib.h>

# define WIDTH 1000
# define HEIGHT 600

typedef struct			s_env
{
	void			*mlx;
	void			*win;
	int			step_x;
	int			step_y;
	int			dx;
	int			dy;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			line_color;
}				t_env;

/* if dy <= dx */
static	void		ft_draw_dx(t_env *e)
{
	int	error;
	int	i;
	int	x;
	int	y;

	error = (e->dy << 1) - e->dx;
	x = e->x0 + e->step_x;
	y = e->y0;
	i = 1;
	mlx_pixel_put(e->mlx, e->win, e->x0, e->y0, e->line_color);
	while (i <= e->dx)
	{
		if (error > 0)
		{
			y += e->step_y;
			error += (e->dy - e->dx) << 1;
		}
		else
			error += e->dy << 1;
		mlx_pixel_put(e->mlx, e->win, x, y, e->line_color);
		x += e->step_x;
		i++;
	}
}

/* if dy >= dx */
static	void		ft_draw_dy(t_env *e)
{
	int	error;
	int	i;
	int	x;
	int	y;

	error = (e->dx << 1) - e->dy;
	y = e->y0 + e->step_y;
	x = e->x0;
	i = 1;
	mlx_pixel_put(e->mlx, e->win, e->x0, e->y0, e->line_color);
	while (i <= e->dy)
	{
		if (error > 0)
		{
			error += (e->dx - e->dy) << 1;
			x += e->step_x;
		}
		else
			error += e->dx << 1;
		mlx_pixel_put(e->mlx, e->win, x, y, e->line_color);
		y += e->step_y;
		i++;
	}
}

/* making a decision: deltaX > deltaY || deltaX > deltaY */
/* also we should figure out the value of step (1 or -1) */
void				bresenham_line(t_env *e)
{
	e->dx = abs(e->x1 - e->x0); /* delta x */
	e->dy = abs(e->y1 - e->y0); /* delta y */
	e->step_x = e->x1 >= e->x0 ? 1 : -1; /* stepx if line (from left to right) = +1 ; else = -1 */
	e->step_y = e->y1 >= e->y0 ? 1 : -1; /* stepy if line (from up to down) = +1 ; else = -1 */
	if (e->dx > e->dy)
		ft_draw_dx(e);
	else
		ft_draw_dy(e);
}

int			main(void)
{
	int 	color;
	t_env 	*e;

	if (!(e = malloc(sizeof(t_env))))
		return (0);
	color = 8388352;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");
	e->x0 = 0;
	e->x1 = WIDTH;
	e->y0 = 0;
	e->y1 = HEIGHT;
	e->line_color = 8388352;
	bresenham_line(e);
	mlx_loop(e->mlx);
	free(e);
	return (0);
}