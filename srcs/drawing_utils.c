/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:24:24 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/13 18:04:06 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenham_alg(t_point p1, t_point p2, t_data *data)
{
	int	diff_x;
	int	diff_y;
	int	decision_var;

	diff_x = p2.x - p1.x;
	diff_y = p2.y - p1.y;
	if (diff_x >= diff_y)
	{
		decision_var = 2 * diff_y - diff_x;
		while (p1.x <= p2.x)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, RED_PIXEL);
			p1.x++;
			if (decision_var < 0)
				decision_var += 2 * diff_y;
			else
			{
				decision_var += 2 * (diff_y - diff_x);
				p1.y++;
			}
		}
	}
	else
	{
		decision_var = 2 * diff_x - diff_y;
		while (p1.y <= p2.y)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, RED_PIXEL);
			p1.y++;
			if (decision_var < 0)
				decision_var += 2 * diff_x;
			else
			{
				decision_var += 2 * (diff_x - diff_y);
				p1.x++;
			}
		}
	}
}
