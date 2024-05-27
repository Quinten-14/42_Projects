/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:05:32 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/03 14:23:13 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
 * The minimap can be both used for the bonus or a debug for raycasts
 * We make a 2D array of the map and we make our player visible in here
 * We also have a little line that shows you which direction we are looking at
 */

int	get_starting_angle(char direction, t_player_data *player)
{
	if (direction == 'N')
		player->playerangle = 0;
	else if (direction == 'E')
		player->playerangle = 3 * M_PI / 2;
	else if (direction == 'S')
		player->playerangle = M_PI;
	else if (direction == 'W')
		player->playerangle = M_PI / 2;
	else
	{
		printf("Oops, you normally shouldn't be able to get here\n");
		return (FAILURE);
	}
	if (direction == 'W' || direction == 'E')
	{
		player->deltax = -cos(player->playerangle) * 5;
		player->deltay = -sin(player->playerangle) * 5;
	}
	else if (direction == 'N' || direction == 'S')
	{
		player->deltax = -cos(player->playerangle) * 5;
		player->deltay = sin(player->playerangle) * 5;
	}
	return (SUCCESS);
}

int	find_player(char **map, t_player_data *player)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' || map[y][x] == 'S'
				|| map[y][x] == 'W')
			{
				get_starting_angle(map[y][x], player);
				player->posx = x * GRID_SIZE + GRID_SIZE / 2.0;
				player->posy = y * GRID_SIZE + GRID_SIZE / 2.0;
				return (SUCCESS);
			}
			x++;
		}
		y++;
	}
	return (FAILURE);
}

void	draw_player(t_minimap *map, t_mlx *mlx)
{
	t_player_drawer	draw;

	draw.texture_path = "textures/arrow.xpm";
	draw.img = mlx_xpm_file_to_image(mlx->ptr, draw.texture_path,
			&draw.img_width, &draw.img_height);
	draw.img_data = mlx_get_data_addr(draw.img, &draw.bpp, &draw.size_line,
			&draw.endian);
	draw.center = map->img_size / 2;
	draw.y = draw.center - draw.img_height / 2;
	while (draw.y < (draw.center + draw.img_height / 2))
	{
		draw.x = draw.center - draw.img_width / 2;
		while (draw.x < (draw.center + draw.img_width / 2))
		{
			draw.color = *(int *)(draw.img_data + ((draw.x - draw.center
							+ draw.img_width / 2) + (draw.y - draw.center
							+ draw.img_height / 2) * draw.img_width) * draw.bpp
					/ 8);
			if (draw.color == 0xFFFFFF)
				my_mlx_pixel_put(mlx, draw.x + 50, draw.y + 50, draw.color);
			draw.x++;
		}
		draw.y++;
	}
	mlx_destroy_image(mlx->ptr, draw.img);
}

void	draw_pixel(t_minimap *map, t_mlx *mlx, t_mini_drawer *drawer)
{
	drawer->sy++;
	if (in_minimap(drawer->x / drawer->sampler_f, drawer->y / drawer->sampler_f,
			map))
	{
		drawer->relative_x = drawer->x - drawer->center * drawer->sampler_f;
		drawer->relative_y = drawer->y - drawer->center * drawer->sampler_f;
		drawer->rot_x = drawer->relative_x * cos(-map->player->playerangle)
			- drawer->relative_y * sin(-map->player->playerangle);
		drawer->rot_y = drawer->relative_x * sin(-map->player->playerangle)
			+ drawer->relative_y * cos(-map->player->playerangle);
		drawer->screen_x = drawer->rot_x / drawer->sampler_f + drawer->center;
		drawer->screen_y = drawer->rot_y / drawer->sampler_f + drawer->center;
		if (drawer->screen_x >= 0 && drawer->screen_x < map->img_size
			&& drawer->screen_y >= 0 && drawer->screen_y < map->img_size)
			minimap_draw_seg(mlx, drawer->screen_x, drawer->screen_y,
				obj_check(drawer->sx, drawer->sy, map));
	}
}

void	update_walls(t_minimap *map, t_mlx *mlx)
{
	t_mini_drawer	drawer;

	drawer.center = map->img_size / 2;
	drawer.sampler_f = 2;
	drawer.sampler_s = map->img_size * drawer.sampler_f;
	drawer.y = -1;
	drawer.sx = map->player->posx - drawer.sampler_s / 2.0 - 1;
	while (++drawer.y < drawer.sampler_s)
	{
		drawer.x = -1;
		drawer.sx++;
		drawer.sy = map->player->posy - drawer.sampler_s / 2.0 - 1;
		while (++drawer.x < drawer.sampler_s)
			draw_pixel(map, mlx, &drawer);
	}
}
