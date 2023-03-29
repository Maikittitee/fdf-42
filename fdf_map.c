/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:31:17 by ktunchar          #+#    #+#             */
/*   Updated: 2023/03/29 18:10:42 by ktunchar         ###   ########.fr       */
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

static int		get_width(char *filename)
{
	char *line;
	int 	width;
	int		fd;

	fd = open(filename,O_RDONLY);
	line = get_next_line(fd);
	width = count_word(line, ' ');
	return (width);
}

static int	get_height(char *filename)
{
	int	height;
	char *line;
	int		fd;

	fd = open(filename,O_RDONLY);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		height++;
		if (!line)
			break ;
		else
			free(line);
	}
	return (height - 1) ;

}

int	assign_z_metric(t_magic *data, char *filename)
{
	int	i;
	int j;
	char *line;
	char **line_split;
	int fd;

	fd = open(filename, O_RDONLY);
	i = 0;
	data->z_metric = ft_calloc(data->height, sizeof(int *));
	while (i < data->height)
	{
		line = get_next_line(fd);
		line_split = ft_split(line, ' ');
		free(line);
		(data->z_metric)[i] = ft_calloc(data->width, sizeof(int));
		j = 0;
		while  (j < data->width)
		{
			(data->z_metric)[i][j] = ft_atoi(line_split[j]);
			j++;
		}
		ft_double_free(line_split);
		i++;
	}
	return (1);	
}
int	read_map(t_magic *data, char *filename)
{

	data->width = get_width(filename);
	data->height = get_height(filename);
	assign_z_metric(data, filename);
	return (1);
}

void	print_metric(t_magic *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d",(data->z_metric)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


