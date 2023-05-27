/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:31:17 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/28 04:44:02 by ktunchar         ###   ########.fr       */
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

void	get_width(char *filename, t_map *map_data)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Cannot open file", 2);
		exit(1);	
	}
	line = get_next_line(fd);
	map_data->width = count_word(line, ' ');
	free(line);
	close(fd);	
}

void	get_height(char *filename, t_map *map_data)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Cannot open file", 1);
		exit(1);	
	}
	map_data->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		map_data->height++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	
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

void	check_width(char *filename, t_map *map_data)
{
	int	fd;
	char *line;
	size_t count;
	int	i;

	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line_without_nl(fd);
	count =	count_word(line, ' ');
	while (i < map_data->height - 1)
	{
		free(line);
		line = get_next_line_without_nl(fd);
		if (line && count != count_word(line, ' '))
		{
			free(line);
			ft_putendl_fd("Width not match", 1);
			exit(1);
		}
		if (line)
			count =	count_word(line, ' ');
		i++;
	}
	close(fd);	
}

void	check_empthy_n_open(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Cannot open file", 1);
		exit(1);
	}
	line = get_next_line_without_nl(fd);
	if (!line)
	{
		ft_putendl_fd("No data found", 1);
		exit(1);
		
	}
	free(line);
	close(fd);	
}

int	read_map(char *filename, t_map *map_data)
{
	check_empthy_n_open(filename);
	get_height(filename, map_data);
	get_width(filename, map_data);
	check_width(filename, map_data);
	return (1);
}
void	print_map(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			printf("%4.0f", (map_data->map)[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}
