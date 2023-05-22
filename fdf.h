/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:44:40 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/23 01:47:57 by ktunchar         ###   ########.fr       */
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

typedef	struct s_point{
	float	x;
	float	y;
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

typedef struct s_fdf{
	void	*mlx_p;
	void	*win_p;
	void	*img_p;
	int		zoom;
} t_fdf;

typedef struct t_map{
	int	**z_metric;
	int	**color_metric;
	int	width;
	int	height;
} t_map;

float   ft_max(float a, float b);
float   ft_abs(float n);
void	bresenham(t_fdf *fdf, t_point s_pnt, t_point e_pnt);
void    draw_from_metric(t_map *map, t_fdf *fdf);
size_t  count_word(char const *s, char c);
void get_width(char *filename, t_map *map);
void    get_height(char *filename, t_map *map);
void    assign_z_metric(char *filename, t_map *map);
int     read_map(char *filename, t_map *map);
void    print_metric(t_map *map);
void	rotate_z(t_point *point, float z, float theta);
void    ft_double_free(char **s);
int rgb_to_int(double r, double g, double b);
void draw_to_img(t_img img, char *buffer, int color, t_point pnt);

#endif