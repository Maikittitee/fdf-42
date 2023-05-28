/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:55:24 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/28 07:32:35 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map_data;
	t_fdf	*fdf;

	if (argc != 2)
		return (1);
	check_arg(argv[1]);
	map_data = malloc(sizeof(t_map));
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_p = mlx_init();
	fdf->win_p = mlx_new_window(fdf->mlx_p, WIN_WIDTH, WIN_HEIGHT, "pmew");
	fdf->img_p = mlx_new_image(fdf->mlx_p, WIN_WIDTH, WIN_HEIGHT);
	read_map(argv[1], map_data);
	dprintf(1, "height:%d | width:%d", map_data->height, map_data->width);
	ft_initialize(map_data, argv[1], 0.523599);
	draw_from_metric(map_data, fdf);
	ft_dda(fdf, (t_point){0, WIN_HEIGHT/2, 0, 0x0000FF}, (t_point){WIN_WIDTH, WIN_HEIGHT/2, 0, 0x0000FF});
	ft_dda(fdf, (t_point){WIN_WIDTH/2, 0, 0, 0x0000FF}, (t_point){WIN_WIDTH/2, WIN_HEIGHT, 0, 0x0000FF});
	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img_p, 0, 0);
	mlx_hook(fdf->win_p, 17, 0, close_win, fdf);
	mlx_hook(fdf->win_p, 2, 1, ft_exit, fdf);
	mlx_loop(fdf->mlx_p);
	return (0);
}

void	ft_initialize(t_map *map_data, char *filename, float theta)
{
	map_data->theta = theta;
	assign_xy(map_data);
	assign_z_color(filename, map_data);
	map_data->ratio = get_ratio(map_data);
	// map_data->ratio = 20;
	dprintf(1, "ratio: %f\n", map_data->ratio);
	apply_ratio(map_data);
	apply_iso(map_data);
	apply_start_pnt(map_data);
}
