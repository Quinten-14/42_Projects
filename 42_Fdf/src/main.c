/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:30:50 by qraymaek          #+#    #+#             */
/*   Updated: 2024/01/06 21:40:09 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../minilibx-linux/mlx.h"

int	main(int ac, char **av)
{
	t_mlx			mlx_win;
	t_map			map;
	t_map_data		data;
	t_map_bounds	bounds;
	t_matrix_arr	arrays;

	check_input(ac, av[1]);
	map = get_sizes(av[1]);
	map_checker(map.width, map.height);
	mlx_win = setup_mlx();
	arrays.matrix = map_to_2d_array(map, av[1]);
	data = calc_tile_size(map, arrays.matrix);
	arrays.iso_matrix = map_iso_2d(map, arrays.matrix, data);
	find_bounds(arrays.iso_matrix, map, &bounds);
	data = calc_offsets(map, data, bounds);
	data.map_ptr = &map;
	draw_map(arrays.iso_matrix, arrays.matrix, &mlx_win, data);
	mlx_put_image_to_window(mlx_win.mlx_ptr, mlx_win.win_ptr,
		mlx_win.img_data.img, 0, 0);
	free_matrix(arrays.matrix, map.height);
	free_iso_matrix(arrays.iso_matrix, map.height);
	mlx_hook(mlx_win.win_ptr, 2, 1L << 0, key_press, &mlx_win);
	mlx_hook(mlx_win.win_ptr, 17, 1L << 0, close_event, &mlx_win);
	mlx_loop(mlx_win.mlx_ptr);
	return (0);
}
