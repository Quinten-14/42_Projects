/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:31:05 by qraymaek          #+#    #+#             */
/*   Updated: 2023/12/04 23:05:46 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/pipex.h"

int	file_opener(char *file, int perms)
{
	int	fd_id;

	fd_id = 0;
	if (perms == PERMS_R)
		fd_id = open(file, O_RDONLY, 0677);
	else if (perms == PERMS_WCT)
		fd_id = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0677);
	else if (perms == PERMS_WCA)
		fd_id = open(file, O_WRONLY | O_CREAT | O_APPEND, 0677);
	if (fd_id == FAIL)
		error(OPEN_ERROR);
	return (fd_id);
}

void	protected_dup2(int fd, int target_fd)
{
	if (dup2(fd, target_fd) == FAIL)
		error(DUP2_ERROR);
}

void	protected_close(int fd)
{
	if (close(fd) == FAIL)
		error(CLOSE_ERROR);
}

void	remove_quotes(char **cmd_parsed)
{
	int	i;
	int	j;

	i = 0;
	while (cmd_parsed[i])
	{
		j = 0;
		while (cmd_parsed[i][j])
		{
			if (cmd_parsed[i][j] == '\'')
				ft_memmove(&cmd_parsed[i][j], &cmd_parsed[i][j + 1],
					ft_strlen(&cmd_parsed[i][j + 1]) + 1);
			else
				j++;
		}
		i++;
	}
}

void	last_command(char **av, char **envp, int ac)
{
	pid_t	pid;

	pid = fork();
	if (pid == FAIL)
		error(FORK_ERROR);
	if (!pid)
		exec(av[ac - 2], envp);
}
