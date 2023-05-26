#include "fdf.h"

int	close_win(t_fdf *fdf)
{

	mlx_destroy_image(fdf->mlx_p, fdf->img_p);
	mlx_destroy_window(fdf->mlx_p, fdf->win_p);
	exit(0);
}

int	ft_exit(int keycode,t_fdf *fdf)
{

	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(fdf->mlx_p, fdf->img_p);
		mlx_destroy_window(fdf->mlx_p, fdf->win_p);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_map *map_data;
	t_fdf *fdf;

	map_data = malloc(sizeof(t_map));
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_p = mlx_init();
	fdf->win_p = mlx_new_window(fdf->mlx_p,WIN_WIDTH, WIN_HEIGHT,"|");
	fdf->img_p = mlx_new_image(fdf->mlx_p, WIN_WIDTH, WIN_HEIGHT);
	if (argc != 2)
		return (1);
	read_map(argv[1], map_data);
	printf("data.width: %d , data.height: %d\n", map_data->width, map_data->height);
	map_data->theta = -0.523599;
	map_data->ratio = get_ratio(map_data);
	printf("ratio: %f\n", map_data->ratio);
	assign_xy(map_data);
	assign_z_color(argv[1], map_data);
	apply_iso(map_data);
	apply_start_pnt(map_data);
	// print_map(map_data);
	draw_from_metric(map_data, fdf);
	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img_p , 0, 0);
	
	mlx_hook(fdf->win_p, 17, 0, close_win, fdf);
	mlx_hook(fdf->win_p, 2, 1, ft_exit, fdf);
	mlx_loop(fdf->mlx_p);
	return (0);
	// printf("%d\n", str_hex_to_int("0xFBAFF"));
}
