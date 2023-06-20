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
	if (!data->p1)
		exit_fdf(data, "p1 malloc error", EXIT_FAILURE);
	data->p2 = malloc(sizeof(t_point));
	if (!data->p2)
		exit_fdf(data, "p2 malloc error", EXIT_FAILURE);
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
	init_hues(&data->color);
	data->shift_x = 0;
	data->shift_y = 0;
	data->scale_factor = 50;
	data->z_scale = 1;
	data->proj = 'i';
	data->rot_angle_x = 0;
	data->rot_angle_y = 0;
	data->rot_angle_z = 0;
	data->color.base_hue_count = 1;
	data->color.hue_count = 1;
	data->color.base_height = 0;
	data->color.hue = 0xFFFFFF;
	data->obl_angle = 0.0;
}

int	render(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, \
	WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img.mlx_img)
		exit_fdf(data, "mlx_new_image error", EXIT_FAILURE);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, \
	&data->img.bpp, &data->img.line_len, &data->img.endian);
	if (!data->img.addr)
		exit_fdf(data, "mlx_get_data_addr error", EXIT_FAILURE);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render_map(data);
	mlx_put_image_to_window(data->mlx_ptr, \
	data->win_ptr, data->img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	render_menu(data);
	return (0);
}

static void	init_fdf(char **av, t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_fdf(data, "mlx_ptr error", EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!data->win_ptr)
		exit_fdf(data, "win_ptr error", EXIT_FAILURE);
	init_data(data);
	parse_map(av, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		perror("argument count error");
		return (1);
	}
	init_fdf(av, &data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, 2, 1, handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	exit_fdf(&data, NULL, EXIT_SUCCESS);
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
- the values of x' and y' are in 3d

Translation / Shifting
- use mlx_clear_window

Task List:
- [x] use images
- [x] fix the scaling
- [x] rotation
- [x] z_altitude scaling
- [x] correct freeing
- [ ] extra projection
- [x] get menu working
- [x] hue function for base
- [ ] hue function for non - base
*/
