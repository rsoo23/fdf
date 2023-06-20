/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:38:40 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/20 20:51:29 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	shift(t_data *data)
{
	data->p1->x += data->shift_x;
	data->p2->x += data->shift_x;
	data->p1->y += data->shift_y;
	data->p2->y += data->shift_y;
}

static void	rotate_about_x(t_point *p1, t_point *p2, t_data *data)
{
	float	angle;

	angle = data->rot_angle_x;
	p1->y = p1->y * cos(angle) - p1->z * sin(angle);
	p2->y = p2->y * cos(angle) - p2->z * sin(angle);
}

static void	rotate_about_y(t_point *p1, t_point *p2, t_data *data)
{
	float	angle;

	angle = data->rot_angle_y;
	p1->x = p1->x * cos(angle) + p1->z * sin(angle);
	p2->x = p2->x * cos(angle) + p2->z * sin(angle);
}

static void	rotate_about_z(t_point *p1, t_point *p2, t_data *data)
{
	float	angle;
	float	temp_x1;
	float	temp_x2;

	angle = data->rot_angle_z;
	temp_x1 = p1->x;
	temp_x2 = p2->x;
	p1->x = temp_x1 * cos(angle) - p1->y * sin(angle);
	p2->x = temp_x2 * cos(angle) - p2->y * sin(angle);
	p1->y = temp_x1 * sin(angle) + p1->y * cos(angle);
	p2->y = temp_x2 * sin(angle) + p2->y * cos(angle);
}

void	rotation(t_data *data)
{
	rotate_about_x(data->p1, data->p2, data);
	rotate_about_y(data->p1, data->p2, data);
	rotate_about_z(data->p1, data->p2, data);
}
