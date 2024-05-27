/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:17:34 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 20:51:42 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	give_shotgun(t_weapon_data *weapon)
{
	weapon->name = "Shotgun";
	weapon->range = 5 * GRID_SIZE;
	weapon->damage = 74;
	weapon->max_ammo = 6;
	weapon->ammo = weapon->max_ammo;
	weapon->full_auto = false;
	weapon->auto_speed = -1;
	weapon->walk_speed = 1;
	weapon->reload_speed = 1;
	weapon->weapon_id = SHOTGUN;
	weapon->max_player_ammo = 24;
	weapon->player_ammo = weapon->max_player_ammo;
}

void	give_ar(t_weapon_data *weapon)
{
	weapon->name = "AR-15";
	weapon->range = 16 * GRID_SIZE;
	weapon->damage = 47;
	weapon->max_ammo = 30;
	weapon->ammo = weapon->max_ammo;
	weapon->full_auto = true;
	weapon->auto_speed = 750;
	weapon->walk_speed = 1;
	weapon->reload_speed = 1;
	weapon->weapon_id = AR;
	weapon->max_player_ammo = 120;
	weapon->player_ammo = weapon->max_player_ammo;
}

int	get_color_main_image(t_mlx *mlx, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel
					/ 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}

void	draw_weapon(t_mlx *mlx, t_single_texture *tex, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < tex->y)
	{
		j = 0;
		while (j < tex->x)
		{
			tex->color = *(unsigned int *)(tex->data + (i * tex->size_line + j
						* (tex->bpp / 8)));
			if (tex->color != color)
				my_mlx_pixel_put_weapon(mlx, j, i, tex->color);
			else if (tex->color == color)
				my_mlx_pixel_put_weapon(mlx, j, i, get_color_main_image(mlx, j,
						i));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->weapon_img, 0, 0);
}

void	weapon_drawer(t_weapon_data *weapon, t_mlx *mlx)
{
	if (weapon->weapon_id == PISTOL)
		draw_weapon(mlx, &mlx->weapon_textures.pistol_text[1], 0xFFFFFF);
	else if (weapon->weapon_id == SHOTGUN)
		draw_weapon(mlx, &mlx->weapon_textures.shotgun_text[1], 0xFFFFFF);
	else if (weapon->weapon_id == AR)
		draw_weapon(mlx, &mlx->weapon_textures.ar_text[1], 0xFFFFFF);
}
