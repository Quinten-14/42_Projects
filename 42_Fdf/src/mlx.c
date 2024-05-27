/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:31:02 by qraymaek          #+#    #+#             */
/*   Updated: 2024/01/06 20:56:39 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../minilibx-linux/mlx.h"

t_mlx	setup_mlx(void)
{
	void	*mlx_ptr;
	t_data	img_data;
	t_mlx	mlx_win;

	mlx_ptr = mlx_init();
	img_data.img = mlx_new_image(mlx_ptr, 1000, 1000);
	img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel,
			&img_data.line_length, &img_data.endian);
	mlx_win.mlx_ptr = mlx_ptr;
	mlx_win.win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "FdF");
	mlx_win.img_data = img_data;
	return (mlx_win);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_press(int keycode, t_mlx *mlx_win)
{
	if (keycode == 65307)
	{
		close_event(mlx_win);
	}
	return (0);
}

// Window close event handler
int	close_event(t_mlx *mlx_win)
{
	mlx_destroy_image(mlx_win->mlx_ptr, mlx_win->img_data.img);
	mlx_destroy_window(mlx_win->mlx_ptr, mlx_win->win_ptr);
	mlx_destroy_display(mlx_win->mlx_ptr);
	free(mlx_win->mlx_ptr);
	exit(0);
	return (0);
}
