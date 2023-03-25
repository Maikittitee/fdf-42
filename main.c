#include "fdf.h"

int rgb_to_int(double r, double g, double b)
{
    int color;
	
	color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}


void	draw_pixel_xy(t_magic *fdf)
{
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x + fdf->size_x/2 ,fdf->y + fdf->size_y/2, rgb_to_int(1,0,0));
}

void	draw_circle(t_magic *fdf, float r)
{
	fdf->y = -fdf->size_y/2;
	while (fdf->y >= -fdf->size_y/2 && fdf->y <= fdf->size_y/2)
	{
		fdf->x = -fdf->size_x/2;
		while (fdf->x >= -fdf->size_x/2 && fdf->x <= fdf->size_x/2)
		{
			if (fdf->x*fdf->x + fdf->y*fdf->y < r*r)
				draw_pixel_xy(fdf);
			fdf->x++;
		}
		fdf->y++;
	}	
}
// int mouse_event(int button, int x, int y, int *param)
// {
// 	(void)x;
// 	(void)y;
// 	(void)param;

// 	if (button == 4)
// 		ft_putstr_fd("Cursor Down\n", 1);
// 	if (button == 5)
// 	{
// 		mlx_destroy_window(mlx_ptr,win_ptr)
// 		ft_putstr_fd("Cursor Up\n", 1);
// 	}
// 	if (button == 6)
// 		ft_putstr_fd("Cursor Left\n", 1);
// 	if (button == 7)
// 		ft_putstr_fd("Cursor Right\n", 1);
	
//     // Whenever the event is triggered, print the value of button to console.
// 	return (button);
// }

int	main()
{
	t_magic	fdf;

	// fdf = NULL;
	fdf.size_x = 500;
	fdf.size_y = 500;
	fdf.x = 0;
	fdf.y = 0;


	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.size_x, fdf.size_y, "my fdf");

	//mlx_mouse_hook(fdf.win, &mouse_event, 0);
	draw_circle(&fdf, 23);

	mlx_loop(fdf.mlx);
}