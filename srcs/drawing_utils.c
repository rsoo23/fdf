/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:24:24 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/15 10:09:23 by rsoo             ###   ########.fr       */
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

int	abs_val(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	draw_vertical(int p1_x, int start_y, int end_y, t_data *data)
{
	while (start_y <= end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1_x, start_y, data->color);
		start_y++;
	}
}

void	bresenham_alg(t_point p1, t_point p2, t_data *data)
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
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, data->color);
		if (p1.x == p2.x && p1.y == p2.y)
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

/*
plotLine(x0, y0, x1, y1)
    dx = abs(x1 - x0)
    sx = x0 < x1 ? 1 : -1
    dy = -abs(y1 - y0)
    sy = y0 < y1 ? 1 : -1
    error = dx + dy
    
    while true
        plot(x0, y0)
        if x0 == x1 && y0 == y1 break
        e2 = 2 * error
        if e2 >= dy
            if x0 == x1 break
            error = error + dy
            x0 = x0 + sx
        end if
        if e2 <= dx
            if y0 == y1 break
            error = error + dx
            y0 = y0 + sy
        end if
    end while
*/

// void	bresenham_alg(t_point p1, t_point p2, t_data *data)
// {
// 	float	diff_x;
// 	float	diff_y;
// 	float	decision_var;

// 	diff_x = p2.x - p1.x;
// 	diff_y = p2.y - p1.y;
// 	printf("\x1b[34mdiff_x %f diff_y %f\n\n" "\x1b[0m", diff_x, diff_y);
// 	if (diff_x == 0)
// 		draw_vertical(p1.x, p1.y, p2.y, data);
// 	if (abs_val(diff_y) / abs_val(diff_x) < 1)
// 	{
// 		decision_var = 2 * diff_y - diff_x;
// 		while (p1.x <= p2.x && diff_x > 0 && diff_y > 0)
// 		{
// 			mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, data->color);
// 			p1.x++;
// 			if (decision_var < 0)
// 				decision_var += 2 * diff_y;
// 			else
// 			{
// 				decision_var += 2 * (diff_y - diff_x);
// 				p1.y++;
// 			}
// 		}
// 		decision_var = 2 * diff_x - diff_y;
// 		while (p1.x >= p2.x && diff_x < 0 && diff_y > 0)
// 		{
// 			mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, data->color);
// 			p1.x--;
// 			if (decision_var < 0)
// 				decision_var += 2 * diff_x;
// 			else
// 			{
// 				decision_var += 2 * (diff_x - diff_y);
// 				p1.y++;
// 			}
// 		}
// 	}
// 	else if (abs_val(diff_y) / abs_val(diff_x) >= 1)
// 	{
// 		decision_var = 2 * diff_y - diff_x;
// 		while (p1.y <= p2.y && diff_x > 0 && diff_y > 0)
// 		{
// 			mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, data->color);
// 			p1.y++;
// 			if (decision_var < 0)
// 				decision_var += 2 * diff_y;
// 			else
// 			{
// 				decision_var += 2 * (diff_y - diff_x);
// 				p1.x++;
// 			}
// 		}
// 		decision_var = 2 * diff_x - diff_y;
// 		while (p1.y <= p2.y && diff_x < 0 && diff_y > 0)
// 		{
// 			mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, data->color);
// 			p1.y++;
// 			if (decision_var < 0)
// 				decision_var += 2 * diff_x;
// 			else
// 			{
// 				decision_var += 2 * (diff_x - diff_y);
// 				p1.x--;
// 			}
// 		}
// 	}
// }
