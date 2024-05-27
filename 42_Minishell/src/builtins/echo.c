/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:23:17 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:23:18 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

// so it should be possible to do -nnnnn
// if i do echo -n -n both should be removed
// if i do echo -n -new only the first one should be removed
// if i do echo -new -n none should be removed
// so basically only check the first one but if the second one also is
// -n then it is fine and also check that

static bool	echo_checker(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (false);
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

int	echo_command(char **args)
{
	int		i;
	bool	passed_flags;
	bool	found_flag;

	i = 1;
	passed_flags = false;
	found_flag = false;
	while (args[i])
	{
		if (echo_checker(args[i]) == true && passed_flags == false)
			found_flag = true;
		else
		{
			passed_flags = true;
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
		}
		i++;
	}
	if (found_flag == false)
		write(1, "\n", 1);
	return (0);
}
