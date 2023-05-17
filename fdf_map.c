/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:31:17 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/18 02:59:23 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	count_word(char const *s, char c)
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
			// free_map_exit(map);		
			printf("The file width is wrong");
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

void	assign_z_metric(char *filename, t_map *map)
{
	int	i;
	int j;
	char *line;
	char **line_split;
	int fd;

	fd = open(filename, O_RDONLY);
	i = 0;
	map->z_metric = ft_calloc(map->height, sizeof(int *));
	while (i < map->height)
	{
		line = get_next_line(fd);
		line_split = ft_split(line, ' ');
		free(line);
		(map->z_metric)[i] = ft_calloc(map->width, sizeof(int));
		j = 0;
		while  (j < map->width)
		{
			(map->z_metric)[i][j] = ft_atoi(line_split[j]);
			j++;
		}
		ft_double_free(line_split);
		i++;
	}
	// return (1);	
}
int	read_map(char *filename, t_map *map)
{

	get_width(filename, map);
	get_height(filename, map);
	assign_z_metric(filename, map);
	return (1);
}

void	print_metric(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%3d",(map->z_metric)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


