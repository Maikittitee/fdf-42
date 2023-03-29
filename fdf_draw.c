#include "fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}
void	bresenham(t_magic *data, float x0, float y0, float x1, float y1)
{
	float step_x;
	float	step_y;
	float	delta_x;
	float	delta_y;

	delta_x = (x1 - x0);
	delta_y = (y1 - y0);
	step_x = delta_x/ft_max(ft_abs(delta_x),ft_abs(delta_y));
	step_y = delta_y/ft_max(ft_abs(delta_x),ft_abs(delta_y));
	// step_x = delta_x/;
	// step_y = delta_y/10000;

	while (x0 <= x1 && y0 <= y1)
	{
		mlx_pixel_put(data->mlx, data->win, x0, y0,rgb_to_int(1,1,1));
		printf("End point x0:%.2f, y0:%.2f\n",x0,y0);
		x0 += step_x;
		y0 += step_y;
	}
}

// void	draw_from_metric(t_magic data, )