/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:24:24 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/14 18:07:43 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// static void	swap_points(t_point *p1, t_point *p2)
// {
// 	int	temp_x;
// 	int	temp_y;

// 	temp_x = p1->x;
// 	temp_y = p1->y;
// 	p1->x = p2->x;
// 	p1->y = p2->y;
// 	p2->x = temp_x;
// 	p2->y = temp_y;
// }

float	abs_val(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	draw_vertical(float p1_x, float start_y, float end_y, t_data *data)
{
	while (start_y <= end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1_x, start_y, data->color);
		start_y++;
	}
}

void	bresenham_alg(t_point p1, t_point p2, t_data *data)
{
	float	diff_x;
	float	diff_y;
	float	decision_var;

	// if (p2.x < p1.x)
	// 	swap_points(&p1, &p2);
	diff_x = p2.x - p1.x;
	diff_y = p2.y - p1.y;
	printf("\x1b[34mdiff_x %f diff_y %f\n\n" "\x1b[0m", diff_x, diff_y);
	decision_var = 2 * diff_y - diff_x;
	if (diff_x == 0)
		draw_vertical(p1.x, p1.y, p2.y, data);
	while (p1.x <= p2.x && diff_x > 0)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, data->color);
		p1.x++;
		if (decision_var < 0)
			decision_var += 2 * diff_y;
		else
		{
			decision_var += 2 * (diff_y - diff_x);
			p1.y++;
		}
	}
	while (p1.x >= p2.x && diff_x < 0)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, data->color);
		p1.x--;
		if (decision_var < 0)
			decision_var += 2 * diff_y;
		else
		{
			decision_var += 2 * (diff_y - diff_x);
			p1.y++;
		}
	}
	// else
	// {
	// 	decision_var = 2 * diff_x - diff_y;
	// 	while (p1.y <= p2.y)
	// 	{
	// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, data->color);
	// 		p1.y++;
	// 		if (decision_var < 0)
	// 			decision_var += 2 * diff_x;
	// 		else
	// 		{
	// 			decision_var += 2 * (diff_x - diff_y);
	// 			p1.x++;
	// 		}
	// 	}
	// }
}
