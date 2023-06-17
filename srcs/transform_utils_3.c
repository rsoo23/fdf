/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:32:52 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/17 11:16:28 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	offset_axes(t_data *data)
{
	data->p1->x -= data->width * data->scale_factor / 2;
	data->p2->x -= data->width * data->scale_factor / 2;
	data->p1->y -= data->height * data->scale_factor / 2;
	data->p2->y -= data->height * data->scale_factor / 2;
}

void	offset_origin(t_data *data)
{
	data->p1->x += MID_X;
	data->p2->x += MID_X;
	data->p1->y += MID_Y;
	data->p2->y += MID_Y;
}
