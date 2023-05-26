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
	t_map *old_map_data;
	t_fdf *fdf;

	old_map_data = malloc(sizeof(t_map));
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_p = mlx_init();
	fdf->win_p = mlx_new_window(fdf->mlx_p,WIN_WIDTH, WIN_HEIGHT,"ktunchar's FdF");
	fdf->img_p = mlx_new_image(fdf->mlx_p, WIN_WIDTH, WIN_HEIGHT);
	if (argc != 2)
		return (1);
	read_map(argv[1], old_map_data);
	printf("data.width: %d , data.height: %d\n", old_map_data->width, old_map_data->height);
	old_map_data->theta = 0.8;
	old_map_data->ratio = get_ratio(old_map_data);
	printf("ratio: %f\n", old_map_data->ratio);
	// old_map_data->ratio = 20;
	assign_xy(old_map_data);
	assign_z_color(argv[1], old_map_data);
	apply_iso(old_map_data);
	apply_start_pnt(old_map_data);
	// apply_difference(old_map_data, new_map_data);
	print_map(old_map_data);
	draw_from_metric(old_map_data, fdf);
	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img_p , 0, 0);
	
	mlx_hook(fdf->win_p, 17, 0, close_win, fdf);
	mlx_hook(fdf->win_p, 2, 1, ft_exit, fdf);
	mlx_loop(fdf->mlx_p);
	return (0);
	// printf("%d\n", str_hex_to_int("0xFBAFF"));
}
