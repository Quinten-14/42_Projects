/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:25:14 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:25:14 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include "../../../include/minishell.h"

void		free_input(t_input *input);
t_ASTNode	*create_and_add_nodes(t_input **input, t_ASTNode *curr, int *elem);

void	free_ast(t_ASTNode *head)
{
	if (!head)
		return ;
	free_ast(head->left);
	free_ast(head->right);
	free(head->content);
	free(head->type);
	free(head);
}

t_ASTNode	*create_ast(t_input *input, int *element)
{
	t_ASTNode	*head;

	head = malloc(sizeof(t_ASTNode));
	if (!head)
		return (NULL);
	head->parent = NULL;
	head->left = NULL;
	head->right = NULL;
	head->content = ft_strdup(input->content);
	if (!head->content)
	{
		free(head);
		return (NULL);
	}
	head->type = ft_strdup(input->type);
	if (!head->type)
	{
		free(head->content);
		free(head);
		return (NULL);
	}
	(*element)--;
	return (head);
}

t_input	*traverse_input(t_input *input, int *element)
{
	if (ft_strcmp(input->type, "pipe") == 0)
		return (NULL);
	while (input->next != NULL)
	{
		(*element)++;
		input = input->next;
	}
	if (ft_strcmp(input->type, "pipe") == 0)
		return (NULL);
	while ((input->prev != 0) && (ft_strcmp(input->type, "pipe") != 0))
		input = input->prev;
	return (input);
}

t_ASTNode	*build_ast(t_input *input, int element)
{
	t_ASTNode	*head;
	t_ASTNode	*curr;

	head = create_ast(input, &element);
	curr = head;
	if (DEBUG_MODE)
		printf("\nhead: content = %s, type = %s\n", head->content, head->type);
	input = input->next;
	while (element != 0)
	{
		curr = create_and_add_nodes(&input, curr, &element);
		while ((curr->parent != 0) && (ft_strcmp(curr->content, "|")) != 0)
			curr = curr->parent;
		while ((input->prev != 0) && (ft_strcmp(input->type, "pipe") != 0))
			input = destroy_node(input);
		if ((ft_strcmp(input->type, "pipe") == 0) || (!input->prev))
			input = destroy_node(input);
		if (element == 0)
			break ;
		while ((input->prev != 0) && (ft_strcmp(input->type, "pipe") != 0))
			input = input->prev;
	}
	return (head);
}

t_ASTNode	*parse_to_ast(t_input *input)
{
	t_ASTNode	*head;
	int			element;

	element = 1;
	input = traverse_input(input, &element);
	if (!input)
		return (NULL);
	head = build_ast(input, element);
	if (!head->left && !head->right)
		input = destroy_node(input);
	if (!head)
		return (NULL);
	return (head);
}
