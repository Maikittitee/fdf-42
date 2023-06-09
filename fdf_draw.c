/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:01:05 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/27 21:02:26 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	put_to_img(char *buffer, t_img img, t_point pnt)
{
	int	pixel;

	pixel = ((int)pnt.y * img.line_bytes) + ((int)pnt.x * 4);
	buffer[pixel + 0] = (pnt.color) & 0xFF;
	buffer[pixel + 1] = (pnt.color >> 8) & 0xFF;
	buffer[pixel + 2] = (pnt.color >> 16) & 0xFF;
	buffer[pixel + 3] = (pnt.color >> 24);
}

void	ft_dda(t_fdf *fdf, t_point s_pnt, t_point e_pnt)
{
	t_img	img;
	t_draw	draw;
	float	max;
	char	*buffer;

	draw.dx = (e_pnt.x - s_pnt.x);
	draw.dy = (e_pnt.y - s_pnt.y);
	max = ft_max(ft_abs(draw.dx), ft_abs(draw.dy));
	draw.dx /= max;
	draw.dy /= max;
	buffer = mlx_get_data_addr(fdf->img_p, &(img.pixel_bits), \
			&(img.line_bytes), &(img.endian));
	while ((int)(s_pnt.x - e_pnt.x) || (int)(s_pnt.y - e_pnt.y))
	{
		if (s_pnt.x + draw.dx < WIN_WIDTH && s_pnt.y + draw.dy < WIN_HEIGHT)
			put_to_img(buffer, img, s_pnt);
		s_pnt.x += draw.dx;
		s_pnt.y += draw.dy;
	}
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
