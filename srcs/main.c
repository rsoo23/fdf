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

#define RED_PIXEL 0xFF0000

int	esc_window(int keysym, t_data *data)
{
	if (keysym == ESC_KEY)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	exit(EXIT_SUCCESS);
}

// int	render(t_data *data)
// {
// 	if (data->win_ptr != NULL)
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
// 	return (0);
// }

int	keyrelease_checker(int keysym)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

// void	parse_map(char *infile)
// {
// 	int		fd;
// 	char	*line;
// 	char	**values;

// 	fd = open(infile, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_printf(1, "Failed to open file\n", 20);
// 		exit(EXIT_FAILURE);
// 	}
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		values[0] = malloc 
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }

// gcc srcs/main.c -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit && ./a.out 42.fdf

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 2)
		return (1);
    data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	// parse_map(av[1]);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World!");
	if (data.win_ptr == NULL)
		return (1);

	mlx_pixel_put(data.mlx_ptr, data.win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	// mlx_hook(data.win_ptr, 2, 1, &keyrelease_checker, &data);
	mlx_hook(data.win_ptr, 2, 1, &esc_window, &data);
	mlx_loop(data.mlx_ptr);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
}