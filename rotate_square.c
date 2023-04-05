#include "fdf.h"

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

void	iso(float *x,float *y, float *new_x,float *new_y, float rad)
{

	*new_x = (*x * cos(rad) - *y * sin(rad));
	*new_y = (*x * sin(rad) + *y * cos(rad));
}

void	draw_circle(t_magic *data, int x0, int y0, int r)
{
	int	x;
	int	y;

	(void)x0;
	(void)y0;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			if ((x - x0) * (x - x0) + (y - y0) * (y- y0) <= r*r)
				mlx_pixel_put(data->mlx, data->win, x, y, rgb_to_int(1,0,0));
			x++;
		}
		y++;
	}
}

void	draw_square(t_magic data, int x0, int y0, int x1, int y1, float rad)
{
	float	x;
	float	y;
	float	new_x;
	float	new_y;

	x = (float)x0;
	y = (float)y0;
	while (y < y1)
	{
		x = (float)x0;
		while (x < x1)
		{
			iso(&x,&y,&new_x, &new_y, rad);
			mlx_pixel_put(data.mlx, data.win, new_x + 250,new_y + 250,rgb_to_int(1,0,0));
			x++;
		}
		y++;

	}
}

int mouse_event(int button, int x, int y, t_magic *param)
{
	(void)x;
	(void)y;
    // Whenever the event is triggered, print the value of button to console.
	mlx_clear_window(param->mlx,param->win);
    ft_putnbr_fd(button, 1);
	draw_square(*param,-100,-100,100,100,param->rad);
	param->rad += 0.1;
	return (1);
}

int	main()
{
	t_magic data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,500,500,"ktunchar");
	data.rad = 0;
		
	// draw_square(data,-100,-100,100,100,data.rad);
	// data.rad += 0.8;
	// usleep(1000000);
	// mlx_mouse_hook(data.win, &mouse_event, &data);
	draw_circle(&data, 250, 250, 100);
	mlx_loop(data.mlx);

}