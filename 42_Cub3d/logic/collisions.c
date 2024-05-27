/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:20:57 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/05 13:13:21 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_offsets(t_player_data *player)
{
	if (player->deltax < 0)
		player->coll_data.x_offset = -player->coll_data.collision_box_size;
	else
		player->coll_data.x_offset = player->coll_data.collision_box_size;
	if (player->deltay < 0)
		player->coll_data.y_offset = -player->coll_data.collision_box_size;
	else
		player->coll_data.y_offset = player->coll_data.collision_box_size;
}

void	calculate_corners(t_coll_data *coll_data, int posx, int posy)
{
	coll_data->top_left_x = (posx - coll_data->collision_box_size) / GRID_SIZE;
	coll_data->top_left_y = (posy - coll_data->collision_box_size) / GRID_SIZE;
	coll_data->top_right_x = (posx + coll_data->collision_box_size) / GRID_SIZE;
	coll_data->top_right_y = (posy - coll_data->collision_box_size) / GRID_SIZE;
	coll_data->bottom_left_x = (posx - coll_data->collision_box_size)
		/ GRID_SIZE;
	coll_data->bottom_left_y = (posy + coll_data->collision_box_size)
		/ GRID_SIZE;
	coll_data->bottom_right_x = (posx + coll_data->collision_box_size)
		/ GRID_SIZE;
	coll_data->bottom_right_y = (posy + coll_data->collision_box_size)
		/ GRID_SIZE;
}

int	is_collision(t_minimap *map, t_coll_data *col)
{
	return (map->map[col->top_left_y][col->top_left_x] == '1'
		|| map->map[col->top_right_y][col->top_right_x] == '1'
		|| map->map[col->bottom_left_y][col->bottom_left_x] == '1'
		|| map->map[col->bottom_right_y][col->bottom_right_x] == '1'
		|| map->map[col->top_left_y][col->top_left_x] == 'D'
		|| map->map[col->top_right_y][col->top_right_x] == 'D'
		|| map->map[col->bottom_left_y][col->bottom_left_x] == 'D'
		|| map->map[col->bottom_right_y][col->bottom_right_x] == 'D'
		|| map->map[col->top_left_y][col->top_left_x] == 'Z'
		|| map->map[col->top_right_y][col->top_right_x] == 'Z'
		|| map->map[col->bottom_left_y][col->bottom_left_x] == 'Z'
		|| map->map[col->bottom_right_y][col->bottom_right_x] == 'Z'
		|| map->map[col->top_left_y][col->top_left_x] == 'O'
		|| map->map[col->top_right_y][col->top_right_x] == 'O'
		|| map->map[col->bottom_left_y][col->bottom_left_x] == 'O'
		|| map->map[col->bottom_right_y][col->bottom_right_x] == 'O'
		|| map->map[col->top_left_y][col->top_left_x] == 'T' ||
			map->map[col->top_right_y][col->top_right_x] == 'T'
				|| map->map[col->bottom_left_y][col->bottom_left_x] == 'T'
				|| map->map[col->bottom_right_y][col->bottom_right_x] == 'T');
}
