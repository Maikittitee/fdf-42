/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:44:40 by ktunchar          #+#    #+#             */
/*   Updated: 2023/03/29 18:50:19 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx/mlx.h"
#include "lib/libft/libft.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_magic{
	void	*mlx;
	void	*win;
	int		**z_metric;
	int	width;
	int	height;
} t_magic;

void    ft_double_free(char **s);
int     read_map(t_magic *data, char *filename);
void    print_metric(t_magic *data);
void    bresenham(t_magic *data, float x0, float y0, float x1, float y1);
int rgb_to_int(double r, double g, double b);

#endif