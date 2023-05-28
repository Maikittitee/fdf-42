/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:44:40 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/28 22:31:02 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "lib/libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define ESC_KEY 53
# define MAGIC_Z 0.5

typedef struct s_point{
	float	x;
	float	y;
	float	z;
	int		color;
}t_point;

typedef struct s_img{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
}t_img;

typedef struct s_draw{
	float	dx;
	float	dy;
}t_draw;

typedef struct s_map{
	int		width;
	int		height;
	float	ratio;
	float	theta;
	t_point	**map;
}t_map;

typedef struct s_fdf{
	void	*mlx_p;
	void	*win_p;
	void	*img_p;
}t_fdf;

void	ft_initialize(t_map *map_data, char *filename, float theta);
void	assign_xy(t_map *map_data);
void	apply_ratio(t_map *map_data);
int		get_color(float z, char **value);
void	apply_to_each_point(char *line, t_map *map_data, int i);
void	assign_z_color(char *filename, t_map *map_data);
void	check_width(char *filename, t_map *map_data);
void	check_can_open(char *filename);
void	check_empty_file(char *filename);
float	ft_max(float a, float b);
float	ft_abs(float n);
void	put_to_img(char *buffer, t_img img, t_point pnt);
void	ft_dda(t_fdf *fdf, t_point s_pnt, t_point e_pnt);
void	draw_from_metric(t_map *map_data, t_fdf *fdf);
int		is_all_digit(char *str);
void	ft_str_tolower(char *str);
int		is_hex(char *str);
void	is_format_error(char **value);
void	check_arg(char *filename);
float	get_max_z(t_map *map_data);
int		get_rheight(t_map *map_data);
int		get_rwidth(t_map *map_data);
void	apply_start_pnt(t_map *map_data);
float	get_ratio(t_map *map_data);
int		close_win(t_fdf *fdf);
int		ft_exit(int keycode, t_fdf *fdf);
size_t	count_word(char const *s, char c);
char	*get_next_line_without_nl(int fd);
void	get_width(char *filename, t_map *map);
void	get_height(char *filename, t_map *map);
int		read_map(char *filename, t_map *map_data);
void	rotate_z(t_point *point, float theta);
void	apply_iso(t_map *old_map_data);
void	apply_difference(t_map *old_map_data, t_map *new_map_data);
void	ft_double_free(char **s);
void	ft_free_map(t_map *map_data);
int		get_value(char c);
int		str_hex_to_int(char *str);

#endif
