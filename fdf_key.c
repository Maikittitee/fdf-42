#include "fdf.h"

int	close_win(t_fdf *fdf)
{

	mlx_destroy_image(fdf->mlx_p, fdf->img_p);
	mlx_destroy_window(fdf->mlx_p, fdf->win_p);
	exit(0);
}

int	ft_exit(int keycode,t_fdf *fdf)
{

	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(fdf->mlx_p, fdf->img_p);
		mlx_destroy_window(fdf->mlx_p, fdf->win_p);
		exit(0);
	}
	return (0);
}