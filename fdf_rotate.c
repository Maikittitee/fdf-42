/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:33:52 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/26 02:04:41 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_point *old_point, t_point *new_point, float theta)
{

	new_point->x = (old_point->x * cos(theta)) + (old_point->y * sin(theta));
	new_point->y = (old_point->y * cos(theta)) - (old_point->x * sin(theta)) - old_point->z ; //del temp z

}

void	apply_iso(t_map *old_map_data, t_map *new_map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < old_map_data->height)
	{
		j = 0;
		while (j < old_map_data->width)
		{
			rotate_z(&(old_map_data->map)[i][j], &(new_map_data->map)[i][j], old_map_data->theta);
			(new_map_data->map)[i][j].z = (old_map_data->map)[i][j].z;
			(new_map_data->map)[i][j].color = (old_map_data->map)[i][j].color;
			j++;
		}		
		i++;
	}
	
}

void	apply_difference(t_map *old_map_data, t_map *new_map_data)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	i = 0;
	while (i < new_map_data->height)
	{
		j = 0;
		while (j < new_map_data->width)
		{
			dx = (new_map_data->map)[i][j].x - (old_map_data->map)[i][j].x;
			dy = (new_map_data->map)[i][j].y - (old_map_data->map)[i][j].y;
			(new_map_data->map)[i][j].x -= dx;
			(new_map_data->map)[i][j].y -= dy;
			j++;
		}
		i++;
	}
}
