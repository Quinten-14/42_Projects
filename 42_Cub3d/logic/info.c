/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:40:47 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/08 16:21:43 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Print the map
void	prnt_map(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map && map[++y])
	{
		(printf("\n"), x = -1);
		while (map[y][++x])
			printf("%c", map[y][x]);
	}
	printf("\n");
}

// Print the scene
void	prnt_scene(t_scene *scene)
{
	int	y;

	y = -1;
	while (scene->nt_path[++y])
		printf("nt_path argument %i: %s\n", y, scene->nt_path[y]);
	(printf("\n"), y = -1);
	while (scene->et_path[++y])
		printf("et_path argument %i: %s\n", y, scene->et_path[y]);
	(printf("\n"), y = -1);
	while (scene->st_path[++y])
		printf("st_path argument %i: %s\n", y, scene->st_path[y]);
	(printf("\n"), y = -1);
	while (scene->wt_path[++y])
		printf("wt_path argument %i: %s\n", y, scene->wt_path[y]);
	(printf("\n"), y = -1);
	while (scene->c_clr && scene->c_clr[++y])
		printf("c_clr argument %i: %s\n", y, scene->c_clr[y]);
	(printf("\n"), y = -1);
	while (scene->f_clr && scene->f_clr[++y])
		printf("f_clr argument %i: %s\n", y, scene->f_clr[y]);
	prnt_map(scene->opt_map);
}

// Print locations
void	prnt_pos(t_pos **pos, char id)
{
	int	i;

	i = -1;
	while (pos && pos[++i])
		printf("'%c': Y:%i, X:%i\n", id, pos[i]->y, pos[i]->x);
}

// Print player data
void	print_debug(t_mlx *mlx)
{
	printf("Player position: x = %f, y = %f\n", mlx->map->player->posx,
		mlx->map->player->posy);
	printf("Player angle: %f\n", mlx->map->player->playerangle);
}
