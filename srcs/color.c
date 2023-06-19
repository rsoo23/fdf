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

void    set_color(t_data *data)
{
    if (data->p1->z != data->base_val || data->p2->z != data->base_val)
		data->color = PURPLE;
	else
		data->color = WHITE;
}