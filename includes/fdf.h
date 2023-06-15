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

// positions
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MID_X WINDOW_WIDTH / 2
# define MID_Y WINDOW_HEIGHT / 2

# define MLX_ERROR 1

// keys
# define ESC_KEY 53
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define C_KEY 8
# define X_KEY 7
# define G_KEY 5
# define F_KEY 3
# define R_KEY 15
# define E_KEY 14

// colors
# define WHITE 0xFFFFFF
# define PURPLE 0xFF00FF
# define BLACK 0x000000

/*
mlx_img: refers to the address mlx_new_image returns
bpps: bits per pixel
*/
typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_bres
{
	int		dx;
	int		dy;
	int		err;
	int		err2;
	int		sx;
	int		sy;
}	t_bres;

typedef struct	s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*infile;
	int				fd;
	int				length;
	int				width;
	int				**alt_matrix;
	int				scale_factor;
	int				shift_x;
	int				shift_y;
	int				z_scale;
	unsigned int	color;
	float			angle;
	t_point			*p1;
	t_point			*p2;
	t_bres			bres;
	t_img			img;
}	t_data;

// main.c
int		render(t_data *data);
void	make_grid(t_data *data);

// map_parsing.c
void	parse_map(char **av, t_data *data);

// key_utils.c
int		handle_keypress(int keysym, t_data *data);
// int		handle_mouse(int keysym, t_data *data);

// drawing_utils.c
void	draw_horizontal(int i, int j, t_data *data);
void	draw_vertical(int i, int j, t_data *data);

// transform_utils_1.c
void	iso_transform_point(t_point *p, float angle);
void	scale_points(t_data *data);
void	shift(t_data *data);
void	z_height(t_data *data);

// rendering.c
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);
void	render_map(t_data *data);

#endif
