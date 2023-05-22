/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:33:52 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/23 01:32:17 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_point *point, float z, float theta)
{
	t_point	temp;

	temp = *point;
	point->x = (temp.x * cos(theta)) + (temp.y * sin(theta));
	point->y = (temp.y * cos(theta)) - (temp.x * sin(theta)) - z;
}
