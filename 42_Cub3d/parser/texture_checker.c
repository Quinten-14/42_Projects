/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:32:01 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/07 16:24:44 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Convert textures into mlx images
static int	fetch_optional_textures(t_scene *scene, t_mlx *mlx, int *s)
{
	if (scene->dt_path)
		mlx->dt = mlx_xpm_file_to_image(mlx->ptr, scene->dt_path[1], s, s);
	if (scene->dt_path && !mlx->dt)
		return (0);
	if (scene->ot_path)
		mlx->ot = mlx_xpm_file_to_image(mlx->ptr, scene->ot_path[1], s, s);
	if (scene->ot_path && !mlx->ot)
		return (0);
	if (scene->tt_path)
		mlx->tt = mlx_xpm_file_to_image(mlx->ptr, scene->tt_path[1], s, s);
	if (scene->tt_path && !mlx->tt)
		return (0);
	if (scene->zt_path)
		mlx->zt = mlx_xpm_file_to_image(mlx->ptr, scene->zt_path[1], s, s);
	if (scene->zt_path && !mlx->zt)
		return (0);
	return (1);
}

// Convert textures into mlx images
int	fetch_textures(t_scene *scene, t_mlx *mlx, int *s)
{
	if (scene->nt_path[2] || scene->et_path[2]
		|| scene->st_path[2] || scene->wt_path[2]
		|| (scene->dt_path && (!scene->dt_path[1] || scene->dt_path[2]))
		|| (scene->ot_path && (!scene->ot_path[1] || scene->ot_path[2]))
		|| (scene->tt_path && (!scene->tt_path[1] || scene->tt_path[2]))
		|| (scene->zt_path && (!scene->zt_path[1] || scene->zt_path[2])))
		return (prnt_err("Error: Invalid scene"), 0);
	mlx->nt = mlx_xpm_file_to_image(mlx->ptr, scene->nt_path[1], s, s);
	mlx->et = mlx_xpm_file_to_image(mlx->ptr, scene->et_path[1], s, s);
	mlx->st = mlx_xpm_file_to_image(mlx->ptr, scene->st_path[1], s, s);
	mlx->wt = mlx_xpm_file_to_image(mlx->ptr, scene->wt_path[1], s, s);
	if (!mlx->nt || !mlx->et || !mlx->st || !mlx->wt)
		return (prnt_err("Error: Converting textures"), 0);
	if (!fetch_optional_textures(scene, mlx, s))
		return (prnt_err("Error: Converting textures"), 0);
	return (1);
}

// Store texture paths
void	fetch_optional_texture_paths(char *line, t_scene *scene, bool *error)
{
	if (line[0] == 'D' && scene->dt_path)
		*error = true;
	else if (line[0] == 'D')
		scene->dt_path = ft_split(line, ' ');
	else if (line[0] == 'O' && scene->ot_path)
		*error = true;
	else if (line[0] == 'O')
		scene->ot_path = ft_split(line, ' ');
	else if (line[0] == 'T' && scene->tt_path)
		*error = true;
	else if (line[0] == 'T')
		scene->tt_path = ft_split(line, ' ');
	else if (line[0] == 'Z' && scene->zt_path)
		*error = true;
	else if (line[0] == 'Z')
		scene->zt_path = ft_split(line, ' ');
}

// Store texture paths
void	fetch_texture_paths(char *line, t_scene *scene, bool *error)
{
	if (line[0] == 'N' && scene->nt_path)
		*error = true;
	else if (line[0] == 'N')
		scene->nt_path = ft_split(line, ' ');
	else if (line[0] == 'E' && scene->et_path)
		*error = true;
	else if (line[0] == 'E')
		scene->et_path = ft_split(line, ' ');
	else if (line[0] == 'S' && scene->st_path)
		*error = true;
	else if (line[0] == 'S')
		scene->st_path = ft_split(line, ' ');
	else if (line[0] == 'W' && scene->wt_path)
		*error = true;
	else if (line[0] == 'W')
		scene->wt_path = ft_split(line, ' ');
	else
		fetch_optional_texture_paths(line, scene, error);
}
