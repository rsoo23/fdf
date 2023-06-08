/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:07:20 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/09 00:17:38 by rsoo             ###   ########.fr       */
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
	while (get_next_line(fd))
		data->width++;
	close(data->fd);
}

static void	check_all_lengths(char *line, t_data *data)
{
	int	length_check;

	length_check = 0;
	line = get_next_line(data->fd);
	while (line)
	{
		while (*line != '\n')
		{
			while (ft_isdigit(*line))
				line++;
			if (*line == ' ')
			{
				line++;
				length_check++;
			}	
		}
		if (length_check != data->length)
		{
			perror("Map length error");
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

	data->fd = open(data->infile, O_RDONLY);
	if (data->fd < 0)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(data->fd);
	while (*line != '\n')
	{
		while (ft_isdigit(*line))
			line++;
		if (*line == ' ')
		{
			line++;
			data->length++;
		}	
	}
	check_all_lengths(line, data);
	close(data->fd);
}

static void	assign_altitude_matrix(t_data *data)
{
	data->fd = open(data->infile, O_RDONLY);
	if (data->fd < 0)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	close(data->fd);
}

void	parse_map(char **av, t_data *data)
{
	data->infile = NULL;
	data->infile = ft_strdup(av[1]);
	data->length = 0;
	data->width = 0;
	calc_width(data);
	calc_length(data);
	assign_altitude_matrix(data);
	// printf("%s\n", values[0]);
	// printf("%s\n", values[1]);
	// printf("%s\n", values[2]);
	free(data->infile);
	// printf("%s\n", values[3]);
	// printf("%s\n", values[4]);
	// printf("%s\n", values[5]);
	// printf("%d\n", i);
}
