/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:40:53 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/24 14:40:53 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
Notes:
mlx_new_window(mlx, width, height, name): 
    ctrl + c to close window

mlx_loop: 
    initiate window rendering

mlx_loop_hook: 
    add extra functionality to your program by defining 
    a function that gets executed repeatedly within the main loop of 
    your program. It allows you to perform specific tasks or actions at 
    regular intervals while the program is running.

mlx_ptr:
    special key that grants access to the graphics system, 
    allowing you to create and manage graphical windows

win_ptr:
    represents the game window itself, enabling you to interact with 
    it, change its size, and respond to user input.

mlx_ptr is required to create win_ptr and establish a connection to 
the graphics system. Together, they provide the means to display graphics
 and create interactive experiences in a game or program.
*/

// gcc srcs/*.c -lmlx -framework OpenGL -framework AppKit

void	init_points(t_data *data)
{
	data->p1 = malloc(sizeof(t_point));
	data->p2 = malloc(sizeof(t_point));
	if (!(data->p1) || !(data->p2))
		return ;
	data->p1->x = 0;
	data->p1->y = 0;
	data->p1->z = 0;
	data->p2->x = 0;
	data->p2->y = 0;
	data->p2->z = 0;
}

void	init_data(t_data *data)
{
	init_points(data);
	data->shift_x = MID_X - 200;
	data->shift_y = 100;
	data->scale_factor = 70;
	data->color = WHITE;
	data->angle = 1.0;
	data->z_height = 0;
}

void	iso_transform_point(t_point *p, float angle)
{
	p->x = (p->x - p->y) * cos(angle);
	p->y = (p->x + p->y) * sin(angle) - p->z;
}

void	scale_points(t_data *data)
{
	data->p1->x *= data->scale_factor;
	data->p1->y *= data->scale_factor;
	// data->p1->z *= data->scale_factor;
	data->p2->x *= data->scale_factor;
	data->p2->y *= data->scale_factor;
	// data->p2->z *= data->scale_factor;
}

void	shift(t_data *data)
{
	data->p1->x += data->shift_x;
	data->p2->x += data->shift_x;
	data->p1->y += data->shift_y;
	data->p2->y += data->shift_y;
}

void	z_height(t_data *data)
{
	if (data->p1->z == 0 && data->p2->z > 0)
	{
		data->p2->z += data->z_height;
	}
	if (data->p1->z > 0 && data->p2->z > 0)
	{
		data->p1->z += data->z_height;
		data->p2->z += data->z_height;
	}
	if (data->p1->z > 0 && data->p2->z == 0)
		data->p1->z += data->z_height;
}

void	draw_horizontal_line(int i, int j, t_data *data)
{
	if (i != data->length - 1)
	{
		data->p1->x = i;
		data->p1->y = j;
		data->p1->z = data->alt_matrix[j][i];
		data->p2->x = i + 1;
		data->p2->y = j;
		data->p2->z = data->alt_matrix[j][i + 1];
		z_height(data);
		scale_points(data);
		iso_transform_point(data->p1, data->angle);
		iso_transform_point(data->p2, data->angle);
		shift(data);
		if (data->p2->z > 0)
			data->color = PURPLE;
		else
			data->color = WHITE;
		bresenham_alg(*(data->p1), *(data->p2), data);
	}
}

void	draw_vertical_line(int i, int j, t_data *data)
{
	if (j != data->width - 1)
	{
		data->p2->x = i;
		data->p2->y = j;
		data->p2->z = data->alt_matrix[j][i];
		iso_transform_point(data->p2, data->angle);
		data->p1->x = i;
		data->p1->y = j + 1;
		data->p1->z = data->alt_matrix[j + 1][i];
		scale_points(data);
		iso_transform_point(data->p1, data->angle);
		shift(data);
		if (data->p2->z > 0)
			data->color = PURPLE;
		else
			data->color = WHITE;
		bresenham_alg(*(data->p1), *(data->p2), data);
	}
}

int	make_grid(t_data *data)
{
	int	x_ind;
	int	y_ind;

	y_ind = -1;
	while (++y_ind < data->width)
	{
		x_ind = -1;
		while (++x_ind < data->length)
		{
			draw_horizontal_line(x_ind, y_ind, data);
			draw_vertical_line(x_ind, y_ind, data);
		}
	}
	return (0);
}

// gcc srcs/main.c -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit && ./a.out 42.fdf

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
    data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (data.win_ptr == NULL)
		return (1);
	init_data(&data);
	parse_map(av, &data);
	make_grid(&data);
	mlx_hook(data.win_ptr, 2, 1, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
}

/*
Notes:
draw lines based on the width and lengths 

width: 2, length: 2

0 __ 0 __ 0 
|    |    
0 __ 0 __ 0 
|    |    
0    0    0 

Scale up by setting mulitplying the coordinates by a zoom factor

Set color for different altitudes

Isometric Projection Formulas:
 - x' = (x - y) * cos(angle)
 - y' = (x + y) * sin(angle) - z
- the values of x' and y' are in 3d, default angle = 0.8

Translation / Shifting
- use mlx_clear_window
*/
