/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:16:12 by rsoo              #+#    #+#             */
/*   Updated: 2025/06/07 23:50:27 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_pix_put(t_img *img, int x, int y, unsigned int color)
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
	int	j;
	int	i;

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

static void	render_menu_2(t_data *data)
{
	char	*str;
	char	*str2;

	str2 = ft_itoa(data->rot_angle_y * 180 / M_PI);
	str = ft_strjoin("Y-axis Rotation (Deg) (w/s): ", str2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 400, WHITE, str);
	free(str2);
	free(str);

	str2 = 	ft_itoa(data->rot_angle_z * 180 / M_PI);
	str = ft_strjoin("Z-axis Rotation (Deg) (e/d): ", str2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 420, WHITE, str);
	free(str2);
	free(str);

	str2 = ft_itoa(data->color.base_height);
	str = ft_strjoin("Base Height (c/v): ", str2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 450, WHITE, str);
	free(str2);
	free(str);

	str2 = ft_itoa(data->color.base_hue_count);
	str = ft_strjoin("Base Hue Count (h/j): ", str2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 470, WHITE, str);
	free(str2);
	free(str);

	str2 = ft_itoa(data->color.hue_count);
	str = ft_strjoin("Hue Count (k/l): ", str2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 490, WHITE, str);
	free(str2);
	free(str);

	str2 = ft_itoa(data->obl_angle * 180 / M_PI);
	str = ft_strjoin("Oblique Angle (Deg) (u): ", str2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 520, WHITE, str);
	free(str2);
	free(str);
}

void	render_menu(t_data *data)
{
	char	*str;
	char	*str2;

	str = ft_strjoin("FDF: ", data->infile);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 200, WHITE, str);
	free(str);

	mlx_string_put(data->mlx_ptr, \
	data->win_ptr, 100, 230, WHITE, "Isometric: i");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 250, WHITE, "Oblique: o");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 270, WHITE, "Top: t");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 290, WHITE, "Reset: r");

	str2 = ft_itoa((int)data->scale_factor);
	str = ft_strjoin("Scale (z/x): ", str2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 320, WHITE, str);
	free(str2);
	free(str);

	str2 = ft_itoa(data->z_scale);
	str = ft_strjoin("Z Scale (f/g): ", str2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 350, WHITE, str);
	free(str2);
	free(str);

	str2 = ft_itoa(data->rot_angle_x * 180 / M_PI);
	str = ft_strjoin("X-axis Rotation (Deg) (q/a): ", str2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 380, WHITE, str);
	free(str2);
	free(str);

	render_menu_2(data);
}
