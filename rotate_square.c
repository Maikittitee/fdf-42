#include "fdf.h"

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

void	rotateZ(float x,float y, float *new_x,float *new_y, float rad)
{

	*new_x = (x * cos(rad) - y * sin(rad));
	*new_y = (x * sin(rad) + y * cos(rad));
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

	x0 *= data.zoom;
	y0 *= data.zoom;
	x1 *= data.zoom;
	y1 *= data.zoom;

	x = (float)x0;
	y = (float)y0;

	while (y < y1)
	{
		x = (float)x0;
		while (x < x1)
		{
			rotateZ(x,y,&new_x, &new_y, rad);
			mlx_pixel_put(data.mlx, data.win, new_x + 500,new_y + 500,rgb_to_int(1,0,0));
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
	param->rad += 0.1;
	return (1);
}

int	key_hook(int keycode, t_magic *param)
{
	if (keycode == ADD_BUTTON)
		param->zoom += 0.1;
	else if (keycode == SUB_BUTTON)
		param->zoom -= 0.1;
	else if (keycode == LEFT_BUTTON)
		param->rad -= 0.1;
	else if (keycode == RIGHT_BUTTON)
		param->rad += 0.1;
	mlx_clear_window(param->mlx,param->win);
	draw_square(*param,-100,-100,100,100,param->rad);
	printf("You press:%d\n",keycode);
	return (0);
}

int	main()
{
	t_magic data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,1000,1000,"ktunchar");
	data.rad = 0;
	data.zoom = 1;
		
	draw_square(data,-100,-100,100,100,data.rad);
	mlx_key_hook(data.win, key_hook, &data);
	// data.rad += 0.8;
	// usleep(1000000);
	// mlx_mouse_hook(data.win, &mouse_event, &data);
	// draw_circle(&data, 250, 250, 100);
	mlx_loop(data.mlx);

}