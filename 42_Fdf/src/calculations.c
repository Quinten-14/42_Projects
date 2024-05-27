/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:40:05 by qraymaek          #+#    #+#             */
/*   Updated: 2024/01/15 12:43:41 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	find_max_height(int **matrix, t_map map)
{
	int	max_height;
	int	i;
	int	j;

	max_height = matrix[0][0];
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (matrix[i][j] > max_height)
				max_height = matrix[i][j];
			j++;
		}
		i++;
	}
	return (max_height);
}

int	find_min_height(int **matrix, t_map map)
{
	int	min_height;
	int	i;
	int	j;

	min_height = matrix[0][0];
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (matrix[i][j] < min_height)
				min_height = matrix[i][j];
			j++;
		}
		i++;
	}
	return (min_height);
}

// calculate the offsets of the sided
t_map_data	calc_offsets(t_map map, t_map_data data, t_map_bounds bounds)
{
	int	bbox_width;
	int	bbox_height;

	(void)map;
	bbox_width = bounds.max_x - bounds.min_x;
	bbox_height = bounds.max_y - bounds.min_y;
	data.offset_x = (1000 - bbox_width) / 2 - bounds.min_x;
	data.offset_y = (1000 - bbox_height) / 2 - bounds.min_y;
	return (data);
}

// calculate the tile size by window sizes divided by map sizes

t_map_data	calc_tile_size(t_map map, int **matrix)
{
	t_map_data	map_data;
	int			x_poss_size;
	int			y_poss_size;
	int			max_height;
	int			min_height;

	map_data.height_scale = 0.2;
	max_height = find_max_height(matrix, map);
	min_height = find_min_height(matrix, map);
	x_poss_size = 750 / map.width;
	y_poss_size = 750 / (map.height + max_height * map_data.height_scale
			- min_height * map_data.height_scale);
	map_data.tile_size = min(x_poss_size, y_poss_size);
	while (map_data.tile_size < 1)
	{
		map_data.height_scale /= 2;
		x_poss_size = 750 / map.width;
		y_poss_size = 750 / (map.height + max_height * map_data.height_scale
				- min_height * map_data.height_scale);
		map_data.tile_size = min(x_poss_size, y_poss_size);
	}
	return (map_data);
}

void	isometricprojection(t_coords coords, int *screen_x, int *screen_y,
		t_map_data data)
{
	*screen_x = (int)(((sqrt(2) / 2) * (coords.y - coords.x)) * data.tile_size);
	*screen_y = (int)(((sqrt(2) / 2) * (coords.x + coords.y) - sqrt(2.0 / 3.0)
				* coords.z * data.height_scale) * data.tile_size);
}
