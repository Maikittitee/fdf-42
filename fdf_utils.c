/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:33:01 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/23 13:56:59 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_double_free(char **s)
{
	int	i;

	i = 0;
	while  (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free_map(t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->height)
	{
		if ((map_data->map)[i])
			free((map_data->map)[i]);
		i++;
	}
	free (map_data->map);
	free (map_data);
}

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}