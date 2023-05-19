/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:44:40 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/19 17:44:09 by ktunchar         ###   ########.fr       */
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

typedef struct s_fdf{
	void	*mlx_p;
	void	*win_p;
	int		zoom;
} t_fdf;

typedef struct t_map{
	int	**z_metric;
	int	width;
	int	height;
} t_map;

float   ft_max(float a, float b);
float   ft_abs(float n);
void    bresenham(t_map *map,t_fdf *fdf, float x0, float y0, float x1, float y1);
void    draw_from_metric(t_map *map, t_fdf *fdf);
size_t  count_word(char const *s, char c);
void get_width(char *filename, t_map *map);
void    get_height(char *filename, t_map *map);
void    assign_z_metric(char *filename, t_map *map);
int     read_map(char *filename, t_map *map);
void    print_metric(t_map *map);
void    rotateZ(float *x, float *y, float z, float theta);
void    ft_double_free(char **s);
int rgb_to_int(double r, double g, double b);

#endif