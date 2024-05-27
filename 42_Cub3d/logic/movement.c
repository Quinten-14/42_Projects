/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:21:43 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/09 20:22:00 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_dir(t_player_data *player, int dir)
{
	if (dir == W)
		player->newx = player->posx + player->deltay;
	else if (dir == A)
		player->newx = player->posx - player->deltax;
	else if (dir == S)
		player->newx = player->posx - player->deltay;
	else if (dir == D)
		player->newx = player->posx + player->deltax;
	if (dir == W)
		player->newy = player->posy - player->deltax;
	else if (dir == A)
		player->newy = player->posy - player->deltay;
	else if (dir == S)
		player->newy = player->posy + player->deltax;
	else if (dir == D)
		player->newy = player->posy + player->deltay;
}

static double	normalize_angle(double angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	rotate_player(t_player_data *player, int direction)
{
	int		i;
	double	angle;

	if (direction == LEFT || direction == Q)
		player->playerangle += 0.1;
	else
		player->playerangle -= 0.1;
	player->playerangle = normalize_angle(player->playerangle);
	i = -1;
	while (++i < 4)
	{
		angle = i * M_PI / 2;
		if (fabs(player->playerangle - angle) < (M_PI / 36))
		{
			player->playerangle = angle;
			break ;
		}
	}
}

// Handles Movement
int	move(t_mlx *mlx, t_minimap *map, t_player_data *player, int direction)
{
	if (direction == LEFT || direction == RIGHT || direction == Q
		|| direction == E)
	{
		rotate_player(map->player, direction);
		map->player->deltax = cos(map->player->playerangle) * 10;
		map->player->deltay = -sin(map->player->playerangle) * 10;
	}
	else
	{
		calculate_offsets(map->player);
		move_dir(map->player, direction);
		calculate_corners(&player->coll_data, player->newx, player->posy);
		if (!is_collision(map, &player->coll_data))
			player->posx = player->newx;
		calculate_corners(&player->coll_data, player->posx, player->newy);
		if (!is_collision(map, &player->coll_data))
			player->posy = player->newy;
	}
	render(mlx);
	return (SUCCESS);
}
