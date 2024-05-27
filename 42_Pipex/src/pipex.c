/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:54:34 by qraymaek          #+#    #+#             */
/*   Updated: 2023/12/04 23:14:10 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/pipex.h"

void	exec(char *cmd, char **envp)
{
	char	**cmd_parsed;
	char	*path;

	cmd_parsed = ft_split(cmd, ' ');
	remove_quotes(cmd_parsed);
	path = get_path(cmd_parsed[0], envp);
	if (execve(path, cmd_parsed, envp) == FAIL)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_parsed[0], 2);
		ft_free_tab(cmd_parsed);
		exit(0);
	}
}

int	check_ac_and_doc(int ac, char **av)
{
	size_t	i;
	char	*str;
	char	*str2;

	str = av[1];
	str2 = "here_doc";
	i = 0;
	if (ac < 5)
		error(INPUT_ERROR);
	while (str[i] || str2[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	if (ac < 6)
		error(INPUT_ERROR);
	return (1);
}

void	doc(char **av)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == FAIL)
		error(PIPE_ERROR);
	pid = fork();
	if (pid == FAIL)
		error(FORK_ERROR);
	if (!pid)
		doc_put(av, p_fd);
	else
	{
		protected_close(p_fd[1]);
		protected_dup2(p_fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	ft_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == FAIL)
		error(PIPE_ERROR);
	pid = fork();
	if (pid == FAIL)
		error(FORK_ERROR);
	if (!pid)
	{
		protected_close(p_fd[0]);
		protected_dup2(p_fd[1], STDOUT_FILENO);
		exec(cmd, envp);
	}
	else
	{
		protected_close(p_fd[1]);
		protected_dup2(p_fd[0], STDIN_FILENO);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fd;
	int	p_fd;
	int	i;

	if (check_ac_and_doc(ac, av) == 1)
	{
		i = 3;
		p_fd = file_opener(av[ac - 1], PERMS_WCA);
		doc(av);
	}
	else
	{
		i = 2;
		fd = file_opener(av[1], PERMS_R);
		p_fd = file_opener(av[ac - 1], PERMS_WCT);
		protected_dup2(fd, STDIN_FILENO);
	}
	while (i < ac - 2)
		ft_pipe(av[i++], envp);
	protected_dup2(p_fd, STDOUT_FILENO);
	last_command(av, envp, ac);
}
