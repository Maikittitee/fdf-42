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

void	ft_dda(t_fdf *fdf, t_point s_pnt, t_point e_pnt)
{
	t_img img;
	t_draw draw;
	// int	color = 0xFF0000;
	float max;


	// if (s_pnt.y < map->height && s_pnt.x < map->width)
	// 	draw.z = (map->z_metric)[(int)s_pnt.y][(int)s_pnt.x];
	// else
	// 	draw.z = 0;

	// if (s_pnt.z == 0)
	// 	color = rgb_to_int(1,1,1);
	// else
	// 	color = rgb_to_int(1,0,0);

	// s_pnt.x *= fdf->zoom;
	// s_pnt.y *= fdf->zoom;
	// e_pnt.x *= fdf->zoom;
	// e_pnt.y *= fdf->zoom;

	draw.dx = (e_pnt.x - s_pnt.x);
	draw.dy = (e_pnt.y - s_pnt.y);

	max = ft_max(ft_abs(draw.dx), ft_abs(draw.dy));

	// printf("Start point x0:%.2f | y0:%.2f\nEnd point x1:%.2f, y1:%.2f\n",s_pnt.x,s_pnt.y,e_pnt.x, e_pnt.y);
	// printf("dx %f",draw.dx);
	// printf("| dy %f\n",draw.dy);
	// printf("abs x %f",ft_abs(draw.dx));
	// printf("| abs y %f\n",ft_abs(draw.dy));
	draw.dx /= max;
	draw.dy /= max;

	// printf("max is %f\n", max);	
	char *buffer = mlx_get_data_addr(fdf->img_p, &(img.pixel_bits), &(img.line_bytes), &(img.endian));	

	float	i = 0;
	// while ( (int)(s_pnt.x - e_pnt.x) || (int)(s_pnt.y - e_pnt.y))
	while (i < max)
	{
		int pixel = ((int)s_pnt.y * img.line_bytes) + ((int)s_pnt.x * 4);

		buffer[pixel + 0] = (s_pnt.color) & 0xFF;
		buffer[pixel + 1] = (s_pnt.color >> 8) & 0xFF;
		buffer[pixel + 2] = (s_pnt.color >> 16) & 0xFF;
		buffer[pixel + 3] = (s_pnt.color >> 24);

		// printf("Start point x0:%.2f | y0:%.2f\nEnd point x1:%.2f, y1:%.2f\nStep x:%.2f, Step_y:%.2f\n",s_pnt.x,s_pnt.y,e_pnt.x,e_pnt.y,draw.dx, draw.dy);
		s_pnt.x += draw.dx;
		s_pnt.y += draw.dy;
		i ++;
	}
	// printf("--------------\n");
}

void	draw_from_metric(t_map *map_data, t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			// if (pnt.y < map_data->height && pnt.x < map_data->width)
			// 	pnt.z = (map_data->z_metric)[(int)pnt.y][(int)pnt.x];
			// else
			// 	pnt.z = 0;
			// rotate_z(&pnt, pnt.z, 0);
			if (j == map_data->width - 1 && i == map_data->height - 1)
				return ;
			if (j < map_data->width - 1 || i == map_data->height)
				ft_dda(fdf, map_data->map[i][j], map_data->map[i][j + 1]);
			if (i < map_data->height - 1 || j == map_data->width)
				ft_dda(fdf, map_data->map[i][j], map_data->map[i + 1][j]);
			j++;
		}
		i++;
	}
}