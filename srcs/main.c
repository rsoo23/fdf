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

void	init_map(t_data *data)
{
	data->p1.x = 0;
	data->p1.y = 0;
	data->p1.z = 0;
	data->p2.x = 0;
	data->p2.y = 0;
	data->p2.z = 0;
	data->scale_factor = 50;
}

int	render(t_data *data)
{
	int		x_index;
	int		y_index;

	y_index = -1;
	while (++y_index < data->width)
	{
		x_index = -1;
		while (++x_index < data->length)
		{
			data->p1.x = x_index * data->scale_factor;
			data->p1.y = y_index * data->scale_factor;
			data->p2.x = (x_index + 1) * data->scale_factor;
			data->p2.y = y_index * data->scale_factor;
			printf("p1: (%d, %d) p2: (%d, %d)\n", data->p1.x, data->p1.y, data->p2.x, data->p2.y);
			bresenham_alg(data->p1, data->p2, data);
			data->p2.x = x_index * data->scale_factor;
			data->p2.y = (y_index + 1) * data->scale_factor;
			printf("p1: (%d, %d) p2: (%d, %d)\n", data->p1.x, data->p1.y, data->p2.x, data->p2.y);
			bresenham_alg(data->p1, data->p2, data);
			printf("\n");
		}
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
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (data.win_ptr == NULL)
		return (1);
	parse_map(av, &data);
	init_map(&data);
	render(&data);
	// mlx_hook(data.win_ptr, 2, 1, &keyrelease_checker, &data);
	mlx_hook(data.win_ptr, 2, 1, &esc_window, &data);
	mlx_hook(data.win_ptr, 4, 0, &scaling, &data);
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
