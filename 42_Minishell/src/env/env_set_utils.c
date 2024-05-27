/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:23:52 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:23:52 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

void	free_env_list(t_env *head)
{
	t_env	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->var_name);
		free(tmp->content);
		free(tmp);
	}
}

static t_env	*new_list(char *name, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->var_name = ft_strdup(name);
	if (value)
	{
		env->content = ft_strdup(value);
		if (!env->content)
		{
			free(env->var_name);
			free(env);
			return (NULL);
		}
	}
	if (!env->var_name)
	{
		free(env);
		return (NULL);
	}
	env->next = NULL;
	env->exported = true;
	return (env);
}

void	add_node_create(t_env **head, char *name, char *value)
{
	t_env	*new;
	t_env	*current;

	new = new_list(name, value);
	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

bool	var_exists(t_env *env, char *var)
{
	while (env)
	{
		if (ft_strcmp(env->var_name, var) == 0)
			return (true);
		env = env->next;
	}
	return (false);
}
