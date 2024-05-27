/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:43:39 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/08 15:02:35 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Print error messages
int	prnt_err(char *str)
{
	return (ft_putendl_fd(str, 2), 1);
}

// Loop through gnl to clean the buffer
void	clean_gnl(char *line, int fd)
{
	while (line)
		(free(line), line = NULL, line = get_next_line(fd));
}

// Clean scene paths
static void	clean_paths(t_scene *scene)
{
	if (scene->nt_path != NULL)
		free_arr((void *)scene->nt_path);
	if (scene->et_path != NULL)
		free_arr((void *)scene->et_path);
	if (scene->st_path != NULL)
		free_arr((void *)scene->st_path);
	if (scene->wt_path != NULL)
		free_arr((void *)scene->wt_path);
	if (scene->dt_path != NULL)
		free_arr((void *)scene->dt_path);
	if (scene->ot_path != NULL)
		free_arr((void *)scene->ot_path);
	if (scene->tt_path != NULL)
		free_arr((void *)scene->tt_path);
	if (scene->zt_path != NULL)
		free_arr((void *)scene->zt_path);
}

// Handle resources when an error occured
void	clean_scene(t_scene *scene)
{
	clean_paths(scene);
	if (scene->c_clr != NULL)
		free_arr((void *)scene->c_clr);
	if (scene->f_clr != NULL)
		free_arr((void *)scene->f_clr);
	if (scene->c != NULL)
		free(scene->c);
	if (scene->f != NULL)
		free(scene->f);
	if (scene->map != NULL)
		free_arr((void *)scene->map);
	if (scene->opt_map != NULL)
		free_arr((void *)scene->opt_map);
}
