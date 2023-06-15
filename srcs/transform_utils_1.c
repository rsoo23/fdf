/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:04:36 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/15 12:34:09 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso_transform_point(t_point *p, float angle)
{
	p->x = (p->x - p->y) * cos(angle);
	p->y = (p->x + p->y) * sin(angle) - p->z;
}

void	scale_points(t_data *data)
{
	data->p1->x *= data->scale_factor;
	data->p1->y *= data->scale_factor;
	if (data->p1->z != 0)
		data->p1->z += 10;
	data->p2->x *= data->scale_factor;
	data->p2->y *= data->scale_factor;
	if (data->p2->z != 0)
		data->p2->z += 10;
}

void	shift(t_data *data)
{
	data->p1->x += data->shift_x;
	data->p2->x += data->shift_x;
	data->p1->y += data->shift_y;
	data->p2->y += data->shift_y;
}

void	z_height(t_data *data)
{
	if (data->p1->z == 0 && data->p2->z > 0)
	{
		data->p2->z *= data->z_scale;
	}
	else if (data->p1->z > 0 && data->p2->z > 0)
	{
		data->p1->z *= data->z_scale;
		data->p2->z *= data->z_scale;
	}
	else if (data->p1->z > 0 && data->p2->z == 0)
		data->p1->z *= data->z_scale;
}
