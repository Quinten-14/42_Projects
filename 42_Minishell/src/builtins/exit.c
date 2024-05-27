/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:23:33 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:23:33 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

static bool	ret_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	exit_command(t_data *data, char **prompt)
{
	bool	numeric;

	data->exit = true;
	ft_putendl_fd("exit ", 2);
	if (prompt[1] && prompt[2])
	{
		data->ret = 1;
		ft_putendl_fd("minishell: exit: too many arguments", 2);
	}
	else if (prompt[1])
	{
		numeric = ret_is_num(prompt[1]);
		if (!numeric)
		{
			data->ret = 2;
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(prompt[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
		}
		else
			data->ret = ft_atoi(prompt[1]);
	}
	else
		data->ret = 0;
}
