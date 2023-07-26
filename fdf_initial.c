/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:17:35 by ktunchar          #+#    #+#             */
/*   Updated: 2023/07/26 15:11:04 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_max_z(t_map *map_data)
{
	int		i;
	int		j;
	float	max;

	i = 0;
	max = map_data->map[i][0].z;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			if (map_data->map[i][j].z > max)
				max = map_data->map[i][j].z;
			j++;
		}
		i++;
	}
	return (max);
}

int	get_rheight(t_map *map_data)
{
	return (ft_abs(map_data->height * cos(map_data->theta)) + \
		ft_abs(map_data->width * cos(map_data->theta)));
}	

int	get_rwidth(t_map *map_data)
{
	return (ft_abs(map_data->height * sin(map_data->theta)) + \
		ft_abs(map_data->width * sin(map_data->theta)));
}	

void	apply_start_pnt(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			(map_data->map)[i][j].y += ((WIN_HEIGHT / 2) - \
			(get_rheight(map_data) / 4 * map_data->ratio));
			(map_data->map)[i][j].x += ((WIN_WIDTH / 2) - \
			((get_rwidth(map_data) - map_data->height * cos(map_data->theta)) \
			/ 4 * map_data->ratio));
			j++;
		}		
		i++;
	}
}

float	get_ratio(t_map *map_data)
{
	float	x_ratio;
	float	y_ratio;
	float	ratio;

	x_ratio = floor(WIN_WIDTH / (get_rwidth(map_data)));
	y_ratio = floor(WIN_HEIGHT / (get_rheight(map_data) + \
		(get_max_z(map_data) * MAGIC_Z * 2)));
	if (x_ratio > y_ratio)
		ratio = y_ratio;
	else
		ratio = x_ratio;
	if (ratio > 180)
	{
		ft_putendl_fd("OVERFLOW", 1);
		exit(1);
	}
	// if (ratio <= 0)
	// 	return (1 / (get_max_z(map_data) * MAGIC_Z));
	if (ratio <= 1)
		return (1.2);
	return (ratio);
}
