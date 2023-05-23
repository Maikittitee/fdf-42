#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map *map_data;
	t_fdf *fdf;


	map_data = malloc(sizeof(t_map));
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_p = mlx_init();
	fdf->win_p = mlx_new_window(fdf->mlx_p,WIN_WIDTH, WIN_HEIGHT,"ktunchar's FdF");
	fdf->img_p = mlx_new_image(fdf->mlx_p, WIN_WIDTH, WIN_HEIGHT);

	if (argc != 2)
		return (1);
	read_map(argv[1], map_data);
	printf("data.width: %d , data.height: %d\n", map_data->width, map_data->height);
	map_data->ratio = 20;
	assign_xy(map_data);
	assign_z_color(argv[1], map_data);
	printf("############ = Z_Metric = ###########\n");
	print_map(map_data);
	draw_from_metric(map_data, fdf);
	// ft_dda(fdf, (t_point){0, 0, 0, 0xFFFFFF}, (t_point){WIN_WIDTH, WIN_HEIGHT, 0, 0xFFFFFF});
	// ft_dda(fdf, (t_point){0, WIN_HEIGHT, 0, 0xFFFFFF}, (t_point){WIN_WIDTH, 0, 0, 0xFFFFFF});
	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img_p, WIN_WIDTH/3 - map_data->width, WIN_HEIGHT/3 - map_data->height);

	mlx_loop(fdf->mlx_p);
	ft_free_map(map_data);
	return (0);
}
