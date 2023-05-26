/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:17:35 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/27 00:34:49 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_rheight(t_map *map_data)
{
	return (ft_abs(map_data->height * sin(map_data->theta)) + ft_abs(map_data->width * cos(map_data->theta)));
	// return ((map_data->height + map_data->width) * cos(map_data->theta));
}	

int get_rwidth(t_map *map_data)
{
	return (ft_abs(map_data->height * cos(map_data->theta)) + ft_abs(map_data->width * sin(map_data->theta)));
	// return ((map_data->height + map_data->width) * sin(map_data->theta));
}	

void	apply_start_pnt(t_map *map_data)
{
	int	i;
	int	j;
	int	r_width;
	int r_height;

	i = 0;

	r_width = floor(get_rwidth(map_data));
	r_height = floor(get_rheight(map_data));
	printf("rotated_height:%d, rotated_width:%d\n", r_height, r_width);
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			(map_data->map)[i][j].x += (WIN_WIDTH / 2 - ((ft_abs(map_data->width * cos(map_data->theta)) - ft_abs(map_data->height * sin(map_data->theta)))) * map_data->ratio/ 2);
			(map_data->map)[i][j].y += (WIN_HEIGHT / 2 - (ft_abs((map_data->width * sin(map_data->theta))) * map_data->ratio));
			j++;
            
		}		
		i++;
	}
	
}
float get_ratio(t_map *map_data)
{
	float	x_ratio;
	float	y_ratio;
	float	ratio;

	x_ratio = WIN_WIDTH / get_rwidth(map_data) * 0.5;
	y_ratio = WIN_HEIGHT / get_rheight(map_data) * 0.5;
	if (x_ratio > y_ratio)
		ratio = y_ratio;
	else
		ratio = x_ratio;
	if (ratio == 0)
		return (0.5);
	return (ratio);
}