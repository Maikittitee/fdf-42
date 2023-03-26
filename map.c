/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:31:17 by ktunchar          #+#    #+#             */
/*   Updated: 2023/03/27 00:50:15 by ktunchar         ###   ########.fr       */
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

int		get_width(int fd)
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

int	read_map(t_magic *data, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	data->width = get_width(fd);
	data->height = get_height(fd);
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	t_magic data;

// 	if (argc != 2)
// 		return (1);

// 	read_map(&data, argv);
// 	printf("data.width: %d , data.height: %d", data.width,data.height);
// 	return (0);
// }
