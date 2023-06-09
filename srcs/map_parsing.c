/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:07:20 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/09 09:30:16 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	calc_width(t_data *data)
{
	data->fd = open(data->infile, O_RDONLY);
	if (data->fd < 0)
	{
		perror("Failed to open file\n");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(data->fd))
		data->width++;
	close(data->fd);
}

static void	check_all_lengths(char *line, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	line = get_next_line(data->fd);
	while (line)
	{
		i = 0;
		j = 0;
		while (line[i] != '\n')
		{
			while (ft_isdigit(line[i]))
				i++;
			if (line[i] == ' ')
				j++;
			i++;
		}
		if (j != data->length)
		{
			ft_printf("Map length error\n");
			free(line);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(data->fd);
	}
}

static void	calc_length(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	data->fd = open(data->infile, O_RDONLY);
	if (data->fd < 0)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(data->fd);
	while (line[i] != '\n')
	{
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ' ')
			data->length++;
		i++;
	}
	printf("length: %d\n", data->length);
	check_all_lengths(line, data);
	close(data->fd);
}

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
		j = 0;
		line = ft_strtrim(line, "\n");
		num_arr = ft_split(line, ' ');
		while (num_arr[j])
		{
			data->alt_matrix[i][j] = ft_atoi(num_arr[j]);
			j++;
		}
		free(num_arr);
		free(line);
		line = get_next_line(data->fd);
		i++;
	}
	free(line);
	close(data->fd);
}

void	parse_map(char **av, t_data *data)
{
	int i = 0;
	int j = 0;
	data->infile = ft_strdup(av[1]);
	printf("infile: %s\n", data->infile);
	data->length = 0;
	data->width = 0;
	calc_width(data);
	printf("length: %d, width: %d\n", data->length, data->width);
	calc_length(data);
	assign_altitude_matrix(data);
	while (data->alt_matrix[i])
	{
		j = 0;
		while (data->alt_matrix[i][j])
		{
			printf("%d", data->alt_matrix[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	free(data->infile);
}
