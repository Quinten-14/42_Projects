/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:17:49 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 22:22:00 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	door_bought(t_scene *scene, t_ray_data *data)
{
	int	i;

	i = 0;
	while (scene->dpos[i])
	{
		if (scene->dpos[i]->x == data->hit_y
			&& scene->dpos[i]->y == data->hit_x)
		{
			if (scene->dpos[i]->bought == true)
				return (true);
			else
				return (false);
		}
		i++;
	}
	return (false);
}

void	set_door_bought(t_scene *scene, t_ray_data *data)
{
	int	i;

	i = 0;
	while (scene->dpos[i])
	{
		if (scene->dpos[i]->x == data->hit_y
			&& scene->dpos[i]->y == data->hit_x)
		{
			scene->dpos[i]->bought = true;
			return ;
		}
		i++;
	}
}

void	door_interaction(t_player_data *player, t_minimap *map, t_mlx *mlx)
{
	t_ray_data	data;

	single_ray(player, map->map, &data, 0);
	if (data.hit_object == DOOR && door_bought(&mlx->scene, &data))
		map->map[data.hit_x][data.hit_y] = '2';
	else if (data.hit_object == DOOR && !door_bought(&mlx->scene, &data))
	{
		if (player->points >= 350)
		{
			player->points -= 350;
			set_door_bought(&mlx->scene, &data);
			map->map[data.hit_x][data.hit_y] = '2';
		}
		else
			printf("You can't afford this\n");
	}
	else if (data.hit_object == OPEN_DOOR)
		map->map[data.hit_x][data.hit_y] = 'D';
	render(mlx);
}
