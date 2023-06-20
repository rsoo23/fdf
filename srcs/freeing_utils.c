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
	data->infile = NULL;
	data->p1 = NULL;
	data->p2 = NULL;
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
	exit(status);
}


