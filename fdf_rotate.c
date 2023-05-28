/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:33:52 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/28 06:56:26 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_point *point, float theta)
{
	t_point	temp;

	temp = *point;
// 	point->x = (temp.x * cos(theta)) + (temp.y * sin(theta));
// 	point->y = (temp.y * cos(theta)) - (temp.x * sin(theta)) - temp.z;
	point->x = (temp.x - temp.y) * cos(theta);
	point->y = ((temp.y + temp.x) * sin(theta)) - temp.z;
	
}

void	apply_iso(t_map *old_map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < old_map_data->height)
	{
		j = 0;
		while (j < old_map_data->width)
		{
			rotate_z(&(old_map_data->map)[i][j], old_map_data->theta);
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
