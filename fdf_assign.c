#include "fdf.h"

void    assign_xy(t_map *map_data)
{
    int i;
    int	j;

    i = 0;
    map_data->map = malloc(sizeof(t_point *) * map_data->height);
    while (i < map_data->height)
    {
        j = 0;
		(map_data->map)[i] = malloc(sizeof(t_point) * map_data->width);
        while (j < map_data->width)
		{
			(map_data->map)[i][j].x = j * map_data->ratio;
			(map_data->map)[i][j].y = i * map_data-> ratio;
			j++;
		}
		i++;
    }
}

void	assign_z_color(char *filename, t_map *map_data)
{
	int	fd;
	int	i;
	int	j;
	char	*line;
	char 	**value;
	char	**each_point;

	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		each_point = ft_split(line, ' ');
		while (j < map_data->width && each_point[j])
		{
			value = ft_split(each_point[j], ',');
			if (value)
			{
				if (value[0] && !all_digit(value[0]))
					//free and exit
				if (value[1] && !is_hex(value[1]))
					//free and exit

			}
			if (value && value[0])
				map_data->map[i][j].z = ft_atoi(value[0]) * map_data->ratio * 0.17 ;
			if (value && value[1])
				map_data->map[i][j].color = str_hex_to_int(value[1]);
			else
			{
				if (map_data->map[i][j].z != 0)
					map_data->map[i][j].color = 0xFF0000;
				else
					map_data->map[i][j].color = 0xFFFFFF;
			}
			ft_double_free(value);
			j++;
		}
		ft_double_free(each_point);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}


