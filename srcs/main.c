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

#include <mlx.h>
#include "../includes/fdf.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1800
# define MLX_ERROR 1

/*
mlx_new_window(mlx, width, height, name): ctrl + c to close window
mlx_loop: initiate window rendering
*/

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int		create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// clang main.c -lX11 -lXext -lmlx

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	// t_data	img;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (MLX_ERROR);
	}
	while (1)
		 ;
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.bits_per_pixel, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0xFF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
}
