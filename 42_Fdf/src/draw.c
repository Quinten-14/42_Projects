/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:30:43 by qraymaek          #+#    #+#             */
/*   Updated: 2024/01/06 21:27:15 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	plot_point(int x, int y, t_mlx *mlx_win, int color)
{
	my_mlx_pixel_put(&mlx_win->img_data, x, y, color);
}

void	draw_line(t_line_params *line_param, t_mlx *mlx_param, int color)
{
	int	e2;

	while (line_param->x0 != line_param->x1 || line_param->y0 != line_param->y1)
	{
		plot_point(line_param->x0, line_param->y0, mlx_param, color);
		e2 = 2 * line_param->err;
		if (e2 > -line_param->dy)
		{
			line_param->err -= line_param->dy;
			line_param->x0 += line_param->x_direction;
		}
		if (e2 < line_param->dx)
		{
			line_param->err += line_param->dx;
			line_param->y0 += line_param->y_direction;
		}
	}
}

void	draw_horizontal(int ***iso_matrix, int **matrix, t_mlx *mlx_win,
		t_map_data data)
{
	t_line_params	line_param;
	int				i;
	int				j;

	i = 0;
	while (i < data.map_ptr->height)
	{
		j = 0;
		while (j < data.map_ptr->width - 1)
		{
			line_param.x0 = iso_matrix[0][i][j] + data.offset_x;
			line_param.y0 = iso_matrix[1][i][j] + data.offset_y;
			line_param.x1 = iso_matrix[0][i][j + 1] + data.offset_x;
			line_param.y1 = iso_matrix[1][i][j + 1] + data.offset_y;
			init_params(&line_param);
			draw_line(&line_param, mlx_win, get_color(matrix[i][j]));
			j++;
		}
		i++;
	}
}

void	draw_vertical(int ***iso_matrix, int **matrix, t_mlx *mlx_win,
		t_map_data data)
{
	t_line_params	line_param;
	int				i;
	int				j;

	i = 0;
	while (i < data.map_ptr->height - 1)
	{
		j = 0;
		while (j < data.map_ptr->width)
		{
			line_param.x0 = iso_matrix[0][i][j] + data.offset_x;
			line_param.y0 = iso_matrix[1][i][j] + data.offset_y;
			line_param.x1 = iso_matrix[0][i + 1][j] + data.offset_x;
			line_param.y1 = iso_matrix[1][i + 1][j] + data.offset_y;
			init_params(&line_param);
			draw_line(&line_param, mlx_win, get_color(matrix[i][j]));
			j++;
		}
		i++;
	}
}

void	draw_map(int ***iso_matrix, int **matrix, t_mlx *mlx_win,
		t_map_data data)
{
	draw_horizontal(iso_matrix, matrix, mlx_win, data);
	draw_vertical(iso_matrix, matrix, mlx_win, data);
}
