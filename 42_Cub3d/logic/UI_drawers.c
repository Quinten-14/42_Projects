/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI_drawers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:12:02 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/05 13:12:03 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// NOTE: this function doesnt push the image to the screen
void	ui_drawer(t_mlx *mlx, t_single_texture *tex, int color, int pos[2])
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
				my_mlx_pixel_put_ui(mlx, pos[0] + j, pos[1] + i, tex->color);
			j++;
		}
		i++;
	}
}

void	draw_crosshair(t_mlx *mlx)
{
	int	pos[2];

	pos[0] = (SCREEN_WIDTH - 16) / 2;
	pos[1] = (SCREEN_HEIGHT - 16) / 2;
	if (mlx->map->player->weapon_data.weapon_id == SHOTGUN)
		ui_drawer(mlx, &mlx->weapon_textures.crosshairs[1], 0x000000, pos);
	else
		ui_drawer(mlx, &mlx->weapon_textures.crosshairs[0], 0x000000, pos);
}

void	ui_colorizer(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			my_mlx_pixel_put_ui(mlx, j, i, 800080);
			j++;
		}
		i++;
	}
}

int	get_color_weapon_image(t_mlx *mlx, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		dst = mlx->weapon_addr + (y * mlx->line_length + x
				* (mlx->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}

void	ui_imager(t_mlx *mlx, int color)
{
	int	i;
	int	j;
	int	old_color;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			old_color = *(unsigned int *)(mlx->ui_addr + (i * mlx->line_length
						+ j * (mlx->bits_per_pixel / 8)));
			if (old_color != color)
				my_mlx_pixel_put_ui(mlx, j, i, old_color);
			else if (old_color == color)
				my_mlx_pixel_put_ui(mlx, j, i, get_color_weapon_image(mlx, j,
						i));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->ui_img, 0, 0);
}
