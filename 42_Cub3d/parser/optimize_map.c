/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:25:13 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/08 22:22:06 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Fetch min and max positions from reachable map part
static void	get_min_max_pos(t_opt *opt, char **map)
{
	int		y;
	int		x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '2' || map[y][x] == '3')
			{
				if (opt->ya > y)
					opt->ya = y;
				if (opt->yz < y)
					opt->yz = y;
				if (opt->xa > x)
					opt->xa = x;
				if (opt->xz < x)
					opt->xz = x;
			}
		}
	}
}

// Surround the map with walls
static void	enclose_map(t_scene *scene, t_opt *opt, int y, int x)
{
	char	**m;

	m = scene->map;
	if (m[y -1][x -1] != '2' && m[y -1][x -1] != '3')
		scene->opt_map[y - opt->ya][x - opt->xa] = '1';
	if (m[y -1][x] != '2' && m[y -1][x] != '3')
		scene->opt_map[y - opt->ya][x - opt->xa + 1] = '1';
	if (m[y -1][x +1] != '2' && m[y -1][x +1] != '3')
		scene->opt_map[y - opt->ya][x - opt->xa + 2] = '1';
	if (m[y][x -1] != '2' && m[y][x -1] != '3')
		scene->opt_map[y - opt->ya + 1][x - opt->xa] = '1';
	if (m[y][x +1] != '2' && m[y][x +1] != '3')
		scene->opt_map[y - opt->ya + 1][x - opt->xa + 2] = '1';
	if (m[y +1][x -1] != '2' && m[y +1][x -1] != '3')
		scene->opt_map[y - opt->ya + 2][x - opt->xa] = '1';
	if (m[y +1][x] != '2' && m[y +1][x] != '3')
		scene->opt_map[y - opt->ya + 2][x - opt->xa + 1] = '1';
	if (m[y +1][x +1] != '2' && m[y +1][x +1] != '3')
		scene->opt_map[y - opt->ya + 2][x - opt->xa + 2] = '1';
}

// Reassign original characters in optimized map
static int	refetch_chars(t_scene *s, t_opt *opt)
{
	int		y;
	int		x;

	get_min_max_pos(opt, s->map);
	s->opt = opt;
	s->height = opt->yz - opt->ya + 1;
	s->width = opt->xz - opt->xa + 1;
	if (!init_opt_map(s))
		return (0);
	y = opt->ya - 2;
	while (s->map[++y] && y <= opt->yz + 1)
	{
		x = opt->xa - 2;
		while (s->map[y][++x] && x <= opt->xz + 1)
		{
			if (s->map[y][x] == '2')
				s->opt_map[y - opt->ya + 1][x - opt->xa + 1] = '0';
			else if (s->map[y][x] == '3')
				s->opt_map[y - opt->ya + 1][x - opt->xa + 1] = 'D';
			if (s->map[y][x] == '2' || s->map[y][x] == '3')
				enclose_map(s, opt, y, x);
		}
	}
	return (1);
}

// Translate positions from original to optimized map
static int	trans_pos(t_mlx *mlx, t_scene *s, t_pos **p, char c)
{
	int	i;

	i = -1;
	while (p && p[++i])
	{
		if (c == 'D' && mlx->dt && p[i]->y - s->opt->ya <= s->height
			&& -2 < p[i]->y - s->opt->ya && p[i]->x - s->opt->xa <= s->width
			&& -2 < p[i]->x - s->opt->xa)
			s->opt_map[p[i]->y - s->opt->ya + 1][p[i]->x - s->opt->xa + 1] = c;
		else if (c == 'Z' && mlx->zt && p[i]->y - s->opt->ya <= s->height
			&& -2 < p[i]->y - s->opt->ya && p[i]->x - s->opt->xa <= s->width
			&& -2 < p[i]->x - s->opt->xa && check_sur(s->opt_map,
				p[i]->y - s->opt->ya + 1, p[i]->x - s->opt->xa + 1))
			s->opt_map[p[i]->y - s->opt->ya + 1][p[i]->x - s->opt->xa + 1] = c;
		else
			return (0);
		p[i]->y = p[i]->y - s->opt->ya + 1;
		p[i]->x = p[i]->x - s->opt->xa + 1;
	}
	return (1);
}

// Reconstruct the map out of only what can be reached
int	opt_map(t_mlx *mlx, t_scene *scene, t_opt *opt)
{
	opt->ya = scene->py;
	opt->yz = scene->py;
	opt->xa = scene->px;
	opt->xz = scene->px;
	if (!refetch_chars(scene, opt))
		return (0);
	scene->opt_map[scene->py - opt->ya + 1][scene->px - opt->xa + 1] = scene->d;
	if (mlx->ot && scene->oy - opt->ya <= scene->height
		&& -2 < scene->oy - opt->ya && scene->ox - opt->xa <= scene->width
		&& -2 < scene->ox - opt->xa && check_sur(scene->opt_map,
			scene->oy - opt->ya + 1, scene->ox - opt->xa + 1))
		scene->opt_map[scene->oy - opt->ya + 1][scene->ox - opt->xa + 1] = 'O';
	else if (scene->map[scene->oy])
		return (0);
	if (mlx->tt && scene->ty - opt->ya <= scene->height
		&& -2 < scene->ty - opt->ya && scene->tx - opt->xa <= scene->width
		&& -2 < scene->tx - opt->xa && check_sur(scene->opt_map,
			scene->ty - opt->ya + 1, scene->tx - opt->xa + 1))
		scene->opt_map[scene->ty - opt->ya + 1][scene->tx - opt->xa + 1] = 'T';
	else if (scene->map[scene->ty])
		return (0);
	if (!trans_pos(mlx, scene, scene->dpos, 'D')
		|| !trans_pos(mlx, scene, scene->zpos, 'Z'))
		return (0);
	return (1);
}
