/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:25:04 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:25:05 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include "../../../include/minishell.h"

void	switch_command(t_input *node)
{
	t_input	*node1;
	t_input	*node2;

	if (node == NULL || node->next == NULL || node->next->next == NULL)
		return ;
	node1 = node->next;
	node2 = node->next->next;
	if (node->prev != NULL)
		node->prev->next = node2;
	node1->prev = node;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node->next = node1;
	node1->next = node2->next;
	node2->prev = node->prev;
	node2->next = node;
	node->prev = node2;
}

int	check_type(char *str)
{
	if (ft_strcmp(str, "here_doc") == 0 || ft_strcmp(str, "pipe") == 0)
		return (1);
	else if (ft_strcmp(str, "great") == 0 || ft_strcmp(str, "dgreat") == 0)
		return (1);
	return (0);
}

int	check_heredoc(t_input *current, t_input *head)
{
	if ((ft_strcmp(current->prev->type, "here_doc") == 0)
		&& (ft_strcmp(current->next->type, "great") == 0))
	{
		free_input(head);
		return (1);
	}
	else if ((ft_strcmp(current->prev->type, "here_doc") == 0)
		&& (ft_strcmp(current->next->type, "less") == 0))
	{
		free_input(head);
		return (1);
	}
	return (0);
}

t_input	*check_syntax(t_input *input_list)
{
	t_input	*current;

	current = input_list;
	while (current && current->next)
	{
		if (current->prev)
		{
			if (check_heredoc(current, input_list) == 1)
				return (NULL);
		}
		if (check_type(current->type) && check_type(current->next->type))
		{
			free_input(input_list);
			return (NULL);
		}
		if ((!current->prev || (ft_strcmp(current->prev->type, "pipe") == 0))
			&& (ft_strcmp(current->type, "less") == 0))
			switch_command(current);
		current = current->next;
	}
	while (current->prev)
		current = current->prev;
	return (current);
}
