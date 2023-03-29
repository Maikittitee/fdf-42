/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:31:17 by ktunchar          #+#    #+#             */
/*   Updated: 2023/03/29 17:07:23 by ktunchar         ###   ########.fr       */
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

static int		get_width(int fd)
{
	char *line;
	int 	width;
	
	line = get_next_line(fd);
	width = count_word(line, ' ');
	return (width);
}

int	get_height(int	fd)
{
	int	height;
	char *line;

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
	return (height);

}

int	assign_z_metric(t_magic *data, int fd)
{
	int	i;
	// int j;
	char *line;
	// char **line_split;
	(void)fd;


	i = 0;
	data->z_metric = ft_calloc(data->height + 1, sizeof(int *));
	// while (i < data->height)
	// {
		// line = get_next_line(fd);
		// printf("line = %s\n",line);
		// line = get_next_line(fd);
		// printf("line = %s\n",line);
		// line = get_next_line(fd);
		// printf("line = %s\n",line);
		// line = get_next_line(fd);
		// printf("line = %s\n",line);

		// line_split = ft_split(line, ' ');
		// free(line);
		// (data->z_metric)[i] = ft_calloc(data->width + 1, sizeof(int));
		// printf("%s\n",line_split[1]);
		// j = 0;
		// // while  (line_split[j])
		// // {
		// // 	printf("-%d-\n",ft_atoi(line_split[j]));
		// // 	//(data->z_metric)[i][j] = ft_atoi(line_split[j]);
		// // 	j++;
		// // }
		// (data->z_metric)[i][j] = 0;	
		// // ft_double_free(line_split);
		// i++;
	// }
	(data->z_metric)[i] = 0;
	return (1);	
}
int	read_map(t_magic *data, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	data->width = get_width(fd);
	data->height = get_height(fd);
	// assign_z_metric(data, fd);
	close(fd);
	return (1);
}


int	main(int argc, char **argv)
{
	t_magic data;

	if (argc != 2)
		return (1);

	read_map(&data, argv);
	printf("data.width: %d , data.height: %d", data.width,data.height);
	return (0);
}
