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
# include <math.h>
# include <mlx.h>

# if defined(__APPLE__)
#  include "macos_keys.h"
# elif defined(_WIN32) || defined(_WIN64)
#  include "windows_keys.h"
# elif defined(__linux__)
#  include "linux_keys.h"
# else
#  warning "Unknown platform - trying default Unix keys"
#  include "linux_keys.h"
# endif

// positions
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MID_X 960
# define MID_Y 540

// colors
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define YELLOW 0xFFFF00
# define ORANGE 0xFF6900
# define RED 0xFF0000
# define PINK 0xFF00FF
# define PURPLE 0x7800FF

/*
mlx_img: refers to the address mlx_new_image returns
bpps: bits per pixel
*/
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
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

typedef struct s_hue
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_hue;

typedef struct s_color
{
	unsigned int	base_hue_count;
	unsigned int	hue_count;
	unsigned int	base_height;
	unsigned int	hue_index;
	unsigned int	hue;
	int				max_z;
	t_hue			hues[8];
}	t_color;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*infile;
	int				fd;
	int				width;
	int				height;
	int				**alt_matrix;
	int				scale_factor;
	int				shift_x;
	int				shift_y;
	int				z_scale;
	char			proj;
	float			obl_angle;
	float			rot_angle_x;
	float			rot_angle_z;
	float			rot_angle_y;
	t_point			*p1;
	t_point			*p2;
	t_bres			bres;
	t_img			img;
	t_color			color;
}	t_data;

// main.c
int		render(t_data *data);
void	make_grid(t_data *data);
void	init_data(t_data *data);

// map_parsing.c
void	parse_map(char **av, t_data *data);

// hooks.c
int		handle_keypress(int keysym, t_data *data);

// map_drawing.c
void	draw_horizontal(int i, int j, t_data *data);
void	draw_vertical(int i, int j, t_data *data);

// rendering.c
void	img_pix_put(t_img *img, int x, int y, unsigned int color);
void	render_map(t_data *data);
void	render_menu(t_data *data);

// transform_utils_1.c
void	iso_transform(t_point *p1, t_point *p2, float angle);
void	oblique_transform(t_point *p1, t_point *p2, float angle);
void	scale_points(t_data *data);
void	z_scale(t_data *data);

// transform_utils_2.c
void	rotation(t_data *data);
void	shift(t_data *data);

// transform_utils_3.c
void	offset_axes(t_data *data);
void	offset_origin(t_data *data);

// utils.c
void	exit_fdf(t_data *data, char *str, int status);
void	bresenham_get_values(t_point p1, t_point p2, t_data *data);

// color_1.c
void	set_color(t_color *color, t_data *data);

// color_2.c
void	get_highest_alt(int **alt_mat, t_data *data);
void	init_hues(t_color *color);

#endif
