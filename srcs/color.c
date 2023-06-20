/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:31:13 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/19 16:31:13 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	calc_rgb_uint(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

static int	is_in_range(int low_lim, int upp_lim, t_data *data)
{
	if (data->p1->z >= low_lim && data->p1->z <= upp_lim)
		if (data->p2->z >= low_lim && data->p2->z <= upp_lim)
			return (1);
	return (0);
}

/*
Cycles through the spectrum below
Ex: Starting (White) End:(Blue)
*/

void	get_hue(t_hue st_hue, t_hue end_hue, t_color *color)
{
	unsigned char	r_new;
	unsigned char	g_new;
	unsigned char	b_new;

	r_new = (end_hue.r - st_hue.r) / 20 * color->hue_index + st_hue.r;
	g_new = (end_hue.g - st_hue.g) / 20 * color->hue_index + st_hue.g;
	b_new = (end_hue.b - st_hue.b) / 20 * color->hue_index + st_hue.b;
	color->hue = calc_rgb_uint(r_new, g_new, b_new);
}

void	color_spectrum(unsigned int hue_count, t_color *color)
{
	color->hue_index = hue_count % 160;
	if (color->hue_index <= 20)
		get_hue(color->hues[0], color->hues[1], color);
	else if (color->hue_index <= 40)
		get_hue(color->hues[1], color->hues[2], color);
	else if (color->hue_index <= 60)
		get_hue(color->hues[2], color->hues[3], color);
	else if (color->hue_index <= 80)
		get_hue(color->hues[3], color->hues[4], color);
	else if (color->hue_index <= 100)
		get_hue(color->hues[4], color->hues[5], color);
	else if (color->hue_index <= 120)
		get_hue(color->hues[5], color->hues[6], color);
	else if (color->hue_index <= 150)
		get_hue(color->hues[6], color->hues[7], color);
	else if (color->hue_index <= 160)
		get_hue(color->hues[7], color->hues[0], color);
}

/*
WHITE 0xFFFFFF    255, 255, 255
BLUE 0x0000FF       0,   0, 255
GREEN 0x00FF00      0, 255,   0
YELLOW 0xFFFF00   255, 255,   0
ORANGE 0xFF6900   255, 105,   0
RED 0xFF0000      255,   0,   0
PINK 0xFF00FF     255,   0, 255
PURPLE 0x7800FF   120,   0, 255
*/

void	init_hues(t_color *color)
{
	color->hues[0].r = 255;
	color->hues[0].g = 255;
	color->hues[0].b = 255;

	color->hues[1].r = 0;
	color->hues[1].g = 0;
	color->hues[1].b = 255;

	color->hues[2].r = 0;
	color->hues[2].g = 255;
	color->hues[2].b = 0;

	color->hues[3].r = 255;
	color->hues[3].g = 255;
	color->hues[3].b = 0;

	color->hues[4].r = 255;
	color->hues[4].g = 105;
	color->hues[4].b = 0;

	color->hues[5].r = 255;
	color->hues[5].g = 0;
	color->hues[5].b = 0;

	color->hues[6].r = 255;
	color->hues[6].g = 0;
	color->hues[6].b = 255;

	color->hues[7].r = 120;
	color->hues[7].g = 0;
	color->hues[7].b = 255;
}

/*
base range (initial): color->base_height = 1
-1 <= z <= 1

Smooth Gradient that cycles through: (num % 70)
               White Blue Green Yellow Orange Red Pink Purple
base_hue_ind    1     10    20     30    40    50  60    70
*/
void	set_color(t_color *color, t_data *data)
{
	if (is_in_range(-color->base_height, color->base_height, data))
		color_spectrum(color->base_hue_count, color);
	else
		color->hue = WHITE;
}