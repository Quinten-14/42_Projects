/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:38 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:38 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

char		*join_char(char *result, char char_to_join);
char		*double_quote(char *result, t_ASTNode *node, t_data *data, int *i);
char		*join_free_old(char *result, char *str_to_join);

// this file goes over the AST tree and finds nodes with the type Var-Expension
// then it will get the var from the env var list.

// Function to replace the node content if var is found
// if not just empty it

// Helper function to extract variable name from the input string
static char	*extract_variable_name(t_ASTNode *node, int *i)
{
	char	*variable_name;
	char	*temp;
	char	*new_variable_name;

	variable_name = ft_strdup("");
	(*i)++;
	while (node->content[*i] && node->content[*i] != '$'
		&& node->content[*i] != '=')
	{
		if (node->content[*i] == '$' || node->content[*i] == '\"'
			|| node->content[*i] == '\'')
		{
			break ;
		}
		temp = ft_substr(node->content, *i, 1);
		new_variable_name = ft_strjoin(variable_name, temp);
		free(variable_name);
		free(temp);
		variable_name = new_variable_name;
		(*i)++;
	}
	(*i)--;
	return (variable_name);
}

char	*var_expansion(t_ASTNode *node, t_env *env, int *i)
{
	char	*variable_name;
	char	*variable_value;

	variable_name = extract_variable_name(node, i);
	variable_value = get_from_env(env, variable_name);
	free(variable_name);
	if (!variable_value || ft_strcmp(variable_value, "-NULL-EMPTY-") == 0)
	{
		free(variable_value);
		variable_value = ft_strdup("");
	}
	return (variable_value);
}

char	*handle_dollar(char *result, t_ASTNode *node, t_data *data, int *i)
{
	char	*expansion;

	if (node->content[*i + 1] == '$')
	{
		expansion = get_process_id();
		result = join_free_old(result, expansion);
		free(expansion);
		(*i)++;
	}
	else if (node->content[*i + 1] == '?')
	{
		expansion = ft_itoa(data->ret);
		result = join_free_old(result, expansion);
		free(expansion);
		(*i)++;
	}
	else if (!node->content[*i + 1])
		result = join_free_old(result, "$");
	else
	{
		expansion = var_expansion(node, data->env_list, i);
		result = join_free_old(result, expansion);
		free(expansion);
	}
	return (result);
}

void	expander_checker(t_ASTNode *node, t_data *data)
{
	int		i;
	char	*result;

	result = ft_strdup("");
	i = 0;
	while (node->content[i])
	{
		if (node->content[i] == '\'')
		{
			while (node->content[++i] != '\'')
				result = join_char(result, node->content[i]);
		}
		else if (node->content[i] == '\"')
			result = double_quote(result, node, data, &i);
		else if (node->content[i] == '$')
			result = handle_dollar(result, node, data, &i);
		else
			result = join_char(result, node->content[i]);
		i++;
	}
	free(node->content);
	node->content = ft_strdup(result);
	free(result);
}

void	expander(t_ASTNode *head, t_data *data)
{
	if (!head)
		return ;
	expander_checker(head, data);
	if (DEBUG_MODE)
		printf("After Expander: %s\n", head->content);
	expander(head->right, data);
	expander(head->left, data);
}
