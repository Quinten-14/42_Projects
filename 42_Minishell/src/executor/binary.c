/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:12 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:13 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// if i make a hero doc i should make it so it is in a child process.
// this way it is easier to handle the signals

static char	*check_executable(char *cmd, char **allpath)
{
	char	*exec_path;
	char	*path_part;
	char	*exec;
	int		i;

	exec_path = NULL;
	i = -1;
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			exec_path = exec;
			break ;
		}
		free(exec);
	}
	return (exec_path);
}

char	*get_path(char *cmd, t_env *env)
{
	char	*path;
	char	**allpath;
	char	*exec_path;

	path = get_from_env(env, "PATH");
	exec_path = NULL;
	if (path)
	{
		allpath = ft_split(path, ':');
		free(path);
		exec_path = check_executable(cmd, allpath);
		free_array(allpath);
	}
	return (exec_path);
}

// Function to execute the command using execve
static void	execute_command(char *cmd, char **argv, t_data *data, char *path)
{
	if (ft_strchr(cmd, '/') != NULL)
		execve(cmd, argv, data->env);
	else
	{
		if (path)
			execve(path, argv, data->env);
	}
	perror("Error executing binary");
	exit(EXIT_FAILURE);
}

// Function to run the binary command
int	run_binary(char *cmd, t_data *data, char **argv)
{
	pid_t	pid;
	int		status;
	char	*path;

	pid = fork();
	if (pid == -1)
		return (perror("Fork Failed"), EXIT_FAILURE);
	if (pid == 0)
	{
		path = get_path(cmd, data->env_list);
		execute_command(cmd, argv, data, path);
	}
	else
	{
		ft_close(data->pipe_in);
		ft_close(data->pipe_out);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (EXIT_FAILURE);
	}
	return (WEXITSTATUS(status));
}
