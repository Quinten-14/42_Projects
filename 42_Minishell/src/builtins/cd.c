/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-paep <lde-paep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:23:11 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 08:35:16 by lde-paep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

// Function to handle changing directory and updating environment variables
static void	change_directory_and_update_env(char *path, char *old_pwd,
		t_env **env)
{
	char	*new_pwd;

	update_env(env, "OLDPWD", old_pwd);
	if (chdir(path) < 0)
	{
		perror("cd");
		free(path);
		free(old_pwd);
		return ;
	}
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
	{
		perror("cd");
		free(path);
		free(old_pwd);
		return ;
	}
	update_env(env, "PWD", new_pwd);
	free(path);
	free(new_pwd);
	free(old_pwd);
}

// Main function to handle cd command
void	cd_command(char **strs, t_env *env)
{
	char	*path;
	char	*old_pwd;

	path = NULL;
	if (strs[1] != NULL && strs[2] != NULL)
		return ((void)printf("Too many arguments\n"));
	if (strs[1] != NULL && (strs[1][0] == '-' && strs[1][1]))
		return ((void)printf("Flags are not supported\n"));
	if (strs[1] == NULL)
		path = get_from_env(env, "HOME");
	else if (ft_strcmp(strs[1], "~") == 0)
		path = get_from_env(env, "HOME");
	else if (ft_strcmp(strs[1], "-") == 0)
		path = get_from_env(env, "OLDPWD");
	else if (strs[1][0] == '~' && strs[1][1] == '/')
		path = ft_strjoin(get_from_env(env, "HOME"), strs[1] + 1);
	else
		path = ft_strdup(strs[1]);
	if (!path)
		return ((void)perror("cd"));
	old_pwd = get_from_env(env, "PWD");
	change_directory_and_update_env(path, old_pwd, &env);
}

// removed free oldpwd and pwd from cd command function and moved to
// change directory and update env function
