/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:17:35 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/26 01:51:34 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_rheight(t_map *map_data)
{
	return (map_data->height * sin(map_data->theta) + map_data->width * cos(map_data->theta));
}	

int get_rwidth(t_map *map_data)
{
	return (map_data->height * cos(map_data->theta) + map_data->width * sin(map_data->theta));
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
			printf("H: %d, W: %d\n", r_height, r_width);
	(map_data->map)[5][9].color = rgb_to_int(0,1,0);
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			// (map_data->map)[i][j].x += ((WIN_WIDTH / 2)) ;
			// (map_data->map)[i][j].y += ((WIN_HEIGHT / 2));
			(map_data->map)[i][j].x += ((WIN_WIDTH / 2) - (map_data->width * (map_data->ratio/ 2))) ;
			(map_data->map)[i][j].y += ((WIN_HEIGHT /2) - (map_data->height * (map_data->ratio/ 2) ));
			// printf("%d %d %f %f\n", i, j, (map_data->map)[i][j].x, (map_data->map)[i][j].y);
			
			j++;
            
		}		
		i++;
	}
	
}
// void get_center(t_map *map_data)
// {
   
// }