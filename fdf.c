#include "fdf.h"

int	main(int argc, char **argv)
{
	t_magic *data;

	data = malloc(sizeof(t_magic) * 1);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,500,500,"ktunchar's FdF");
	if (argc != 2)
		return (1);
	read_map(data, argv[1]);
	printf("data.width: %d , data.height: %d\n", data->width,data->height);
	printf("############ = Z_Metric = ###########\n");
	print_metric(data);
	bresenham(data,10,10,500,500);

	mlx_loop(data->mlx);
	return (0);
}
