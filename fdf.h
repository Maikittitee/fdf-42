/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:44:40 by ktunchar          #+#    #+#             */
/*   Updated: 2023/03/26 01:12:29 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx/mlx.h"
#include "lib/libft/libft.h"
#include "lib/gnl/get_next_line.h"
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

#endif