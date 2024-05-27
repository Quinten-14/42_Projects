/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:16 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:17 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

bool	is_builtin(char *command)
{
	if (ft_strcmp(command, "echo") == 0)
		return (true);
	if (ft_strcmp(command, "cd") == 0)
		return (true);
	if (ft_strcmp(command, "pwd") == 0)
		return (true);
	if (ft_strcmp(command, "env") == 0)
		return (true);
	if (ft_strcmp(command, "export") == 0)
		return (true);
	if (ft_strcmp(command, "unset") == 0)
		return (true);
	return (false);
}

int	exec_builtin(char *cmd, char **args, t_data *data)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(cmd, "echo") == 0)
		ret = echo_command(args);
	if (ft_strcmp(cmd, "cd") == 0)
		cd_command(args, data->env_list);
	if (ft_strcmp(cmd, "pwd") == 0)
		ret = get_pwd();
	if (ft_strcmp(cmd, "env") == 0)
		ret = env_command(data->env_list);
	if (ft_strcmp(cmd, "export") == 0)
		export_command(args, data->env_list);
	if (ft_strcmp(cmd, "unset") == 0)
		unset_command(data->env_list, args);
	return (ret);
}
