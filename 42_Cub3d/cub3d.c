/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/16 04:24:41 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_linux/mlx.h"
#include <X11/Xlib.h>

// Initialize the values for mlx and the scene
static void	init_scene(t_scene *scene)
{
	scene->nt_path = NULL;
	scene->et_path = NULL;
	scene->st_path = NULL;
	scene->wt_path = NULL;
	scene->dt_path = NULL;
	scene->ot_path = NULL;
	scene->tt_path = NULL;
	scene->zt_path = NULL;
	scene->c_clr = NULL;
	scene->f_clr = NULL;
	scene->c = NULL;
	scene->f = NULL;
	scene->map = NULL;
	scene->opt_map = NULL;
	scene->height = 0;
	scene->width = 0;
	scene->py = 0;
	scene->px = 0;
	scene->d = '0';
	init_pos(scene);
}

// Initialize the values for mlx and the scene
static void	init(t_mlx *mlx, t_scene *scene)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->weapon_img = NULL;
	mlx->ui_img = NULL;
	mlx->nt = NULL;
	mlx->et = NULL;
	mlx->st = NULL;
	mlx->wt = NULL;
	mlx->dt = NULL;
	mlx->ot = NULL;
	mlx->tt = NULL;
	mlx->zt = NULL;
	mlx->size = 0;
	mlx->alt_mode = false;
	init_scene(scene);
	init_img_arr(mlx->weapon_textures.pistol_text, 25);
	init_img_arr(mlx->weapon_textures.shotgun_text, 25);
	init_img_arr(mlx->weapon_textures.ar_text, 25);
	init_img_arr(mlx->weapon_textures.weapon_ui, 3);
	init_img_arr(mlx->weapon_textures.crosshairs, 2);
	init_img_arr(mlx->weapon_textures.font, 10);
	init_img_arr(mlx->weapon_textures.money_font, 11);
	mlx->reloading_anim_running = false;
}

int	initialize_game(char **av, t_mlx *mlx, t_minimap *minimap,
		t_player_data *player)
{
	char	**map;

	XInitThreads();
	init(mlx, &mlx->scene);
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (prnt_err("Error: Initializing mlx"), close_window(mlx, FAILURE),
			1);
	errno = 0;
	if (!scene_handler(av[1], &mlx->scene, mlx))
		return (close_window(mlx, FAILURE), 1);
	map = mlx->scene.opt_map;
	if (find_player(map, player) == FAILURE)
		return (prnt_err("Player not found"));
	minimap->map = map;
	mlx->map = minimap;
	init_data(player, minimap, mlx);
	return (SUCCESS);
}

int	start_game_loop(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	if (!mlx->win)
		return (prnt_err("Error: Initializing mlx window"), close_window(mlx,
				FAILURE), 0);
	image_create(mlx);
	render(mlx);
	mlx_hook(mlx->win, KeyPress, KeyPressMask, key_event, mlx);
	mlx_hook(mlx->win, ButtonPress, ButtonPressMask, shoot_hook, mlx);
	mlx_hook(mlx->win, DestroyNotify, NoEventMask, close_window, mlx);
	mlx_hook(mlx->win, MotionNotify, PointerMotionMask, mouse_move, mlx);
	mlx_loop(mlx->ptr);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_mlx			mlx;
	t_minimap		minimap;
	t_player_data	player;

	if (ac != 2)
		return (prnt_err(strerror(EINVAL)));
	if (initialize_game(av, &mlx, &minimap, &player) != SUCCESS)
		return (1);
	if (start_game_loop(&mlx) != SUCCESS)
		return (1);
	return (0);
}
