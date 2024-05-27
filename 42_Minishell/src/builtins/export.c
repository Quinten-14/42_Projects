/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:23:37 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:23:37 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

static int	print_exports(t_env *env)
{
	if (!env)
		return (ERROR);
	while (env && env->next)
	{
		if (env->content != NULL && ft_strcmp(env->content,
				"-NULL-EMPTY-") != 0)
			printf("declare -x %s=\"%s\"\n", env->var_name, env->content);
		else
			printf("declare -x %s\n", env->var_name);
		env = env->next;
	}
	if (env)
	{
		if (env->content != NULL && ft_strcmp(env->content,
				"-NULL-EMPTY-") != 0)
			printf("declare -x %s=\"%s\"\n", env->var_name, env->content);
		else
			printf("declare -x %s\n", env->var_name);
	}
	return (SUCCESS);
}

static int	export_syntax(char *str)
{
	int	i;

	if (ft_isdigit(str[0]))
		return (printf("%s: Not a valid identifier\n", str), 0);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] != '_' && !ft_isalnum(str[i]))
			return (printf("%s: not a valid identifier\n", str), 0);
		i++;
	}
	return (1);
}

// Function to create substr and new_value
static void	create_substrings(char *str, size_t *j, char **substr,
		char **new_value)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	*j = i;
	if (str[i] == '=')
		i++;
	*substr = ft_substr(str, 0, *j);
	if (!(*substr))
		throw_fatal("Allocation Failed", 1);
	if (ft_strlen(str) == *j)
		*new_value = ft_strdup("-NULL-EMPTY-");
	else
		*new_value = ft_substr(str, i, (ft_strlen(str) - i));
	if (!(*new_value) && ft_strlen(str) != *j)
		throw_fatal("Allocation Failed", 1);
}

// Main function to handle export
static void	handle_export(char *str, t_env *env)
{
	size_t	j;
	char	*substr;
	char	*new_value;
	char	*env_val;

	create_substrings(str, &j, &substr, &new_value);
	if (var_exists(env, substr) && ft_strcmp(new_value, "-NULL-EMPTY-") == 0)
	{
		free(substr);
		free(new_value);
		return ;
	}
	env_val = get_from_env(env, substr);
	if (env_val != NULL && ft_strcmp(new_value, "-NULL-EMPTY-") == 0)
	{
		free(substr);
		free(new_value);
		free(env_val);
		return ;
	}
	free(env_val);
	update_env(&env, substr, new_value);
	free(substr);
	free(new_value);
}

void	export_command(char **strs, t_env *env)
{
	int	i;

	if (!strs[1])
		print_exports(env);
	i = 1;
	while (strs[i])
	{
		if (export_syntax(strs[i]))
			handle_export(strs[i], env);
		i++;
	}
}
