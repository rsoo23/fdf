/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:04:36 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/16 18:24:04 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	z_scale(t_data *data)
{
	data->p1->z *= data->z_scale;
	data->p2->z *= data->z_scale;
}

void	scale_points(t_data *data)
{
	data->p1->x *= data->scale_factor;
	data->p1->y *= data->scale_factor;
	// if (data->p1->z != 0)
	// 	data->p1->z -= 10;
	data->p2->x *= data->scale_factor;
	data->p2->y *= data->scale_factor;
	// if (data->p2->z != 0)
	// 	data->p2->z -= 10;
}

void	iso_transform(t_point *p1, t_point *p2, float angle)
{
	p1->x = (p1->x - p1->y) * cos(angle);
	p1->y = (p1->x + p1->y) * sin(angle) - p1->z;
	p2->x = (p2->x - p2->y) * cos(angle);
	p2->y = (p2->x + p2->y) * sin(angle) - p2->z;
}

void	perspec_transform(t_point *p1, t_point *p2, float focal_len)
{
	p1->x = focal_len * (p1->x / p1->z);
	p1->y = focal_len * (p1->y / p1->z);
	p2->x = focal_len * (p2->x / p2->z);
	p2->y = focal_len * (p2->y / p2->z);
}
