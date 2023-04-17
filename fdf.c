#include "fdf.h"

int	main(int argc, char **argv)
{
	t_magic *data;

	data = malloc(sizeof(t_magic) * 1);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,1600,1080,"ktunchar's FdF");
	data->zoom = 20;
	if (argc != 2)
		return (1);
	read_map(data, argv[1]);
	printf("data.width: %d , data.height: %d\n", data->width,data->height);
	printf("############ = Z_Metric = ###########\n");
	print_metric(data);
	draw_from_metric(data);

	mlx_loop(data->mlx);
	return (0);
}
