/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:00:47 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/07 20:59:14 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Fetch character position in a map
int	get_c_pos(char **map, char c, int *y, int *x)
{
	while (map[*y])
	{
		while (map[*y][*x])
		{
			if (map[(*y)][(*x)] == c)
				return (1);
			(*x)++;
		}
		*x = 0;
		(*y)++;
	}
	return (0);
}
