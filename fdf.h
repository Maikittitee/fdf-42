/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:44:40 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/26 02:53:05 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx/mlx.h"
#include "lib/libft/libft.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#define WIN_WIDTH 900
#define WIN_HEIGHT 600

#define ESC_KEY 53
#define Q_KEY 12

typedef	struct s_point{
	float	x;
	float	y;
	float	z;
	int	color;
} t_point;

typedef	struct s_img{
	int pixel_bits;
	int line_bytes;
	int endian;
} t_img;

typedef	struct s_draw{
	float	dx;
	float	dy;
} t_draw;

typedef struct s_map{
	int	width;
	int	height;
	float	ratio;
	float	theta;
	t_point	**map;
} t_map;

typedef struct s_fdf{
	void	*mlx_p;
	void	*win_p;
	void	*img_p;
	// int		zoom;
} t_fdf;


float   ft_max(float a, float b);
float   ft_abs(float n);
void	ft_dda(t_fdf *fdf, t_point s_pnt, t_point e_pnt);
void    draw_from_metric(t_map *map, t_fdf *fdf);
size_t  count_word(char const *s, char c);
void get_width(char *filename, t_map *map);
void    get_height(char *filename, t_map *map);
int     read_map(char *filename, t_map *map);
void    print_map(t_map *map);
int rgb_to_int(double r, double g, double b);
void draw_to_img(t_img img, char *buffer, int color, t_point pnt);


// assign & setting
void    assign_xy(t_map *map_data);
void	assign_z_color(char *filename, t_map *map_data);
void	apply_start_pnt(t_map *map_data);
int	get_ratio(t_map *map_data);

//utils 
void    ft_double_free(char **s);
void	ft_free_map(t_map *map_data);

// rotate
void	rotate_z(t_point *old_point, float theta);
void	apply_iso(t_map *old_map_data);
void	apply_difference(t_map *old_map_data, t_map *new_map_data);

#endif