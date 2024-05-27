/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:01:07 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/22 20:21:13 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Fetch player position
static int	get_p_pos(char **map, int *my, int *mx)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E'
				|| map[y][x] == 'S' || map[y][x] == 'W')
			{
				count += 1;
				if (my)
					*my = y;
				if (mx)
					*mx = x;
			}
		}
	}
	return (count);
}

// Dynamically resize position array
static t_pos	**resize_pos_array(t_pos **pos, size_t n)
{
	t_pos	**new_pos;
	size_t	i;

	new_pos = (t_pos **)malloc(sizeof(t_pos *) * (n + 1));
	if (!new_pos)
		return (NULL);
	if (pos)
	{
		i = -1;
		while (pos[++i] && i < n)
			new_pos[i] = pos[i];
		new_pos[i] = NULL;
		free(pos);
		pos = NULL;
	}
	return (new_pos);
}

// Fetch character positions and store them into the 2 dimensional struct array
static int	store_positions(t_mlx *mlx, int *y, int *x, char c)
{
	int		i;
	t_pos	***pos;

	if (c == 'D')
		pos = &mlx->scene.dpos;
	else if (c == 'Z')
		pos = &mlx->scene.zpos;
	i = 0;
	while (get_c_pos(mlx->scene.map, c, y, x))
	{
		if (c == 'Z' && !mlx->zt)
			return (0);
		*pos = resize_pos_array(*pos, i + 1);
		if (!pos)
			return (0);
		(*pos)[i] = (t_pos *)malloc(sizeof(t_pos));
		(*pos)[i]->y = *y;
		(*pos)[i]->x = (*x)++;
		(*pos)[i]->bought = false;
		(*pos)[++i] = NULL;
	}
	return (1);
}

// Fetch object positions
int	get_positions(t_mlx *mlx, t_scene *s, int *y, int *x)
{
	int		cy;
	int		cx;

	if (get_p_pos(s->map, y, x) != 1
		|| (get_c_pos(s->map, 'O', &s->oy, &s->ox) && !mlx->ot)
		|| (get_c_pos(s->map, 'T', &s->ty, &s->tx) && !mlx->tt))
		return (0);
	s->py = *y;
	s->px = *x;
	s->d = s->map[*y][*x];
	cy = s->oy;
	cx = s->ox + 1;
	if (!check_sur(s->map, s->oy, s->ox) || get_c_pos(s->map, 'O', &cy, &cx))
		return (0);
	cy = s->ty;
	cx = s->tx + 1;
	if (get_c_pos(s->map, 'T', &cy, &cx))
		return (0);
	if (!store_positions(mlx, &s->dy, &s->dx, 'D')
		|| !store_positions(mlx, &s->zy, &s->zx, 'Z'))
		return (0);
	return (1);
}

// Check if a character is unreachable
int	check_sur(char **map, int y, int x)
{
	if (!map || !map[y] || !map[y][x])
		return (1);
	if (x > 0 && (map[y][x - 1] != '1' && map[y][x - 1] != 'O')
		&& map[y][x - 1] != 'T' && map[y][x - 1] != 'Z' && map[y][x - 1] != ' ')
		return (1);
	if (y > 0 && (map[y - 1][x] != '1' && map[y - 1][x] != 'O')
		&& map[y - 1][x] != 'T' && map[y - 1][x] != 'Z' && map[y - 1][x] != ' ')
		return (1);
	if (map[y][x + 1] && (map[y][x + 1] != '1' && map[y][x + 1] != 'O')
		&& map[y][x + 1] != 'T' && map[y][x + 1] != 'Z' && map[y][x + 1] != ' ')
		return (1);
	if (map[y + 1] && (map[y + 1][x] != '1' && map[y + 1][x] != 'O')
		&& map[y + 1][x] != 'T' && map[y + 1][x] != 'Z' && map[y + 1][x] != ' ')
		return (1);
	return (0);
}
