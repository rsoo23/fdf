/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:07:20 by rsoo              #+#    #+#             */
/*   Updated: 2025/06/07 23:39:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	alt_matrix_gnl(t_data *data)
{
	char	*line;
	char	**num_arr;
	int		i;
	int		j;

	i = 0;
	line = get_next_line(data->fd);
	while (line)
	{
		data->alt_matrix[i] = malloc(sizeof(int) * (data->width + 1));
		num_arr = ft_split(line, ' ');
		j = -1;
		while (num_arr[++j])
			data->alt_matrix[i][j] = ft_atoi(num_arr[j]);
		free_2d_arr((void **)num_arr);
		free(line);
		line = get_next_line(data->fd);
		i++;
	}
	data->alt_matrix[i] = 0;
	free(line);
}

static void	assign_altitude_matrix(t_data *data)
{
	data->alt_matrix = malloc(sizeof(int *) * (data->height + 2));
	if (!(data->alt_matrix))
		exit_fdf(data, "Altitude matrix error", EXIT_FAILURE);
	data->fd = open(data->infile, O_RDONLY);
	if (data->fd < 0)
		exit_fdf(data, "Failed to open file", EXIT_FAILURE);
	alt_matrix_gnl(data);
	close(data->fd);
}

static void	get_map_length(char *line, t_data *data)
{
	int	i;
	int	space_count;

	i = 0;
	space_count = 0;
	while (line[i] != '\0')
	{
		i++;
		while (ft_isdigit(line[i]) && line[i])
			i++;
		if (line[i] == ' ')
			space_count++;
		while (line[i] == ' ')
			i++;
	}
	free(line);
	if (data->width == 0)
		data->width = space_count;
	else if (data->width != space_count)
		exit_fdf(data, "Map length error", EXIT_FAILURE);
}

static void	get_map_dimensions(t_data *data)
{
	char	*line;

	data->fd = open(data->infile, O_RDONLY);
	if (data->fd < 0)
		exit_fdf(data, "Failed to open file", EXIT_FAILURE);
	line = get_next_line(data->fd);
	while (line)
	{
		get_map_length(line, data);
		line = get_next_line(data->fd);
		data->height++;
	}
	data->height--;
	free(line);
}

void	parse_map(char **av, t_data *data)
{
	data->infile = ft_strdup(av[1]);
	data->width = 0;
	data->height = 0;
	get_map_dimensions(data);
	assign_altitude_matrix(data);
}
