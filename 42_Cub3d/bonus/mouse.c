/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:18:40 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/06 20:53:54 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	mouse_move(int x, int y, t_mlx *mlx)
{
	int	old_x;

	if (mlx->alt_mode == true)
		return (mlx_mouse_show(mlx->ptr, mlx->win), SUCCESS);
	mlx_mouse_hide(mlx->ptr, mlx->win);
	old_x = SCREEN_WIDTH / 2;
	if (abs(x - old_x) < MOUSE_MOVE_THRESHOLD)
		return (SUCCESS);
	else if (x < old_x)
		move(mlx, mlx->map, mlx->map->player, LEFT);
	else if (x > old_x)
		move(mlx, mlx->map, mlx->map->player, RIGHT);
	mlx_mouse_move(mlx->ptr, mlx->win, SCREEN_WIDTH / 2, y);
	return (SUCCESS);
}
