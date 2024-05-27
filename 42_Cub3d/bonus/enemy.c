/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:17:41 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/06 20:54:22 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_ray_data_enemy(t_ray_data *data, t_player_data *player)
{
	data->pos_x = player->posy / GRID_SIZE;
	data->pos_y = player->posx / GRID_SIZE;
	data->dir_x = -1 * cos(player->playerangle);
	data->dir_y = -1 * sin(player->playerangle);
	data->plane_x = 0 - 0.75 * sin(player->playerangle);
	data->plane_y = 0 + 0.75 * cos(player->playerangle);
	data->camera_x = 0;
	ray_setup(data);
	setup_dda(data);
}

void	enemy_raycaster(t_player_data *player, char **map, int *hit_x,
		int *hit_y)
{
	t_ray_data	data;

	setup_ray_data_enemy(&data, player);
	while (data.hit == 0)
	{
		if (data.side_dist_x < data.side_dist_y)
		{
			data.side_dist_x += data.delta_dist_x;
			data.map_x += data.step_x;
			data.side = 0;
		}
		else
		{
			data.side_dist_y += data.delta_dist_y;
			data.map_y += data.step_y;
			data.side = 1;
		}
		if (map[data.map_x][data.map_y] == 'Z')
		{
			data.hit = 1;
			*hit_x = data.map_x;
			*hit_y = data.map_y;
		}
	}
}

void	remove_enemy(t_player_data *player, t_minimap *map, t_mlx *mlx)
{
	int	hit_x;
	int	hit_y;

	enemy_raycaster(player, map->map, &hit_x, &hit_y);
	if (map->map[hit_x][hit_y] == 'Z')
	{
		map->map[hit_x][hit_y] = '1';
		move(mlx, map, map->player, -1);
	}
}

void	damage_player(t_mlx *mlx)
{
	remove_enemy(mlx->map->player, mlx->map, mlx);
	mlx->map->player->points += 500;
}
