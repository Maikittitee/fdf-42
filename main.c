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


void	draw_pixel_xy(void	*mlx_ptr,void *window_ptr, float x, float y, int size_x, int size_y)
{
	mlx_pixel_put(mlx_ptr, window_ptr, x + size_x/2 ,y+size_y/2, rgb_to_int(1,0,0));
}

int	main()
{
	void	*mlx_ptr;
	void	*window_ptr;
	float	x;
	float	y;


	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 500, 500, "hello");

	y = -125;
	while (y >= -125 && y <= 125)
	{
		x = -125;
		while (x >= -125 && x <= 125)
		{
			if (x*x + y*y < 625)
				draw_pixel_xy(mlx_ptr, window_ptr, x, y, 500,500);
			x++;
		}
		y++;
		
	}	
	
	
	
	
	
	
	
	
	mlx_loop(mlx_ptr);
}