/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:18:50 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/22 22:19:54 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	dda_algo_single(t_ray_data *data, char **map, bool shot)
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
		if (!shot)
		{
			if (found_single(data, map, data->map_x, data->map_y))
				data->hit = true;
		}
		else if (shot)
		{
			if (found_hit(data, map, data->map_x, data->map_y))
				data->hit = true;
		}
	}
}

float	single_ray(t_player_data *p, char **m, t_ray_data *d, bool s)
{
	d->pos_x = p->posy / GRID_SIZE;
	d->pos_y = p->posx / GRID_SIZE;
	d->dir_x = -1 * cos(p->playerangle);
	d->dir_y = -1 * sin(p->playerangle);
	d->plane_x = 0 - 0.75 * sin(p->playerangle);
	d->plane_y = 0 + 0.75 * cos(p->playerangle);
	d->camera_x = 0;
	ray_setup(d);
	setup_dda(d);
	dda_algo_single(d, m, s);
	raycaster_calc(d);
	return (d->perp_wall_dist);
}

void	shoot_logic(t_player_data *player, t_minimap *map, t_mlx *mlx)
{
	bool		shot;
	float		distance;
	t_ray_data	data;

	shot = true;
	distance = single_ray(player, map->map, &data, shot) * GRID_SIZE;
	if (distance <= player->weapon_data.range && data.hit_object == ENEMY)
		damage_player(mlx);
	return ;
}

void	*reload_weapon_thread(void *arg)
{
	t_mlx			*mlx;
	t_weapon_data	*weapon;

	mlx = (t_mlx *)arg;
	pthread_mutex_lock(&mlx->lock);
	weapon = &mlx->map->player->weapon_data;
	if (weapon->player_ammo >= weapon->max_ammo)
	{
		mlx->reloading_anim_running = true;
		weapon->player_ammo -= weapon->max_ammo;
		if (weapon->weapon_id == PISTOL)
			pistol_reloading(mlx);
		else if (weapon->weapon_id == SHOTGUN)
			shotgun_reloading(mlx);
		else if (weapon->weapon_id == AR)
			ar_reloading(mlx);
		weapon->ammo = weapon->max_ammo;
		mlx->reloading_anim_running = false;
	}
	pthread_mutex_unlock(&mlx->lock);
	draw_hud(mlx, mlx->map->player, &mlx->map->player->weapon_data);
	ui_imager(mlx, 800080);
	XFlush(((t_xvar *)mlx->ptr)->display);
	return (NULL);
}

int	shoot_hook(int mouse_code, int x, int y, t_mlx *mlx)
{
	t_weapon_data	*weapon;
	pthread_t		thread_id;

	weapon = &mlx->map->player->weapon_data;
	(void)x;
	(void)y;
	if (mouse_code == 1)
	{
		if (weapon->ammo != 0 && !mlx->reloading_anim_running)
		{
			weapon->ammo--;
			shoot_logic(mlx->map->player, mlx->map, mlx);
		}
	}
	if (weapon->player_ammo != 0 && weapon->ammo == 0
		&& !mlx->reloading_anim_running)
	{
		pthread_create(&thread_id, NULL, reload_weapon_thread, mlx);
		pthread_detach(thread_id);
		return (0);
	}
	render(mlx);
	return (0);
}
