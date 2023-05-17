#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map *map;
	// t_fdf *fdf;


	map = malloc(sizeof(t_map));
	// fdf->mlx = mlx_init();
	// fdf->win = mlx_new_window(data->mlx,1600,1080,"ktunchar's FdF");
	// data->zoom = 20;
	if (argc != 2)
		return (1);
	read_map(argv[1], map);
	printf("data.width: %d , data.height: %d\n", map->width, map->height);
	printf("############ = Z_Metric = ###########\n");
	print_metric(map);
	// draw_from_metric(data);

	// mlx_loop(data->mlx);
	return (0);
}
