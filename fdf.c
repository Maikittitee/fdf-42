#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map *map;
	t_fdf *fdf;


	map = malloc(sizeof(t_map));
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_p = mlx_init();
	fdf->win_p = mlx_new_window(fdf->mlx_p,1600,1080,"ktunchar's FdF");
	fdf->zoom = 20;
	if (argc != 2)
		return (1);
	read_map(argv[1], map);
	printf("data.width: %d , data.height: %d\n", map->width, map->height);
	printf("############ = Z_Metric = ###########\n");
	print_metric(map);
	draw_from_metric(map, fdf);

	mlx_loop(fdf->mlx_p);
	return (0);
}
