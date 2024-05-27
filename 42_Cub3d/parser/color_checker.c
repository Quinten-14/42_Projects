/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:58:53 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/07 18:43:24 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Validate the colors given with the ceiling or floor
int	check_colors(char *arg)
{
	int	i;
	int	comma_count;

	i = -1;
	comma_count = 0;
	while (arg[++i])
	{
		if (arg[i] != ',' && (!ft_isdigit(arg[i]) && i > 0))
			return (prnt_err("Error: Invalid RGB value"), 0);
		else if (arg[i] == ',')
			comma_count++;
	}
	if ((arg[0] != '-' && !ft_isdigit(arg[0])) || comma_count != 2)
		return (prnt_err("Error: Invalid RGB value"), 0);
	return (1);
}

// Check ceiling and floor color data
int	fetch_colors(char *line, t_scene *scene, bool *error)
{
	int	x;

	x = 1;
	while (line[++x] == ' ')
		;
	if (!check_colors(line + x))
		return (*error = true, 0);
	if (line[0] == 'C')
	{
		scene->c_clr = ft_split(line + x, ',');
		if (!scene->c_clr)
			return (*error = true, 0);
		if (!convert_rgb(scene->c_clr, &scene->c))
			return (*error = true, 0);
	}
	else if (line[0] == 'F')
	{
		scene->f_clr = ft_split(line + x, ',');
		if (!scene->f_clr)
			return (*error = true, 0);
		if (!convert_rgb(scene->f_clr, &scene->f))
			return (*error = true, 0);
	}
	return (1);
}

// Convert colors into int array
int	convert_rgb(char **clr_in, int **clr_out)
{
	int	i;

	if (!clr_in[0] || !clr_in[1] || !clr_in[2])
		return (prnt_err("Error: Invalid RGB value"), 0);
	*clr_out = (int *)malloc(sizeof(int) * 3);
	if (!clr_out)
		return (0);
	i = -1;
	while (clr_in[++i])
	{
		(*clr_out)[i] = ft_atoi(clr_in[i]);
		if (0 > (*clr_out)[i] || (*clr_out)[i] > 255)
			return (prnt_err("Error: Out of scope: RGB value"), 0);
	}
	return (1);
}
