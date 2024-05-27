/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:41:12 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/08 22:26:56 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Convert the scene's map to a 2d array stored in the scene data struct
static int	map_to_array(int y, char *line, t_scene *scene)
{
	scene->map = resize_arr(scene->map, y + 1);
	if (!scene->map)
		return (0);
	line[ft_strlen(line) - 1] = '\0';
	scene->map[y] = ft_strdup(line);
	if (!scene->map[y])
		return (0);
	scene->map[y + 1] = NULL;
	return (1);
}

// Master map handler
int	map_handler(char *line, int fd, t_scene *scene)
{
	int		x;
	int		y;

	y = 0;
	while (line)
	{
		if (line[0] == '\n')
			return (clean_gnl(line, fd), 0);
		x = -1;
		while (line[++x])
			if (line[x] != ' ' && line[x] != '0' && line[x] != '1'
				&& line[x] != 'N' && line[x] != 'S'
				&& line[x] != 'E' && line[x] != 'W'
				&& line[x] != 'D' && line[x] != 'O'
				&& line[x] != 'T' && line[x] != 'Z' && line[x] != '\n')
				return (clean_gnl(line, fd), 0);
		if (!map_to_array(y, line, scene))
			return (clean_gnl(line, fd), 0);
		(free(line), line = get_next_line(fd), y++);
	}
	return (1);
}

// Flooder algorithm
static void	flooder(char **map, int y, int x, bool *error)
{
	if (map[y][x] == 'D')
		map[y][x] = '3';
	else
		map[y][x] = '2';
	if (y < 1 || x < 1
		|| !map[y + 1] || !map[y][x + 1]
		|| !map[y - 1][x] || !map[y + 1][x]
		|| map[y - 1][x] == ' ' || map[y + 1][x] == ' '
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		return (*error = true, (void)0);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'D')
		flooder(map, y + 1, x, error);
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'D')
		flooder(map, y - 1, x, error);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'D')
		flooder(map, y, x + 1, error);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'D')
		flooder(map, y, x - 1, error);
}

// Master map algorithm
int	map_algo(t_mlx *mlx, t_scene *scene, char **map)
{
	t_opt	opt;
	bool	error;
	int		y;
	int		x;

	errno = 0;
	if (!get_positions(mlx, scene, &y, &x))
	{
		if (errno)
			return (perror("Error: Positions"), 0);
		return (prnt_err("Error: Invalid map\nError: Invalid scene"), 0);
	}
	error = false;
	flooder(map, y, x, &error);
	if (error)
		return (prnt_err("Error: Invalid map\nError: Invalid scene"), 0);
	if (!opt_map(mlx, scene, &opt))
	{
		if (errno)
			return (perror("Error: Optimizing map"), 0);
		return (prnt_err("Error: Invalid map\nError: Invalid scene"), 0);
	}
	free_arr((void *)scene->map);
	scene->map = NULL;
	return (1);
}
