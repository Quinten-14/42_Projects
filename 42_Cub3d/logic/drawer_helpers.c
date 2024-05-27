/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:36:09 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/09 23:04:50 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	image_create(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	mlx->weapon_img = mlx_new_image(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->weapon_addr = mlx_get_data_addr(mlx->weapon_img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	mlx->ui_img = mlx_new_image(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->ui_addr = mlx_get_data_addr(mlx->ui_img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

void	remove_background(t_mlx *mlx, char *path, int color, int pos[2])
{
	t_bg_remover	bg_data;

	bg_data.img = mlx_xpm_file_to_image(mlx->ptr, path, &bg_data.x, &bg_data.y);
	bg_data.data = mlx_get_data_addr(bg_data.img, &bg_data.bpp,
			&bg_data.size_line, &bg_data.endian);
	bg_data.i = 0;
	while (bg_data.i < bg_data.y)
	{
		bg_data.j = 0;
		while (bg_data.j < bg_data.x)
		{
			bg_data.color = *(int *)(bg_data.data + ((bg_data.i * bg_data.x
							+ bg_data.j) * bg_data.bpp / 8));
			if (bg_data.color != color)
				my_mlx_pixel_put(mlx, pos[0] + bg_data.j, pos[1] + bg_data.i,
					bg_data.color);
			bg_data.j++;
		}
		bg_data.i++;
	}
	mlx_destroy_image(mlx->ptr, bg_data.img);
}

// Convert RGB values to a single hexadecimal value
int	rgb_to_hex(int *clr)
{
	int	red;
	int	green;
	int	blue;

	red = clr[0];
	green = clr[1];
	blue = clr[2];
	return (red << 16 | green << 8 | blue);
}

void	better_mlx_string_recursive(t_mlx *mlx, va_list args, int count,
		int y_offset)
{
	int		x_start;
	char	*str;

	if (count == 0)
		return ;
	str = va_arg(args, char *);
	if (str == NULL)
		return ;
	x_start = (SCREEN_WIDTH - ft_strlen(str) * 5) / 2;
	mlx_string_put(mlx->ptr, mlx->win, x_start, (SCREEN_HEIGHT * 0.58)
		+ y_offset, 0x00FF00, str);
	better_mlx_string_recursive(mlx, args, count - 1, y_offset + 20);
}

void	better_mlx_string(t_mlx *mlx, int count, ...)
{
	va_list	args;

	va_start(args, count);
	better_mlx_string_recursive(mlx, args, count, 0);
	va_end(args);
}
