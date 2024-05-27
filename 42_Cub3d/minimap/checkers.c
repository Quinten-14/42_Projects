/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:19:09 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/22 21:32:10 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	in_minimap(int x, int y, t_minimap *map)
{
	int	center;

	center = map->img_size / 2;
	if (((x - center) * (x - center) + (y - center) * (y
				- center)) <= map->radius * map->radius)
		return (true);
	else
		return (false);
}

int	which_object(int x, int y, t_minimap *map)
{
	if (map->map[y][x] == '1')
		return (WALL);
	else if (map->map[y][x] == '2')
		return (OPEN_DOOR);
	else if (map->map[y][x] == 'D')
		return (DOOR);
	else if (map->map[y][x] == 'Z')
		return (ENEMY);
	else if (map->map[y][x] == 'O')
		return (SHOTGUN_BUY);
	else if (map->map[y][x] == 'T')
		return (AR_BUY);
	else if (map->map[y][x] == '0')
		return (AIR);
	else
		return (OUT_OF_BOUNDS);
}

int	obj_check(double x, double y, t_minimap *mini)
{
	int	rx;
	int	ry;

	rx = floor(x / GRID_SIZE);
	ry = floor(y / GRID_SIZE);
	if (rx < 0 || rx >= mini->map_x || ry < 0 || ry >= mini->map_y)
		return (OUT_OF_BOUNDS);
	if (mini->map[ry][rx] == '0' || mini->map[ry][rx] == 'N'
		|| mini->map[ry][rx] == 'E' || mini->map[ry][rx] == 'S'
		|| mini->map[ry][rx] == 'W')
		return (AIR);
	else
		return (which_object(rx, ry, mini));
	return (SUCCESS);
}

void	minimap_draw_seg(t_mlx *mlx, int x, int y, int object)
{
	if (object == WALL)
		my_mlx_pixel_put(mlx, y + 50, x + 50, 0x515459);
	else if (object == AIR)
		my_mlx_pixel_put(mlx, y + 50, x + 50, 0x202224);
	else if (object == OPEN_DOOR)
		my_mlx_pixel_put(mlx, y + 50, x + 50, 0x141517);
	else if (object == DOOR)
		my_mlx_pixel_put(mlx, y + 50, x + 50, 0x000000);
	else if (object == AR_BUY)
		my_mlx_pixel_put(mlx, y + 50, x + 50, 0x7b7f85);
	else if (object == SHOTGUN_BUY)
		my_mlx_pixel_put(mlx, y + 50, x + 50, 0x9aa3b3);
	else if (object == ENEMY)
		my_mlx_pixel_put(mlx, y + 50, x + 50, 0x152954);
}
