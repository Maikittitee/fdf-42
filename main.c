#include "mlx/mlx.h"

int rgb_to_int(double r, double g, double b)
{
    int color;
	
	color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

int	main()
{
	void	*mlx_ptr;
	void	*window_ptr;

	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 500, 500, "hello");
	mlx_pixel_put(mlx_ptr, window_ptr, 500/2, 500/2, rgb_to_int(1,0,0));
	
	
	
	
	
	
	
	
	
	
	mlx_loop(mlx_ptr);
}