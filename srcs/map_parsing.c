/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:07:20 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/11 10:12:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	assign_altitude_matrix(t_data *data)
{
	char	*line;
	char	**num_arr;
	int		i;
	int		j;

	i = 0;
	data->alt_matrix = malloc(sizeof(int *) * (data->width + 1));
	if (!(data->alt_matrix))
		return ;
	data->fd = open(data->infile, O_RDONLY);
	if (data->fd < 0)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(data->fd);
	while (line)
	{
		data->alt_matrix[i] = malloc(sizeof(int) * (data->length + 1));
		num_arr = ft_split(line, ' ');
		j = -1;
		while (num_arr[++j])
			data->alt_matrix[i][j] = ft_atoi(num_arr[j]);
		free(num_arr);
		free(line);
		line = get_next_line(data->fd);
		i++;
	}
	free(line);
	close(data->fd);
}

static void	get_map_length(char *line, t_data *data)
{
	int	i;
	int	space_count;

	i = 0;
	space_count = 0;
	while (line[i] != '\n')
	{
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ' ')
			space_count++;
		i++;
	}
	if (data->length == 0)
		data->length = space_count;
	else if (data->length != space_count)
	{
		perror("Map Length Error");
		exit(FAILURE);
	}
}

static void	get_map_dimensions(t_data *data)
{
	char	*line;

	data->fd = open(data->infile, O_RDONLY);
	if (data->fd < 0)
	{
		perror("Failed to open file\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(data->fd);
	while (line)
	{
		data->width++;
		get_map_length(line, data);
		free(line);
		line = get_next_line(data->fd);
	}
}

void	parse_map(char **av, t_data *data)
{
	data->infile = ft_strdup(av[1]);
	data->length = 0;
	data->width = 0;
	get_map_dimensions(data);
	printf("length: %d, width: %d\n", data->length, data->width);
	assign_altitude_matrix(data);
	free(data->infile);
}
