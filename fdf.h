/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:44:40 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/18 03:12:13 by ktunchar         ###   ########.fr       */
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
} t_fdf;

typedef struct t_map{
	int	**z_metric;
	int	width;
	int	height;
} t_map;

void    assign_z_metric(char *filename, t_map *map);
int     read_map(char *filename, t_map *map);
void    print_metric(t_map *map);
void    rotateZ(float *x, float *y, float z, float theta);
void    ft_double_free(char **s);
int rgb_to_int(double r, double g, double b);
size_t	count_word(char const *s, char c);

#endif