#include "mlx/mlx.h"

int	main()
{
	void	*mlx_ptr;
	void	*window_ptr;

	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 500, 500, "hello");
	mlx_loop(mlx_ptr);
}