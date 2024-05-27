/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descriptor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:25:44 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:26:50 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	reset_fd(t_data *data)
{
	dup2(data->input, STDIN);
	dup2(data->input, STDOUT);
}

void	close_fds(t_data *data)
{
	ft_close(data->pipe_in);
	ft_close(data->pipe_out);
}

void	reset_fds(t_data *data)
{
	data->pipe_in = -1;
	data->pipe_out = -1;
	data->pid = -1;
}
