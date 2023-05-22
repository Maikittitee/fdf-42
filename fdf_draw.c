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

void	bresenham(t_fdf *fdf, t_point s_pnt, t_point e_pnt)
{
	t_img img;
	t_draw draw;
	int	color = 0xFF0000;
	float max;


	// if (s_pnt.y < map->height && s_pnt.x < map->width)
	// 	draw.z = (map->z_metric)[(int)s_pnt.y][(int)s_pnt.x];
	// else
	// 	draw.z = 0;

	// if (s_pnt.z == 0)
	// 	color = rgb_to_int(1,1,1);
	// else
	// 	color = rgb_to_int(1,0,0);

	s_pnt.x *= fdf->zoom;
	s_pnt.y *= fdf->zoom;
	e_pnt.x *= fdf->zoom;
	e_pnt.y *= fdf->zoom;

	draw.dx = (e_pnt.x - s_pnt.x);
	draw.dy = (e_pnt.y - s_pnt.y);

	max = ft_max(ft_abs(draw.dx), ft_abs(draw.dy));

	draw.dx /= max;
	draw.dy /= max;

	char *buffer = mlx_get_data_addr(fdf->img_p, &(img.pixel_bits), &(img.line_bytes), &(img.endian));	

	while ( (int)(s_pnt.x - e_pnt.x) || (int)(s_pnt.y - e_pnt.y))
	{
		int pixel = ((int)s_pnt.y * img.line_bytes) + ((int)s_pnt.x * 4);

		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
		printf("Start point x0:%.2f | y0:%.2f\nEnd point x1:%.2f, y1:%.2f\nStep x:%.2f, Step_y:%.2f\n",s_pnt.x,s_pnt.y,e_pnt.x,e_pnt.y,draw.dx, draw.dy);
		s_pnt.x += draw.dx;
		s_pnt.y += draw.dy;
	}
}

void	draw_from_metric(t_map *map, t_fdf *fdf)
{
	t_point pnt;

	pnt.y = 0;
	while (pnt.y <= map->height)
	{
		pnt.x = 0;
		while (pnt.x <= map->width)
		{
			// if (pnt.y < map->height && pnt.x < map->width)
			// 	pnt.z = (map->z_metric)[(int)pnt.y][(int)pnt.x];
			// else
			// 	pnt.z = 0;
			// rotate_z(&pnt, pnt.z, 0);
			if (pnt.x == map->width && pnt.y == map->height)
				return ;
			if (pnt.x < map->width || pnt.y == map->height)
				bresenham(fdf, pnt, (t_point){pnt.x + 1, pnt.y});
			if (pnt.y < map->height || pnt.x == map->width)
				bresenham(fdf, pnt, (t_point){pnt.x, pnt.y + 1});
			pnt.x++;
		}
		pnt.y++;
	}
}