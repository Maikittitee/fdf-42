#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map *map;
	t_fdf *fdf;

	char test_alpha;

	test_alpha = 0;

	map = malloc(sizeof(t_map));
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_p = mlx_init();
	fdf->win_p = mlx_new_window(fdf->mlx_p,WIN_WIDTH, WIN_HEIGHT,"ktunchar's FdF");
	fdf->img_p = mlx_new_image(fdf->mlx_p, WIN_WIDTH, WIN_HEIGHT);

	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(fdf->img_p, &pixel_bits, &line_bytes, &endian);	
	
	int color = 0xABCDEF;

	if (pixel_bits != 32)
    	color = mlx_get_color_value(fdf->mlx_p, color);

	for(int y = 0; y < 360; ++y)
	{
	for(int x = 0; x < 640; ++x)
	{
		int pixel = (y * line_bytes) + (x * 4);

		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
	}
	}
	// fdf->zoom = 20;
	if (argc != 2)
		return (1);
	read_map(argv[1], map);
	// printf("data.width: %d , data.height: %d\n", map->width, map->height);
	// printf("############ = Z_Metric = ###########\n");
	// print_metric(map);
	// draw_from_metric(map, fdf);

	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img_p, 1, 100);

	mlx_loop(fdf->mlx_p);
	return (0);
}
