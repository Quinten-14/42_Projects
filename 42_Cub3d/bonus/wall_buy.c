/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_buy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:17:27 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 22:22:33 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	which_buy_point(int object)
{
	if (object == SHOTGUN_BUY)
		return (SHOTGUN);
	else if (object == AR_BUY)
		return (AR);
	else if (object == DOOR || object == OPEN_DOOR)
		return (10);
	else
		return (-1);
}

int	price_checker(int object, bool weapon_buy)
{
	if (object == SHOTGUN_BUY && weapon_buy)
		return (450);
	else if (object == AR_BUY && weapon_buy)
		return (1200);
	else if (object == SHOTGUN_BUY && !weapon_buy)
		return (120);
	else if (object == AR_BUY && !weapon_buy)
		return (350);
	else
		return (-1);
}

void	buy_handling(int wanted, bool weapon_buy, t_player_data *play,
		int price)
{
	t_weapon_data	*weapon;

	weapon = &play->weapon_data;
	if (play->points >= price)
	{
		if (weapon_buy == true)
		{
			if (wanted == SHOTGUN)
				give_shotgun(&play->weapon_data);
			else if (wanted == AR)
				give_ar(&play->weapon_data);
		}
		else
		{
			if (weapon->player_ammo != weapon->max_player_ammo)
				weapon->player_ammo = weapon->max_player_ammo;
			else
				return ((void)printf("You already have max ammo\n"));
		}
		play->points -= price;
	}
	else
		printf("You can't afford this\n");
}

// We still need to free the outcome of ft_itoa
void	buy_weapon(t_player_data *player, t_weapon_data *weapon, t_mlx *mlx)
{
	double		distance;
	t_ray_data	data;
	int			price;
	int			wanted_weapon;

	distance = single_ray(player, mlx->map->map, &data, 0) * GRID_SIZE;
	wanted_weapon = which_buy_point(data.hit_object);
	if ((wanted_weapon != 1) && distance < GRID_SIZE)
	{
		if (weapon->weapon_id == wanted_weapon)
		{
			price = price_checker(data.hit_object, false);
			buy_handling(wanted_weapon, false, player, price);
		}
		else
		{
			price = price_checker(data.hit_object, true);
			buy_handling(wanted_weapon, true, player, price);
		}
	}
}
