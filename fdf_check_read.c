/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 08:30:10 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/28 08:31:18 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_width(char *filename, t_map *map_data)
{
	int		fd;
	char	*line;
	size_t	count;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line_without_nl(fd);
	count = count_word(line, ' ');
	while (i ++ < map_data->height - 1)
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
			count = count_word(line, ' ');
	}
	if (line)
		free(line);
	close(fd);
}

void	check_can_open(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Cannot open file", 1);
		exit(1);
	}
	close(fd);
}
void	check_empty_file(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line || *line == '\n' || *line == '\0')
	{
		ft_putendl_fd("No data found", 1);
		exit(1);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}