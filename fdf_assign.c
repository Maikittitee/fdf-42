/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_assign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:52:36 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/28 02:26:36 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_xy(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	map_data->map = malloc(sizeof(t_point *) * map_data->height);
	while (i < map_data->height)
	{
		j = 0;
		(map_data->map)[i] = malloc(sizeof(t_point) * map_data->width);
		while (j < map_data->width)
		{
			(map_data->map)[i][j].x = j;
			(map_data->map)[i][j].y = i;
			j++;
		}
		i++;
	}
}

void	apply_ratio(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			(map_data->map)[i][j].x *= map_data->ratio;
			(map_data->map)[i][j].y *= map_data->ratio;
			(map_data->map)[i][j].z *= map_data->ratio * 0.17;
			j++;
		}
		i++;
	}	
}

int	get_color(float z, char **value)
{
	if (value && value[1])
		return (str_hex_to_int(value[1]));
	else if (z != 0)
		return (0xFF0000);
	else
		return (0xFFFFFF);
}

void	apply_to_each_point(char *line, t_map *map_data, int i)
{
	int		j;
	char	**each_point;
	char	**value;

	j = 0;
	each_point = ft_split(line, ' ');
	while (j < map_data->width && each_point[j])
	{
		value = ft_split(each_point[j], ',');
		is_format_error(value);
		if (value && value[0])
			map_data->map[i][j].z = ft_atoi(value[0]);
		map_data->map[i][j].color = get_color(map_data->map[i][j].z, value);
		ft_double_free(value);
		j++;
	}
	ft_double_free(each_point);
}

void	assign_z_color(char *filename, t_map *map_data)
{
	int		fd;
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	fd = open(filename, O_RDONLY);
	temp = get_next_line(fd);
	line = ft_strtrim(temp, "\n");
	free(temp);
	while (line)
	{
		apply_to_each_point(line, map_data, i);
		free(line);
		temp = get_next_line(fd);
		line = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
}
