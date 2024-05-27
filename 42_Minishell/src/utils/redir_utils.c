/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:26:14 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:26:15 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <unistd.h>

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	back_to_std(t_data *data)
{
	dup2(data->input, STDIN);
	dup2(data->output, STDOUT);
}

void	close_fds(t_data *data)
{
	ft_close(data->fd_input);
	ft_close(data->fd_output);
	ft_close(data->pipe_in);
	ft_close(data->pipe_out);
}

void	reset_fds(t_data *data)
{
	data->fd_input = -1;
	data->fd_output = -1;
	data->pipe_in = -1;
	data->pipe_out = -1;
	data->pid = -1;
}
