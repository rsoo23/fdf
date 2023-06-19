/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:16:12 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/19 14:34:01 by rsoo             ###   ########.fr       */
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
	char *str;

	str = ft_strjoin("FDF: ", data->infile);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 200, WHITE, str);
	free(str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 220, WHITE, "Isometric: i");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 230, WHITE, "Perspective: p");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 240, WHITE, "Top: t");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 250, WHITE, "Reset: r");
	str = ft_strjoin("Scale (z/x): ", ft_itoa(data->scale_factor));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 270, WHITE, str);
	free(str);
	str = ft_strjoin("Z Scale (f/g): ", ft_itoa(data->z_scale));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 290, WHITE, str);
	free(str);
	str = ft_strjoin("X-axis Rotation (q/a): ", ft_itoa(data->rot_angle_x));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 310, WHITE, str);
	free(str);
	str = ft_strjoin("Y-axis Rotation (q/a): ", ft_itoa(data->rot_angle_y));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 320, WHITE, str);
	free(str);
	str = ft_strjoin("Z-axis Rotation (q/a): ", ft_itoa(data->rot_angle_z));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 330, WHITE, str);
	free(str);
}
