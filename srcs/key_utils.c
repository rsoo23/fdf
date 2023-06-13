/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:41:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/13 12:20:30 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	esc_window(int keysym, t_data *data)
{
	if (keysym == ESC_KEY)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	scaling(int keysym, t_data *data)
{
	if (keysym == SCROLL_UP)
		data->scale_factor += 20;
	else if (keysym == SCROLL_DOWN && data->scale_factor > 0)
		data->scale_factor -= 20;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render(data);
	return (1);
}
