/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:33:01 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/26 17:16:28 by ktunchar         ###   ########.fr       */
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

int	get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (ft_isalpha(c) && c <= 'f')
		return (c - 'a' + 10);
	return (0);
	
}

int	str_hex_to_int(char *str)
{
	int	i;
	int	result;

	i = 2;
	result = 0;
	while (str[i])
	{
		result += ((15 * result) + get_value(ft_tolower(str[i])));
		i++;
	}
	return (result);
}