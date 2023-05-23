/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:33:52 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/23 15:36:51 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_point *point, float theta)
{
	t_point	temp;

	temp = *point;
	point->x = (temp.x * cos(theta)) + (temp.y * sin(theta));
	point->y = (temp.y * cos(theta)) - (temp.x * sin(theta)) - temp.z;

}

void	apply_iso(t_map *map_data, float theta)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			rotate_z(&(map_data->map)[i][j], theta);
			j++;
		}		
		i++;
	}
	
}
