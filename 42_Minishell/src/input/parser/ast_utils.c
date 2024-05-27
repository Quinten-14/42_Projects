/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:25:09 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:25:09 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include "../../../include/minishell.h"

t_ASTNode	*create_and_add_nodes(t_input **input, t_ASTNode *curr, int *elem)
{
	while ((*input)->next != NULL)
	{
		curr = add_ast_node(*input, curr, elem);
		*input = (*input)->next;
	}
	curr = add_ast_node(*input, curr, elem);
	return (curr);
}

t_ASTNode	*delete_ast_node(t_ASTNode *current)
{
	t_ASTNode	*parent;

	if (!current)
		return (NULL);
	parent = current->parent;
	if (parent)
	{
		if (parent->left == current)
			parent->left = NULL;
		if (parent->right == current)
			parent->right = NULL;
	}
	free(current->content);
	free(current->type);
	free(current);
	return (parent);
}

t_ASTNode	*add_left_node(t_ASTNode *parent, t_input *input, int *element)
{
	t_ASTNode	*new_node;

	new_node = malloc(sizeof(t_ASTNode));
	if (!new_node)
		return (NULL);
	parent->left = new_node;
	new_node->parent = parent;
	new_node->content = ft_strdup(input->content);
	new_node->type = ft_strdup(input->type);
	new_node->left = NULL;
	new_node->right = NULL;
	(*element)--;
	if (DEBUG_MODE)
		printf("---left---\n");
	return (new_node);
}

t_ASTNode	*add_right_node(t_ASTNode *parent, t_input *input, int *element)
{
	t_ASTNode	*new_node;

	new_node = malloc(sizeof(t_ASTNode));
	if (!new_node)
		return (NULL);
	parent->right = new_node;
	new_node->parent = parent;
	new_node->content = ft_strdup(input->content);
	new_node->type = ft_strdup(input->type);
	new_node->left = NULL;
	new_node->right = NULL;
	(*element)--;
	if (DEBUG_MODE)
		printf("---right---\n");
	return (new_node);
}

t_ASTNode	*add_ast_node(t_input *input, t_ASTNode *current, int *element)
{
	t_ASTNode	*new_node;
	t_ASTNode	*command_node;

	if (!input->prev)
		new_node = add_left_node(current, input, element);
	else if (ft_strcmp(input->prev->content, "|") == 0)
		new_node = add_right_node(current, input, element);
	else if ((ft_strcmp(input->type, "great") == 0) || (ft_strcmp(input->type,
				"dgreat") == 0) || (ft_strcmp(input->type, "here_doc") == 0)
		|| (ft_strcmp(input->type, "less") == 0))
	{
		command_node = current;
		while (ft_strcmp(command_node->type, "command") != 0)
			command_node = command_node->parent;
		new_node = add_right_node(command_node, input, element);
	}
	else
		new_node = add_left_node(current, input, element);
	if (DEBUG_MODE)
		printf("content = %s, type = %s\n", new_node->content, new_node->type);
	return (new_node);
}
