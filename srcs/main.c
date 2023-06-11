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

// clang main.c -lX11 -lXext -lmlx
// gcc main.c -lmlx -framework OpenGL -framework AppKit

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

void	bresenham_line_draw(t_point p1, t_point p2, t_data *data)
{
	int	diff_x;
	int	diff_y;
	int	decision_var;

	diff_x = p2.x - p1.x;
	diff_y = p2.y - p1.y;
	decision_var = 2 * diff_y - diff_x;
	while (p1.x <= p2.x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p1.x, p1.y, RED_PIXEL);
		p1.x++;
		if (decision_var < 0)
			decision_var += 2 * diff_y;
		else
		{
			decision_var += 2 * (diff_y - diff_x);
			p1.y++;
		}
	}
}

void	init_points(t_point *p1, t_point *p2)
{
	p1->x = 0;
	p1->y = 0;
	p2->x = 0;
	p2->y = 0;
}

int	render(t_data *data)
{
	t_point p1;
	t_point p2;
	int		x_index;
	int		y_index;

	init_points(&p1, &p2);
	x_index = 0;
	y_index = 0;
	while (y_index < data->width)
	{
		while (x_index < data->length)
		{
			bresenham_line_draw(p1, p2, data);
			bresenham_line_draw(p1, p2, data);
			x_index++;
		}
		y_index++;
	}
	return (0);
}

int	keyrelease_checker(int keysym)
{
	printf("Keyrelease: %d\n", keysym);
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
	// (void)av;
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (data.win_ptr == NULL)
		return (1);
	parse_map(av, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	// mlx_hook(data.win_ptr, 2, 1, &keyrelease_checker, &data);
	mlx_hook(data.win_ptr, 2, 1, &esc_window, &data);
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
