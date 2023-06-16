/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:47:12 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/16 09:36:02 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	abs_val(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

static void	bresenham_alg(t_point p1, t_point p2, t_data *data)
{
	data->bres.dx = abs_val(p2.x - p1.x);
	data->bres.dy = -abs_val(p2.y - p1.y);
	data->bres.err = data->bres.dx + data->bres.dy;
	if (p1.x < p2.x)
		data->bres.sx = 1;
	else
		data->bres.sx = -1;
	if (p1.y < p2.y)
		data->bres.sy = 1;
	else
		data->bres.sy = -1;
	while (1)
	{
		img_pix_put(&data->img, p1.x, p1.y, data->color);
		if (p1.x == p2.x && p1.y == p2.y)	
			break ;
		if (p1.x >= WINDOW_WIDTH || p1.y >= WINDOW_HEIGHT)
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
	z_height(data);
	scale_points(data);
	iso_transform_point(data->p1, data->angle);
	iso_transform_point(data->p2, data->angle);
	shift(data);
	// printf("x: %d, y: %d, z: %d\n", data->p1->x, data->p1->y, data->p1->z);
	// printf("x: %d, y: %d, z: %d\n", data->p2->x, data->p2->y, data->p2->z);
	if (data->p1->z != 0 || data->p2->z != 0)
		data->color = PURPLE;
	else
		data->color = WHITE;
	bresenham_alg(*(data->p1), *(data->p2), data);
}

void	draw_horizontal(int i, int j, t_data *data)
{
	if (i < data->length)
	{
		data->p1->x = i;
		data->p1->y = j;
		data->p1->z = data->alt_matrix[j][i];
		data->p2->x = i + 1;
		data->p2->y = j;
		data->p2->z = data->alt_matrix[j][i + 1];
		draw_line(data);
	}
}

void	draw_vertical(int i, int j, t_data *data)
{
	if (j < data->width)
	{
		data->p1->x = i;
		data->p1->y = j;
		data->p1->z = data->alt_matrix[j][i];
		data->p2->x = i;
		data->p2->y = j + 1;
		data->p2->z = data->alt_matrix[j + 1][i];
		draw_line(data);
	}
}
