/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:52:06 by qraymaek          #+#    #+#             */
/*   Updated: 2024/01/08 21:29:02 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/get_next_line.h"
#include "../include/libft.h"

void	process_line(int *row, char *line, int width)
{
	int		j;
	char	*tok;

	j = 0;
	tok = line;
	while (*tok && j < width)
	{
		while (*tok == ' ' || *tok == '\t')
			tok++;
		if (*tok)
		{
			row[j] = ft_atoi(tok);
			j++;
			while (*tok && (!(*tok == ' ' || *tok == '\t')))
				tok++;
		}
	}
}

int	**map_to_2d_array(t_map map, char *file)
{
	int		**matrix;
	int		i;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	matrix = malloc(map.height * sizeof(int *));
	while (fd != 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		matrix[i] = malloc(map.width * sizeof(int));
		process_line(matrix[i], line, map.width);
		free(line);
		i++;
	}
	close(fd);
	return (matrix);
}

int	***map_iso_2d(t_map map, int **matrix, t_map_data data)
{
	int			***n_mat;
	t_coords	coords;
	int			i;
	int			j;

	n_mat = (int ***)malloc(sizeof(int **) * 2);
	n_mat[0] = (int **)malloc(sizeof(int *) * map.height);
	n_mat[1] = (int **)malloc(sizeof(int *) * map.height);
	i = 0;
	while (i < map.height)
	{
		n_mat[0][i] = (int *)malloc(sizeof(int) * map.width);
		n_mat[1][i] = (int *)malloc(sizeof(int) * map.width);
		j = 0;
		while (j < map.width)
		{
			coords.x = i;
			coords.y = j;
			coords.z = matrix[i][j];
			isometricprojection(coords, &n_mat[0][i][j], &n_mat[1][i][j], data);
			j++;
		}
		i++;
	}
	return (n_mat);
}

void	find_bounds(int ***iso_matrix, t_map map, t_map_bounds *bounds)
{
	int	i;
	int	j;

	bounds->min_x = iso_matrix[0][0][0];
	bounds->max_x = iso_matrix[0][0][0];
	bounds->min_y = iso_matrix[1][0][0];
	bounds->max_y = iso_matrix[1][0][0];
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (iso_matrix[0][i][j] < bounds->min_x)
				bounds->min_x = iso_matrix[0][i][j];
			if (iso_matrix[0][i][j] > bounds->max_x)
				bounds->max_x = iso_matrix[0][i][j];
			if (iso_matrix[1][i][j] < bounds->min_y)
				bounds->min_y = iso_matrix[1][i][j];
			if (iso_matrix[1][i][j] > bounds->max_y)
				bounds->max_y = iso_matrix[1][i][j];
			j++;
		}
		i++;
	}
}
