/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:47:12 by rsoo              #+#    #+#             */
/*   Updated: 2025/06/08 13:45:21 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	bresenham_alg(t_point p1, t_point p2, t_data *data)
{
	bresenham_get_values(p1, p2, data);
	while (1)
	{
		img_pix_put(&data->img, (int)roundf(p1.x), (int)roundf(p1.y), data->color.hue);
		if (abs_val(p1.x - p2.x) < EPSILON && abs_val(p1.y - p2.y) < EPSILON)
			break ;
		data->bres.err2 = 2 * data->bres.err;
		if (data->bres.err2 >= data->bres.dy)
		{
			data->bres.err += data->bres.dy;
			p1.x += data->bres.sx;
		}
		if (data->bres.err2 <= data->bres.dx)
		{
			data->bres.err += data->bres.dx;
			p1.y += data->bres.sy;
		}
	}
}

static void	draw_line(t_data *data)
{
	z_scale(data);
	scale_points(data);
	offset_axes(data);
	if (data->proj == 'o')
		oblique_transform(data->p1, data->p2, data->obl_angle);
	if (data->proj == 'i')
		iso_transform(data->p1, data->p2, 1.0);
	if (data->rot_angle_x != 0 || \
	data->rot_angle_y != 0 || data->rot_angle_z != 0)
		rotation(data);
	offset_origin(data);
	shift(data);
	set_color(&data->color, data);
	bresenham_alg(*(data->p1), *(data->p2), data);
}

static void set_point(t_point *point, float x, float y, float z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void	draw_horizontal(int i, int j, t_data *data)
{
	if (i < data->width)
	{
		set_point(data->p1, i, j, data->alt_matrix[j][i]);
		set_point(data->p2, i + 1, j, data->alt_matrix[j][i + 1]);
		draw_line(data);
	}
}

void	draw_vertical(int i, int j, t_data *data)
{
	if (j < data->height)
	{
		set_point(data->p1, i, j, data->alt_matrix[j][i]);
		set_point(data->p2, i, j + 1, data->alt_matrix[j + 1][i]);
		draw_line(data);
	}
}
