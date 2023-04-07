/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:44:40 by ktunchar          #+#    #+#             */
/*   Updated: 2023/04/07 18:25:58 by ktunchar         ###   ########.fr       */
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

typedef struct s_magic{
	void	*mlx;
	void	*win;
	int		**z_metric;
	int	width;
	int	height;
	float	zoom;
	float rad;
} t_magic;

# define ADD_BUTTON 24
# define SUB_BUTTON 27
# define LEFT_BUTTON 123
# define RIGHT_BUTTON 124

#endif