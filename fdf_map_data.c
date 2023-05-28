/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:31:17 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/28 08:31:39 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
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

char	*get_next_line_without_nl(int fd)
{
	char	*line;
	char	*ret;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	ret = ft_strtrim(line, "\n");
	if (*ret == 0)
		return (NULL);
	free(line);
	return (ret);
}

void	get_width(char *filename, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Cannot open file", 1);
		exit(1);
	}
	line = get_next_line(fd);
	map->width = count_word(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

void	get_height(char *filename, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Cannot open file", 1);
		exit(1);	
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line == '\n')
		{
			ft_putendl_fd("Wrong file line lenght", 1);
			exit(1);
		}
		else
		{
			free(line);
			map->height++;
		}
	}
}


int	read_map(char *filename, t_map *map_data)
{
	check_can_open(filename);
	check_empty_file(filename);
	map_data->height = 0;
	get_height(filename, map_data);
	get_width(filename, map_data);
	check_width(filename, map_data);
	return (1);
}

