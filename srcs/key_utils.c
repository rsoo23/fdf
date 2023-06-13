/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:41:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/13 10:09:49 by rsoo             ###   ########.fr       */
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

int	scaling(int keysym, t_data *data);
{
	if (keysym == SCROLL_UP)
	{
		
	}
	else if (keysym == SCROLL_DOWN)
	{

	}
}
