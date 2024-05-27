/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:22:23 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/03 14:22:21 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_dda(t_ray_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y)
			* data->delta_dist_y;
	}
}

void	dda_algo(t_ray_data *data, char **map)
{
	while (!data->hit)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (found_hit(data, map, data->map_x, data->map_y) == true)
			data->hit = true;
	}
}

void	raycaster_calc(t_ray_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(SCREEN_HEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + SCREEN_HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + SCREEN_HEIGHT / 2;
	if (data->draw_end >= SCREEN_HEIGHT)
		data->draw_end = SCREEN_HEIGHT - 1;
	if (data->side == 0)
	{
		if (data->step_x < 0)
			data->wall_dir = NORTH;
		else
			data->wall_dir = SOUTH;
	}
	else
	{
		if (data->step_y < 0)
			data->wall_dir = WEST;
		else
			data->wall_dir = EAST;
	}
}

void	ray_setup(t_ray_data *data)
{
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
	data->hit = false;
}

void	draw_rays(t_player_data *player, char **map, t_mlx *mlx)
{
	int			x;
	t_ray_data	data;

	x = 0;
	data.pos_x = player->posy / GRID_SIZE;
	data.pos_y = player->posx / GRID_SIZE;
	data.dir_x = -1 * cos(player->playerangle);
	data.dir_y = -1 * sin(player->playerangle);
	data.plane_x = 0 - 0.75 * sin(player->playerangle);
	data.plane_y = 0 + 0.75 * cos(player->playerangle);
	while (x < SCREEN_WIDTH)
	{
		data.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray_setup(&data);
		setup_dda(&data);
		dda_algo(&data, map);
		raycaster_calc(&data);
		texture_setup(&data);
		draw_x_line(mlx, &data, x);
		x++;
	}
}
