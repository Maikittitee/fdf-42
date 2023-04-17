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
	int	color;
	int	z;

	if (y0 < data->height && x0 < data->width)
		z = (data->z_metric)[(int)y0][(int)x0];
	else
		z = 0;

	if (z == 0)
		color = rgb_to_int(1,1,1);
	else
		color = rgb_to_int(1,0,0);

	x0 *= data->zoom;
	y0 *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	// rotateZ((float *)&x0, (float *)&y0, z, 0.8);
	// rotateZ((float *)&x1, (float *)&y1, z, 0.8);
	delta_x = (x1 - x0);
	delta_y = (y1 - y0);

	step_x = delta_x/ft_max(ft_abs(delta_x), ft_abs(delta_y));
	step_y = delta_y/ft_max(ft_abs(delta_x), ft_abs(delta_y));

	while ( (int)(x1 - x0)|| (int)(y1 - y0))
	{
		mlx_pixel_put(data->mlx, data->win, x0, y0, color);
		printf("End point x0:%.2f, y0:%.2f\nEnd point x1:%.2f, y1:%.2f\nStep x:%.2f, Step_y:%.2f\n",x0,y0,x1,y1,step_x, step_y);
		x0 += step_x;
		y0 += step_y;
	}
}

void	draw_from_metric(t_magic *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= data->height)
	{
		x = 0;
		while (x <= data->width)
		{
			if (x == data->width && y == data->height)
				return ;
			if (x < data->width || y == data->height)
				bresenham(data, x, y, x + 1, y);
			if (y < data->height || x == data->width)
				 bresenham(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}