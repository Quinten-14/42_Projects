/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:40:54 by qraymaek          #+#    #+#             */
/*   Updated: 2023/12/04 18:31:20 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/libft.h"

void	error(int n)
{
	if (n == INPUT_ERROR)
		ft_putstr_fd("input: Incorrect number of arguments\n", 1);
	else if (n == OPEN_ERROR)
		perror("open");
	else if (n == FORK_ERROR)
		perror("fork");
	else if (n == PIPE_ERROR)
		perror("pipe");
	else if (n == CMD_ERROR)
		perror("command");
	else if (n == EXECVE_ERROR)
		perror("execve");
	else if (n == DUP2_ERROR)
		perror("dup2");
	else if (n == CLOSE_ERROR)
		perror("close");
	else
		ft_putstr_fd("Unkown error\n", 1);
	exit(EXIT_FAILURE);
}
