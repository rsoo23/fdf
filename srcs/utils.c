/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:55:31 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/19 14:55:31 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_2d_arr(void **arr) {
	int i;

	i = 0;
	if (!arr)
		return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	exit_fdf(t_data *data, char *str, int status)
{
	if (status != 0)
		perror(str);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->p1)
		free(data->p1);
	if (data->p2)
		free(data->p2);
	if (data->infile)
		free(data->infile);
	if (data->alt_matrix)
		free_2d_arr((void **)(data->alt_matrix));
	data->infile = NULL;
	data->p1 = NULL;
	data->p2 = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	exit(status);
}

static int	abs_val(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	bresenham_get_values(t_point p1, t_point p2, t_data *data)
{
	data->bres.dx = abs_val(p2.x - p1.x);
	data->bres.dy = -abs_val(p2.y - p1.y);
	data->bres.err = data->bres.dx + data->bres.dy;
	data->bres.sx = 1;
	data->bres.sy = 1;
	if (p1.x > p2.x)
		data->bres.sx = -1;
	if (p1.y > p2.y)
		data->bres.sy = -1;
}
