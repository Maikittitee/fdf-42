/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:31:17 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/27 00:42:57 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}	
	return (count);
}

void get_width(char *filename, t_map *map)
{
	char 	*line;
	int		fd;

	fd = open(filename,O_RDONLY);
	line = get_next_line(fd);
	map->width = count_word(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && (size_t)map->width != count_word(line, ' '))
		{
			ft_putstr_fd("The file width is wrong", 1);
			exit(1);
		}			
	}
	
}

void	get_height(char *filename, t_map *map)
{
	char *line;
	int		fd;

	fd = open(filename,O_RDONLY);
	map->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
		{
			free(line);
			map->height++;
		}
	}
}

int	read_map(char *filename, t_map *map)
{

	get_width(filename, map);
	get_height(filename, map);
	return (1);
}

// void	print_map(t_map *map_data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < map_data->height)
// 	{
// 		j = 0;
// 		while (j < map_data->width)
// 		{
// 			printf("%4.0f", (map_data->map)[i][j].z);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }


