/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:25:18 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:25:18 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

void	init_data(t_data *data, char **envp)
{
	data->env = envp;
	data->prompt = NULL;
	data->exit = false;
	data->ret = 0;
	data->input = dup(STDIN);
	data->output = dup(STDOUT);
}

t_ASTNode	*input(t_data *data)
{
	t_input		*input;
	t_ASTNode	*head;

	data->prompt = readline(ANSI_GREEN "Minishell-42: " ANSI_RESET);
	if (data->prompt == NULL)
		return (handle_d(data));
	if (ft_strlen(data->prompt) == 0)
	{
		return (NULL);
	}
	add_history(data->prompt);
	input = lexer(data->prompt);
	if (!input)
		return (ft_error("minishell: syntax error"));
	head = parse_to_ast(input);
	if (!head)
		return (ft_error("minishell: syntax error"));
	expander(head, data);
	return (head);
}
