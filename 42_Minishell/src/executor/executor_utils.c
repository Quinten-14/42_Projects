/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:20 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:21 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

int	amount_args(t_ASTNode *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->left;
	}
	return (i);
}

char	**arg_arr(t_ASTNode *node)
{
	char		**arr;
	int			i;
	t_ASTNode	*temp_node;

	arr = malloc(sizeof(char *) * (amount_args(node) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	temp_node = node;
	while (temp_node)
	{
		arr[i] = temp_node->content;
		i++;
		temp_node = temp_node->left;
	}
	arr[i] = NULL;
	return (arr);
}

bool	has_pi(t_ASTNode *node)
{
	t_ASTNode	*tmp;

	tmp = node;
	while (tmp)
	{
		if (ft_strcmp(tmp->content, "|") == 0)
			return (true);
		tmp = tmp->right;
	}
	return (false);
}

void	handle_abort_exec(int saved_stdout, int saved_stdin)
{
	ft_putstr_fd("syntax error\n", STDERR);
	dup2(saved_stdout, STDOUT);
	close(saved_stdout);
	dup2(saved_stdin, STDIN);
	close(saved_stdin);
}

void	handle_here_doc(t_ASTNode *node, t_data *data)
{
	char	*here_doc_file;
	int		fd;

	here_doc_file = NULL;
	if (node->right && ft_strcmp(node->right->type, "here_doc") == 0)
		here_doc_file = here_doc(data, node->right);
	if (here_doc_file != NULL)
	{
		fd = open(here_doc_file, O_RDONLY);
		if (fd != -1)
		{
			dup2(fd, STDIN);
			ft_close(fd);
		}
		free(here_doc_file);
	}
}
