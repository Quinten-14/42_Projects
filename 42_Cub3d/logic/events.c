/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:40:33 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/16 04:09:27 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Clean MLX image array
static void	clean_img_arr(void *mlx_ptr, t_single_texture *arr, short n)
{
	short	i;

	i = -1;
	if (n == 25)
		i = 0;
	while (++i < n)
		if (arr[i].text_img)
			mlx_destroy_image(mlx_ptr, arr[i].text_img);
}

// Clean various MLX image arrays
static void	clean_weapon_textures(t_mlx *mlx, t_textures *texture)
{
	clean_img_arr(mlx->ptr, texture->pistol_text, 25);
	clean_img_arr(mlx->ptr, texture->shotgun_text, 25);
	clean_img_arr(mlx->ptr, texture->ar_text, 25);
	clean_img_arr(mlx->ptr, texture->weapon_ui, 3);
	clean_img_arr(mlx->ptr, texture->crosshairs, 2);
	clean_img_arr(mlx->ptr, texture->font, 10);
	clean_img_arr(mlx->ptr, texture->money_font, 11);
}

// Clean MLX images
static void	clean_imgs(t_mlx *mlx)
{
	if (mlx->nt)
		mlx_destroy_image(mlx->ptr, mlx->nt);
	if (mlx->et)
		mlx_destroy_image(mlx->ptr, mlx->et);
	if (mlx->st)
		mlx_destroy_image(mlx->ptr, mlx->st);
	if (mlx->wt)
		mlx_destroy_image(mlx->ptr, mlx->wt);
	if (mlx->dt)
		mlx_destroy_image(mlx->ptr, mlx->dt);
	if (mlx->ot)
		mlx_destroy_image(mlx->ptr, mlx->ot);
	if (mlx->tt)
		mlx_destroy_image(mlx->ptr, mlx->tt);
	if (mlx->zt)
		mlx_destroy_image(mlx->ptr, mlx->zt);
	if (mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
	if (mlx->weapon_img)
		mlx_destroy_image(mlx->ptr, mlx->weapon_img);
	if (mlx->ui_img)
		mlx_destroy_image(mlx->ptr, mlx->ui_img);
	clean_weapon_textures(mlx, &mlx->weapon_textures);
}

// Exit in a clean way
int	close_window(t_mlx *mlx, int status)
{
	while (mlx->reloading_anim_running)
		;
	clean_scene(&mlx->scene);
	free_arr((void *)mlx->scene.dpos);
	free_arr((void *)mlx->scene.zpos);
	clean_imgs(mlx);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		mlx->ptr = NULL;
	}
	if (status == FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

// Defines what happens when certain keys are pressed
int	key_event(int keycode, t_mlx *mlx)
{
	t_weapon_data	*weapon;

	weapon = &mlx->map->player->weapon_data;
	if (keycode == ESCAPE)
		close_window(mlx, SUCCESS);
	else if (keycode == W || keycode == A || keycode == S || keycode == D
		|| keycode == LEFT || keycode == RIGHT || keycode == Q || keycode == E)
		move(mlx, mlx->map, mlx->map->player, keycode);
	else if (keycode == I)
		print_debug(mlx);
	else if (keycode == SPACE)
		shoot_hook(1, 1, 1, mlx);
	else if (keycode == M)
		prnt_map(mlx->map->map);
	else if (keycode == R && !mlx->reloading_anim_running
		&& weapon->ammo != weapon->max_ammo && weapon->player_ammo != 0)
		create_reloading_thread(mlx);
	else if (keycode == F)
		interaction_handler(mlx, mlx->map->player, mlx->map);
	else if (keycode == ALT)
		mlx->alt_mode = !mlx->alt_mode;
	else
		printf("Info: key not bound...\n");
	return (0);
}
