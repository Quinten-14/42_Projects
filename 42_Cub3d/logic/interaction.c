/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:12:27 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 22:21:38 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	door_interaction_ui(t_mlx *mlx, t_ray_data *data)
{
	if (data->hit_object == DOOR)
	{
		if (door_bought(&mlx->scene, data))
			better_mlx_string(mlx, 1, "Press F to open door");
		else if (!door_bought(&mlx->scene, data))
			better_mlx_string(mlx, 2, "Press F to buy door for", "350");
		mlx->map->player->in_range_door = true;
	}
	else if (data->hit_object == OPEN_DOOR)
	{
		better_mlx_string(mlx, 1, "Press F to close door");
		mlx->map->player->in_range_door = true;
	}
}

void	weapon_buy_ui(t_mlx *mlx, t_ray_data *data, int wanted_weapon)
{
	int		price;
	char	*str_price;

	if (mlx->map->player->weapon_data.weapon_id == wanted_weapon)
	{
		price = price_checker(data->hit_object, false);
		str_price = ft_itoa(price);
		better_mlx_string(mlx, 2, "Press F to buy ammo for", str_price);
		free(str_price);
	}
	else
	{
		price = price_checker(data->hit_object, true);
		str_price = ft_itoa(price);
		better_mlx_string(mlx, 2, "Press F to buy weapon for", str_price);
		free(str_price);
	}
}

void	interaction_ui(t_mlx *mlx)
{
	double		distance;
	t_ray_data	data;
	int			wanted_weapon;

	mlx->map->player->in_range_door = false;
	distance = single_ray(mlx->map->player, mlx->map->map, &data, 0)
		* GRID_SIZE;
	wanted_weapon = which_buy_point(data.hit_object);
	if (distance < GRID_SIZE && distance > 2 && wanted_weapon != -1)
	{
		if (data.hit_object == DOOR || data.hit_object == OPEN_DOOR)
			door_interaction_ui(mlx, &data);
		else if (data.hit_object == AR_BUY || data.hit_object == SHOTGUN_BUY)
			weapon_buy_ui(mlx, &data, wanted_weapon);
	}
}

void	interaction_handler(t_mlx *mlx, t_player_data *player, t_minimap *map)
{
	float		distance;
	t_ray_data	data;

	distance = single_ray(player, map->map, &data, 0) * GRID_SIZE;
	if (player->in_range_door == true)
		door_interaction(player, map, mlx);
	if (distance < GRID_SIZE && (data.hit_object == AR_BUY
			|| data.hit_object == SHOTGUN_BUY))
		buy_weapon(player, &player->weapon_data, mlx);
	render(mlx);
}
