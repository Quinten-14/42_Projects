/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:58:21 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/15 16:58:22 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pistol_reloading(t_mlx *mlx)
{
	int	i;

	i = 1;
	while (i <= 24)
	{
		draw_weapon(mlx, &mlx->weapon_textures.pistol_text[i], 0xFFFFFF);
		draw_hud(mlx, mlx->map->player, &mlx->map->player->weapon_data);
		ui_imager(mlx, 800080);
		XFlush(((t_xvar *)mlx->ptr)->display);
		usleep(41666);
		i++;
	}
}

void	shotgun_reloading(t_mlx *mlx)
{
	int	i;

	i = 1;
	while (i <= 24)
	{
		draw_weapon(mlx, &mlx->weapon_textures.shotgun_text[i], 0xFFFFFF);
		draw_hud(mlx, mlx->map->player, &mlx->map->player->weapon_data);
		ui_imager(mlx, 800080);
		XFlush(((t_xvar *)mlx->ptr)->display);
		usleep(41666);
		i++;
	}
}

void	ar_reloading(t_mlx *mlx)
{
	int	i;

	i = 1;
	while (i <= 24)
	{
		draw_weapon(mlx, &mlx->weapon_textures.ar_text[i], 0xFFFFFF);
		draw_hud(mlx, mlx->map->player, &mlx->map->player->weapon_data);
		ui_imager(mlx, 800080);
		XFlush(((t_xvar *)mlx->ptr)->display);
		usleep(41666);
		i++;
	}
}
