/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:24 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:25 by qraymaek         ###   ########.fr       */
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

void	handle_redirections(t_ASTNode *node, t_data *data)
{
	if (node->right && (ft_strcmp(node->right->type, "great") == 0
			|| ft_strcmp(node->right->type, "dgreat") == 0))
		redir(data, node->right);
	if (node->right && ft_strcmp(node->right->type, "less") == 0)
		input_redir(data, node->right);
}

void	handle_command_execution(t_ASTNode *node, t_data *data, char **args)
{
	if (args && ft_strcmp(node->content, "exit") == 0 && has_pi(node) == false)
		exit_command(data, args);
	else if (args && is_builtin(node->content))
		data->ret = exec_builtin(node->content, args, data);
	else if (args)
		data->ret = run_binary(node->content, data, args);
}

void	command_executor(t_ASTNode *node, t_data *data)
{
	char	**args;
	int		saved_stdout;
	int		saved_stdin;

	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	data->abort_exec = false;
	g_sig.abort_exec = false;
	handle_redirections(node, data);
	if (data->abort_exec)
		return ((void)handle_abort_exec(saved_stdout, saved_stdin));
	handle_here_doc(node, data);
	if (g_sig.abort_exec)
		return ;
	if (data->abort_exec)
		return ((void)handle_abort_exec(saved_stdout, saved_stdin));
	args = arg_arr(node);
	handle_command_execution(node, data, args);
	free(args);
	dup2(saved_stdout, STDOUT);
	ft_close(saved_stdout);
	dup2(saved_stdin, STDIN);
	ft_close(saved_stdin);
}

void	executor(t_ASTNode *node, t_data *data)
{
	run_signals(2);
	if (ft_strcmp(node->type, "pipe") == 0)
		execute_pipe(node, data);
	else
		command_executor(node, data);
}
