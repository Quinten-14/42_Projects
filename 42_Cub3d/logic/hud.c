/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:12:16 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/09 22:45:06 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_weapon_icon(t_mlx *mlx, t_weapon_data *weapon, int x, int y)
{
	int	pos[2];

	pos[0] = x;
	pos[1] = y;
	if (weapon->weapon_id == PISTOL)
		ui_drawer(mlx, &mlx->weapon_textures.weapon_ui[0], 0xFFFFFF, pos);
	else if (weapon->weapon_id == SHOTGUN)
		ui_drawer(mlx, &mlx->weapon_textures.weapon_ui[1], 0xFFFFFF, pos);
	else if (weapon->weapon_id == AR)
		ui_drawer(mlx, &mlx->weapon_textures.weapon_ui[2], 0xFFFFFF, pos);
}

int	get_int_len(int number)
{
	int	len;

	len = 0;
	while (number > 0)
	{
		len++;
		number /= 10;
	}
	return (len);
}

void	draw_points(t_mlx *mlx, t_player_data *player)
{
	int	pos[2];
	int	points;
	int	len;
	int	digit;

	len = 0;
	pos[0] = SCREEN_WIDTH - 250;
	pos[1] = 80;
	points = player->points;
	ui_drawer(mlx, &mlx->weapon_textures.money_font[10], 0, pos);
	pos[0] += 30;
	if (points == 0)
		return ((void)ui_drawer(mlx, &mlx->weapon_textures.money_font[0], 0,
				pos));
	len = get_int_len(player->points);
	pos[0] += len * 30 - 30;
	while (points > 0)
	{
		digit = points % 10;
		ui_drawer(mlx, &mlx->weapon_textures.money_font[digit], 0, pos);
		pos[0] -= 30;
		points /= 10;
	}
}

void	draw_ammo(t_mlx *mlx, int ammo, int x, int y)
{
	int	digit_width;
	int	pos[2];
	int	digit;

	digit_width = 30;
	pos[0] = x;
	pos[1] = y;
	if (ammo == 0)
	{
		pos[0] += digit_width;
		ui_drawer(mlx, &mlx->weapon_textures.font[0], 0, pos);
		return ;
	}
	pos[0] += digit_width;
	while (ammo > 0)
	{
		digit = ammo % 10;
		ui_drawer(mlx, &mlx->weapon_textures.font[digit], 0, pos);
		pos[0] -= digit_width;
		ammo /= 10;
	}
}

void	draw_hud(t_mlx *mlx, t_player_data *player, t_weapon_data *weapon)
{
	ui_colorizer(mlx);
	draw_crosshair(mlx);
	draw_weapon_icon(mlx, weapon, SCREEN_WIDTH - 300, SCREEN_HEIGHT - 100);
	draw_points(mlx, player);
	draw_ammo(mlx, player->weapon_data.ammo, (SCREEN_WIDTH - 150),
		(SCREEN_HEIGHT - 95));
	draw_ammo(mlx, player->weapon_data.player_ammo, (SCREEN_WIDTH - 150),
		(SCREEN_HEIGHT - 65));
	if (!mlx->reloading_anim_running)
		weapon_drawer(weapon, mlx);
}
