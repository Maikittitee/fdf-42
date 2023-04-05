/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:33:52 by ktunchar          #+#    #+#             */
/*   Updated: 2023/04/06 00:34:02 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotateZ(float *x, float *y, float z, float theta)
{
	float new_x;
	float new_y;
	// new_x = *x * cos(theta) - *y * sin(theta);
	// new_y = *y * cos(theta) + *x * sin(theta) - *z;
	new_x = (*x - *y) * cos(theta);
	new_y = (*x + *y) * sin(theta) - z;

	*x = new_x;
	*y = new_y;
}
