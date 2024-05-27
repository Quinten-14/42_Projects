/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:36:37 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 22:03:58 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sizes_matrix(t_minimap *map)
{
	int	i;
	int	j;
	int	max_width;

	i = 0;
	max_width = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (j > max_width)
			max_width = j;
		i++;
	}
	map->map_x = max_width;
	map->map_y = i;
}

// function to replace the long list of raycaster hit registers
// hit point is saved in the dda algo function togheter with setting the
// hit to true
// this is just to see what object it hit

bool	found_hit(t_ray_data *data, char **map, int x, int y)
{
	if (map[x][y] == '1')
		data->hit_object = WALL;
	else if (map[x][y] == 'D')
		data->hit_object = DOOR;
	else if (map[x][y] == 'O')
		data->hit_object = SHOTGUN_BUY;
	else if (map[x][y] == 'T')
		data->hit_object = AR_BUY;
	else if (map[x][y] == 'Z')
		data->hit_object = ENEMY;
	else
		return (false);
	data->hit_x = x;
	data->hit_y = y;
	return (true);
}

bool	found_single(t_ray_data *data, char **map, int x, int y)
{
	if (map[x][y] == '1')
		data->hit_object = WALL;
	else if (map[x][y] == 'D')
		data->hit_object = DOOR;
	else if (map[x][y] == '2')
		data->hit_object = OPEN_DOOR;
	else if (map[x][y] == 'O')
		data->hit_object = SHOTGUN_BUY;
	else if (map[x][y] == 'T')
		data->hit_object = AR_BUY;
	else if (map[x][y] == 'Z')
		data->hit_object = ENEMY;
	else
		return (false);
	data->hit_x = x;
	data->hit_y = y;
	return (true);
}

void	create_reloading_thread(t_mlx *mlx)
{
	pthread_t	thread_id;

	pthread_create(&thread_id, NULL, reload_weapon_thread, mlx);
	pthread_detach(thread_id);
}

char	*get_texture_filename(char *path, int frame_number)
{
	char	*filename;
	char	*temp;
	char	*temp1;
	char	*frame_str;

	frame_str = ft_itoa(frame_number);
	if (frame_number < 10)
	{
		temp1 = ft_strjoin(path, "0");
		temp = ft_strjoin(temp1, frame_str);
		free(temp1);
	}
	else
		temp = ft_strjoin(path, frame_str);
	filename = ft_strjoin(temp, ".xpm");
	free(temp);
	free(frame_str);
	return (filename);
}
