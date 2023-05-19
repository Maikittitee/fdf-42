#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map *map;
	t_fdf *fdf;


	map = malloc(sizeof(t_map));
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_p = mlx_init();
	fdf->win_p = mlx_new_window(fdf->mlx_p,WIN_WIDTH, WIN_HEIGHT,"ktunchar's FdF");
	fdf->img_p = mlx_new_image(fdf->mlx_p, WIN_WIDTH, WIN_HEIGHT);

	fdf->zoom = 20;
	if (argc != 2)
		return (1);
	read_map(argv[1], map);
	printf("data.width: %d , data.height: %d\n", map->width, map->height);
	printf("############ = Z_Metric = ###########\n");
	print_metric(map);
	draw_from_metric(map, fdf);

	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img_p, 1, 100);

	mlx_loop(fdf->mlx_p);
	return (0);
}
