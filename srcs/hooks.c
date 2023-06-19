/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:00:31 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/19 22:38:07 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	translation_rotation(int keysym, t_data *data)
{
	if (keysym == LEFT_ARROW)
		data->shift_x -= 10;
	else if (keysym == RIGHT_ARROW)
		data->shift_x += 10;
	else if (keysym == DOWN_ARROW)
		data->shift_y += 10;
	else if (keysym == UP_ARROW)
		data->shift_y -= 10;
	else if (keysym == A_KEY)
		data->rot_angle_x += 0.05;
	else if (keysym == S_KEY)
		data->rot_angle_y += 0.05;
	else if (keysym == D_KEY)
		data->rot_angle_z += 0.05;
	else if (keysym == Q_KEY)
		data->rot_angle_x -= 0.05;
	else if (keysym == W_KEY)
		data->rot_angle_y -= 0.05;
	else if (keysym == E_KEY)
		data->rot_angle_z -= 0.05;
}

static void	projections(int keysym, t_data *data)
{
	if (keysym == T_KEY)
		data->proj = 't';
	else if (keysym == I_KEY)
		data->proj = 'i';
	else if (keysym == R_KEY)
	else if (keysym == P_KEY)
		data->proj = 'p';
		init_data(data);
	else if (keysym == X_KEY)
		data->scale_factor += 1;
	else if (keysym == Z_KEY && data->scale_factor > 0)
		data->scale_factor -= 1;
}

void	extra_features(int keysym, t_data *data)
{
	if (keysym == G_KEY)
		data->z_scale += 1;
	else if (keysym == F_KEY)
		data->z_scale -= 1;
	else if (keysym == C_KEY)
		data->color->base_height -= 1;
	else if (keysym == V_KEY)
		data->color->base_height += 1;
	else if (keysym == H_KEY)
		data->color->base_hue_count -= 1;
	else if (keysym == J_KEY)
		data->color->base_hue_count += 1;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == ESC_KEY)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(EXIT_SUCCESS);
	}
	translation_rotation(keysym, data);
	projections_scaling(keysym, data);
	extras_features(keysym, data);
	// printf("keypress: %d\n", keysym);
	return (0);
}
