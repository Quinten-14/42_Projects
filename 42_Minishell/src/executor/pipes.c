/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:21:41 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:21:43 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

bool	is_builtin(char *command);
int		exec_builtin(char *cmd, char **args, t_data *data);
int		amount_args(t_ASTNode *head);
char	**arg_arr(t_ASTNode *node);
char	*get_path(char *cmd, t_env *env);
bool	has_pi(t_ASTNode *node);
void	handle_abort_exec(int saved_stdout, int saved_stdin);
void	handle_here_doc(t_ASTNode *node, t_data *data);
void	command_executor(t_ASTNode *node, t_data *data);

void	handle_child_process(int pipefd[2], t_ASTNode *node, t_data *data)
{
	dup2(pipefd[1], STDOUT);
	close(pipefd[0]);
	if (ft_strcmp(node->left->type, "pipe") == 0)
		execute_pipe(node->left, data);
	else
		command_executor(node->left, data);
	exit(EXIT_SUCCESS);
}

void	handle_parent_process(int pipefd[2], t_ASTNode *node, t_data *data,
		pid_t pid)
{
	int	status;

	dup2(pipefd[0], STDIN);
	close(pipefd[1]);
	if (node->right && ft_strcmp(node->right->type, "here_doc") == 0)
		handle_here_doc(node->right, data);
	command_executor(node->right, data);
	waitpid(pid, &status, 0);
}

void	execute_pipe(t_ASTNode *node, t_data *data)
{
	int		pipefd[2];
	pid_t	pid;
	int		saved_stdout;
	int		saved_stdin;

	saved_stdout = dup(STDOUT);
	saved_stdin = dup(STDIN);
	if (pipe(pipefd) == -1)
		return ((void)perror("pipe"));
	pid = fork();
	if (pid == -1)
		return ((void)perror("fork"));
	if (pid == 0)
		handle_child_process(pipefd, node, data);
	else
		handle_parent_process(pipefd, node, data, pid);
	dup2(saved_stdout, STDOUT);
	ft_close(saved_stdout);
	dup2(saved_stdin, STDIN);
	ft_close(saved_stdin);
}
