/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:54:28 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/16 15:54:29 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render(t_mlx *mlx)
{
	draw_rays(mlx->map->player, mlx->map->map, mlx);
	update_walls(mlx->map, mlx);
	draw_player(mlx->map, mlx);
	draw_hud(mlx, mlx->map->player, &mlx->map->player->weapon_data);
	ui_imager(mlx, 800080);
	interaction_ui(mlx);
}
