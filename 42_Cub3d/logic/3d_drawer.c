/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:36:23 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/09 22:08:51 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_pixel_color_hex(void *img_ptr, int x, int y)
{
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;

	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	return ((*(int *)(img_data + (y * size_line + x * (bpp / 8)))));
}

void	texture_setup(t_ray_data *data)
{
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)TEXTURE_SIZE);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = TEXTURE_SIZE - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = TEXTURE_SIZE - data->tex_x - 1;
	data->step = 1.0 * TEXTURE_SIZE / data->line_height;
}

static int	wall_color_getter(t_mlx *mlx, t_ray_data *data, int tex_y)
{
	if (data->wall_dir == NORTH && data->hit_object == WALL)
		return (get_pixel_color_hex(mlx->nt, data->tex_x, tex_y));
	else if (data->wall_dir == EAST && data->hit_object == WALL)
		return (get_pixel_color_hex(mlx->et, data->tex_x, tex_y));
	else if (data->wall_dir == SOUTH && data->hit_object == WALL)
		return (get_pixel_color_hex(mlx->st, data->tex_x, tex_y));
	else if (data->wall_dir == WEST && data->hit_object == WALL)
		return (get_pixel_color_hex(mlx->wt, data->tex_x, tex_y));
	else if (data->hit_object == DOOR)
		return (get_pixel_color_hex(mlx->dt, data->tex_x, tex_y));
	else if (data->hit_object == SHOTGUN_BUY)
		return (get_pixel_color_hex(mlx->ot, data->tex_x, tex_y));
	else if (data->hit_object == AR_BUY)
		return (get_pixel_color_hex(mlx->tt, data->tex_x, tex_y));
	else if (data->hit_object == ENEMY)
		return (get_pixel_color_hex(mlx->zt, data->tex_x, tex_y));
	else
		return (0);
}

void	draw_wall(t_mlx *mlx, t_ray_data *data, int x)
{
	double	tex_pos;
	int		tex_y;
	int		color;

	tex_pos = (data->draw_start - SCREEN_HEIGHT / 2. + data->line_height / 2.)
		* data->step;
	while (data->draw_start < data->draw_end)
	{
		tex_y = (int)tex_pos & (TEXTURE_SIZE - 1);
		color = wall_color_getter(mlx, data, tex_y);
		my_mlx_pixel_put(mlx, x, data->draw_start, color);
		data->draw_start++;
		tex_pos += data->step;
	}
}

void	draw_x_line(t_mlx *mlx, t_ray_data *data, int x)
{
	int	i;

	i = 0;
	while (i < data->draw_start)
	{
		my_mlx_pixel_put(mlx, x, i, rgb_to_hex(mlx->scene.c));
		i++;
	}
	draw_wall(mlx, data, x);
	i = data->draw_end;
	while (i < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(mlx, x, i, rgb_to_hex(mlx->scene.f));
		i++;
	}
}
