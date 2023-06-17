/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:16:12 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/17 11:16:28 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x > 0 && y > 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	render_map(t_data *data)
{
	int j;
	int i;

	j = -1;
	while (++j <= data->height)
	{
		i = -1;
		while (++i <= data->width)
		{
			draw_horizontal(i, j, data);
			draw_vertical(i, j, data);
		}
	}
}

void	render_menu(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, MID_X, MID_Y, PURPLE, "lsflsdjflsdkjflsjflsdjf");
}
