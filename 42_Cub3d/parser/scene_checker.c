/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:41:12 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/08 22:28:47 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Check if data is correct
static int	scene_data_checker(char *line, int fd, t_scene *scene, bool *error)
{
	line[ft_strlen(line) - 1] = '\0';
	if (line[0] == 'F' || line[0] == 'C')
		fetch_colors(line, scene, error);
	else
		fetch_texture_paths(line, scene, error);
	if (*error || !scene->nt_path || !scene->nt_path[1]
		|| !scene->et_path || !scene->et_path[1]
		|| !scene->st_path || !scene->st_path[1]
		|| !scene->wt_path || !scene->wt_path[1]
		|| !scene->c_clr || !scene->f_clr)
		return (0);
	(free(line), line = get_next_line(fd));
	if (!line)
		return (clean_gnl(line, fd), 0);
	while (line && line[0] == '\n')
		(free(line), line = get_next_line(fd));
	if (!ft_strncmp(line, "ON ", 3) || !ft_strncmp(line, "TW ", 3)
		|| !ft_strncmp(line, "DO ", 3) || !ft_strncmp(line, "ZO ", 3))
		return (scene_data_checker(line, fd, scene, error));
	if (!map_handler(line, fd, scene) || !scene->map)
		return (*error = true, prnt_err("Error: Invalid map"), 1);
	if (close(fd) < 0)
		perror("Error: Closing scene");
	return (1);
}

// Allocation memory for the scene
static int	scene_allocation(int fd, t_scene *scene, bool *error)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	if (*error)
		return (clean_gnl(line, fd), 0);
	while (line[0] == '\n')
		(free(line), line = get_next_line(fd));
	if (ft_strncmp(line, "NO ", 3) && ft_strncmp(line, "EA ", 3)
		&& ft_strncmp(line, "SO ", 3) && ft_strncmp(line, "WE ", 3)
		&& ft_strncmp(line, "C ", 2) && ft_strncmp(line, "F ", 2)
		&& ft_strncmp(line, "ON ", 3) && ft_strncmp(line, "TW ", 3)
		&& ft_strncmp(line, "DO ", 3) && ft_strncmp(line, "ZO ", 3))
		return (clean_gnl(line, fd), *error = true, 0);
	else if (!scene_data_checker(line, fd, scene, error))
		(free(line), scene_allocation(fd, scene, error));
	return (1);
}

// Master scene handler
int	scene_handler(char *file_name, t_scene *scene, t_mlx *mlx)
{
	int		fd;
	bool	error;

	if (!file_name)
		return (prnt_err("Error: File"), 0);
	if (!extension_checker(file_name, ".cub"))
		return (prnt_err("Error: Invalid file type"), 0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error: Opening scene"), 0);
	error = false;
	if (!scene_allocation(fd, scene, &error) || error || errno)
	{
		if (errno)
			return (perror("Error: Scene"), 0);
		return (prnt_err("Error: Invalid scene"), 0);
	}
	if (!fetch_textures(scene, mlx, &mlx->size)
		|| !map_algo(mlx, scene, scene->map))
		return (0);
	return (1);
}
	//return (prnt_map(scene->opt_map), 0);
