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

void	bresenham(t_map *map,t_fdf *fdf, float x0, float y0, float x1, float y1)
{
	float step_x;
	float	step_y;
	float	delta_x;
	float	delta_y;
	int	color;
	int	z;

	if (y0 < map->height && x0 < map->width)
		z = (map->z_metric)[(int)y0][(int)x0];
	else
		z = 0;

	if (z == 0)
		color = rgb_to_int(1,1,1);
	else
		color = rgb_to_int(1,0,0);

	x0 *= fdf->zoom;
	y0 *= fdf->zoom;
	x1 *= fdf->zoom;
	y1 *= fdf->zoom;

	// rotateZ((float *)&x0, (float *)&y0, z, 0.8);
	// rotateZ((float *)&x1, (float *)&y1, z, 0.8);
	delta_x = (x1 - x0);
	delta_y = (y1 - y0);

	step_x = delta_x/ft_max(ft_abs(delta_x), ft_abs(delta_y));
	step_y = delta_y/ft_max(ft_abs(delta_x), ft_abs(delta_y));

	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(fdf->img_p, &pixel_bits, &line_bytes, &endian);	

	while ( (int)(x1 - x0) || (int)(y1 - y0))
	{
		int pixel = (y0 * line_bytes) + (x0 * 4);

		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
		printf("End point x0:%.2f, y0:%.2f\nEnd point x1:%.2f, y1:%.2f\nStep x:%.2f, Step_y:%.2f\n",x0,y0,x1,y1,step_x, step_y);
		x0 += step_x;
		y0 += step_y;
	}
}

void	draw_from_metric(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y <= map->height)
	{
		x = 0;
		while (x <= map->width)
		{
			if (x == map->width && y == map->height)
				return ;
			if (x < map->width || y == map->height)
				bresenham(map, fdf, x, y, x + 1, y);
			if (y < map->height || x == map->width)
				 bresenham(map, fdf,x, y, x, y + 1);
			x++;
		}
		y++;
	}
}