/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:04:36 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/19 16:15:58 by rsoo             ###   ########.fr       */
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
	data->p2->x *= data->scale_factor;
	data->p2->y *= data->scale_factor;
}

void	iso_transform(t_point *p1, t_point *p2, float angle)
{
	p1->x = (p1->x - p1->y) * cos(angle);
	p1->y = (p1->x + p1->y) * sin(angle) - p1->z;
	p2->x = (p2->x - p2->y) * cos(angle);
	p2->y = (p2->x + p2->y) * sin(angle) - p2->z;
}

void	perspec_transform(t_point *p1, t_point *p2, t_data *data)
{
	float	aspect_ratio;
	float	focal_len_scale_factor;
	int		z_far;
	int		z_near;
	float	lambda;

	aspect_ratio = WINDOW_WIDTH / WINDOW_HEIGHT;
	focal_len_scale_factor = 1 / tan(M_PI / 2 / 2);
	z_far = 1920 + 500;
	z_near = 1920;
	lambda = z_far / (z_far - z_near);
	data->proj = 'p';
	p1->x = p1->x / aspect_ratio * focal_len_scale_factor;
	p1->y = p1->y * focal_len_scale_factor;
	p1->z = lambda * p1->z - lambda * z_near;
	p2->x = p2->x / aspect_ratio * focal_len_scale_factor;
	p2->y = p2->y * focal_len_scale_factor;
	p2->z = lambda * p2->z - lambda * z_near; 
}
                                                                                                                                                                                                                                                                       