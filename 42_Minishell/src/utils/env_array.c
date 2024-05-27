/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:25:36 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:25:37 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

static int	count_env_elements(t_env *env)
{
	int		count;
	t_env	*tmp;

	count = 0;
	tmp = env;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

// Function to create an environment variable string
static char	*create_env_variable_string(const char *var_name,
		const char *content)
{
	char	*tmp_str;
	char	*env_str;

	tmp_str = ft_strjoin(var_name, "=");
	if (!tmp_str)
		return (NULL);
	env_str = ft_strjoin(tmp_str, content);
	free(tmp_str);
	return (env_str);
}

// Function to populate the environment variable array
static void	populate_env_array(char **envp, t_env *env)
{
	int		i;
	t_env	*tmp;
	char	*env_str;

	i = 0;
	tmp = env;
	while (tmp)
	{
		env_str = create_env_variable_string(tmp->var_name, tmp->content);
		if (!env_str)
		{
			while (i > 0)
				free(envp[--i]);
			free(envp);
			return ;
		}
		envp[i] = env_str;
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
}

// Function to create the array from the env list
char	**env_list_to_array(t_env *env)
{
	int		size;
	char	**envp;

	size = count_env_elements(env);
	envp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	populate_env_array(envp, env);
	return (envp);
}

void	free_env_array(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env[i] != NULL)
	{
		free(env[i]);
		i++;
	}
	free(env);
}
