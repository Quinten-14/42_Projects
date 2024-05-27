/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:44 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:45 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include "../../../include/minishell.h"

char	*check_types(char *str, int i, char **arr);

t_input	*new_list(char *str, int i, char **arr)
{
	t_input	*new;

	new = malloc(sizeof(t_input));
	if (!new)
		return (NULL);
	new->content = ft_strdup(str);
	new->type = check_types(str, i, arr);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_input	*destroy_node(t_input *input)
{
	t_input	*tmp;

	if (!input->prev)
	{
		tmp = NULL;
		free(input->content);
		free(input);
		return (NULL);
	}
	tmp = input->prev;
	tmp->next = NULL;
	free(input->content);
	free(input);
	return (tmp);
}

void	free_input(t_input *input)
{
	t_input	*next;

	while (input != NULL)
	{
		next = input->next;
		free(input->content);
		free(input);
		input = next;
	}
}

void	add_node_input(t_input **head, char *str, int i, char **arr)
{
	t_input	*new_node;
	t_input	*current;

	new_node = new_list(str, i, arr);
	if (!new_node)
	{
		return ;
	}
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
	}
}

void	print_list(t_input *head)
{
	t_input	*current;

	current = head;
	while (current != NULL)
	{
		printf("Content: %s, Type: %s\n", current->content, current->type);
		current = current->next;
	}
}
