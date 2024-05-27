/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:23:48 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:23:48 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

void	add_node_create(t_env **head, char *name, char *value);

// function to get from env

char	*get_from_env(t_env *env, char *search)
{
	char	*path;

	while (env != NULL)
	{
		if (ft_strcmp(env->var_name, search) == 0)
		{
			path = ft_strdup(env->content);
			if (!path)
				throw_fatal("Allocation Failed", 1);
			return (path);
		}
		env = env->next;
	}
	return (NULL);
}

// function to update something in env

void	update_env(t_env **head, char *var, char *update_val)
{
	t_env	*env;

	env = *head;
	while (env)
	{
		if (ft_strcmp(env->var_name, var) == 0)
		{
			free(env->content);
			env->content = ft_strdup(update_val);
			if (env->content == NULL)
				throw_fatal("Allocation Failed", 1);
			if (DEBUG_MODE)
				printf("%s Got Updated to %s\n", env->var_name, env->content);
			return ;
		}
		env = env->next;
	}
	create_env(head, var, update_val);
}

void	create_env(t_env **env, char *var, char *update_val)
{
	while (*env)
	{
		if (ft_strcmp((*env)->var_name, var) == 0)
		{
			update_env(env, var, update_val);
			return ;
		}
		env = &(*env)->next;
	}
	add_node_create(env, var, update_val);
	if (DEBUG_MODE)
		printf("%s Got Created and Assigned to %s\n", var, update_val);
}

void	delete_env(t_env **env, char *search)
{
	t_env	*current;
	t_env	*prev;

	current = *env;
	prev = NULL;
	if (current != NULL && ft_strcmp(current->var_name, search) == 0)
	{
		*env = current->next;
		free(current->var_name);
		free(current->content);
		free(current);
		return ;
	}
	while (current != NULL && ft_strcmp(current->var_name, search) != 0)
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	prev->next = current->next;
	free(current->var_name);
	free(current->content);
	free(current);
}
