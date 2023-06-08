/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:07:20 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/08 17:22:50 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	parse_map(char *infile)
{
	int		fd;
	char	*line;
	char	*trimmed_line;
	char	**values;
	int		i;

	i = 0;
	values = NULL;
	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open file\n");
		exit(EXIT_FAILURE);
	}
	rows = count_rows();
	line = get_next_line(fd);
	while (line)
	{
		trimmed_line = ft_strtrim(line, "\n");
		values[i++] = malloc(sizeof(char) * ft_strlen(trimmed_line) + 1);
		free(trimmed_line);
		free(line);
		line = get_next_line(fd);
	}
	// printf("%s\n", values[0]);
	// printf("%s\n", values[1]);
	// printf("%s\n", values[2]);
	// printf("%s\n", values[3]);
	// printf("%s\n", values[4]);
	// printf("%s\n", values[5]);
	// printf("%d\n", i);
}
