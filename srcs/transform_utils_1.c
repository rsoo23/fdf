/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:04:36 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/20 17:42:03 by rsoo             ###   ########.fr       */
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
	// data->p1->z *= data->scale_factor / 10.0;
	data->p2->x *= data->scale_factor;
	data->p2->y *= data->scale_factor;
	// data->p2->z *= data->scale_factor / 10.0;
}

void	iso_transform(t_point *p1, t_point *p2, float angle)
{
	p1->x = (p1->x - p1->y) * cos(angle);
	p1->y = (p1->x + p1->y) * sin(angle) - p1->z;
	p2->x = (p2->x - p2->y) * cos(angle);
	p2->y = (p2->x + p2->y) * sin(angle) - p2->z;
}

void	oblique_transform(t_point *p1, t_point *p2, float angle)
{
	p1->x += 0.5 * p1->z * cos(angle);
	p1->y += 0.5 * p1->z * cos(angle);
	p2->x += 0.5 * p2->z * cos(angle);
	p2->y += 0.5 * p2->z * cos(angle);
}
                                                                                                                                                                                                                                                                       