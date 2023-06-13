/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:31:01 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/28 20:31:01 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define START_X 0             // value: 0
# define START_Y WINDOW_HEIGHT // value: 1080
# define MID_X WINDOW_WIDTH / 2
# define MID_Y WINDOW_HEIGHT / 2
# define MLX_ERROR 1

# define ESC_KEY 53
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define KeyReleaseMask 1L<<1
# define KeyPressMask 1L<<0
# define WHITE_PIXEL 0xFFFFFF

/*
mlx_img: refers to the address mlx_new_image returns
bpps: bits per pixel
*/
// typedef struct	s_img
// {
// 	void	*mlx_img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// }	t_img;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*infile;
	int		fd;
	int		length;
	int		width;
	int		**alt_matrix;
	int		scale_factor;
	int		shift_x;
	int		shift_y;
	t_point	p1;
	t_point	p2;
}	t_data;


// main.c
int		render(t_data *data);
int		make_grid(t_data *data);

// map_parsing.c
void	parse_map(char **av, t_data *data);

// key_utils.c
int		handle_keypress(int keysym, t_data *data);
int		handle_mouse(int keysym, t_data *data);

// drawing_utils.c
void	bresenham_alg(t_point p1, t_point p2, t_data *data);

#endif
