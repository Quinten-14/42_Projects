/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:10:51 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/22 20:52:11 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Initialize position values
void	init_pos(t_scene *scene)
{
	scene->dpos = NULL;
	scene->zpos = NULL;
	scene->oy = 0;
	scene->ox = 0;
	scene->ty = 0;
	scene->tx = 0;
	scene->dy = 0;
	scene->dx = 0;
	scene->zy = 0;
	scene->zx = 0;
}

// Initialize weapon data
static void	weapon_init(t_player_data *player)
{
	t_weapon_data	weapon;

	weapon.name = "Pistol";
	weapon.range = 8 * GRID_SIZE;
	weapon.damage = 24;
	weapon.max_ammo = 12;
	weapon.ammo = weapon.max_ammo;
	weapon.max_player_ammo = 60;
	weapon.player_ammo = weapon.max_player_ammo;
	weapon.full_auto = false;
	weapon.auto_speed = -1;
	weapon.walk_speed = 1;
	weapon.reload_speed = 1.5;
	weapon.weapon_id = PISTOL;
	weapon.reloading = false;
	pthread_mutex_init(&weapon.lock, NULL);
	player->weapon_data = weapon;
}

// Initialize player and minimap data (mostly)
void	init_data(t_player_data *player, t_minimap *map, t_mlx *mlx)
{
	t_coll_data	coll_data;
	t_textures	textures;

	player->movespeed = GRID_SIZE / 5.;
	player->minimap_size = 1;
	player->fov = 90;
	player->points = 500;
	coll_data.collision_box_size = player->minimap_size;
	player->coll_data = coll_data;
	map->radius = 50;
	map->img_size = 100;
	map->player = player;
	get_sizes_matrix(map);
	fetch_weapon_textures(&textures, mlx);
	fetch_ui_textures(&textures, mlx);
	mlx->weapon_textures = textures;
	weapon_init(player);
	pthread_mutex_init(&mlx->lock, NULL);
}

// Initialize new optimized map
int	init_opt_map(t_scene *scene)
{
	int	i;
	int	j;

	scene->opt_map = (char **)malloc(sizeof(char *) * (scene->height + 3));
	if (!scene->opt_map)
		return (0);
	i = -1;
	while (++i < scene->height + 2)
	{
		scene->opt_map[i] = (char *)malloc(sizeof(char) * (scene->width + 3));
		if (!scene->opt_map[i])
			return (0);
		j = -1;
		while (++j < scene->width + 2)
			scene->opt_map[i][j] = ' ';
		scene->opt_map[i][j] = '\0';
	}
	scene->opt_map[i] = NULL;
	return (1);
}

// Initialization of an image array
void	init_img_arr(t_single_texture *arr, short n)
{
	short	i;

	i = -1;
	while (++i <= n)
		arr[i].text_img = NULL;
}
