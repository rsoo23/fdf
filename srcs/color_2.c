/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:02:03 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/20 15:12:35 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

