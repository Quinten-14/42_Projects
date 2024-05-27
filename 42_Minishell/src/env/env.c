/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:03 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:04 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

static t_env	*new_list(char *content)
{
	t_env	*env;
	char	**vars;

	vars = ft_split(content, '=');
	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->var_name = ft_strdup(vars[0]);
	env->content = ft_strdup(vars[1]);
	if (!env->content || !env->var_name)
	{
		free(env->content);
		free(env->var_name);
		free(env);
	}
	env->next = NULL;
	env->exported = true;
	free_array(vars);
	return (env);
}

void	add_node(t_env **head, char *content)
{
	t_env	*new;
	t_env	*current;

	new = new_list(content);
	if (!new)
		return ;
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

int	node_exists(char *str, t_env **head)
{
	t_env	*current;

	current = *head;
	while (current->next != NULL)
	{
		if (ft_strcmp(str, current->var_name) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	print_list(t_env *head, bool exported_only)
{
	t_env	*curr;

	curr = head;
	while (curr != NULL)
	{
		if (curr->exported == exported_only)
			printf("env var_name: %s\nenv content: %s\n", curr->var_name,
				curr->content);
		curr = curr->next;
	}
	printf("\nAll Environment Variables Loaded In\n\n");
}

t_env	*init_env_list(char **envp)
{
	t_env	*environment;
	int		i;

	environment = new_list(envp[0]);
	i = 1;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "OLDPWD", 6) == 0))
			add_node(&environment, envp[i]);
		i++;
	}
	if (DEBUG_MODE == true)
		print_list(environment, true);
	return (environment);
}
