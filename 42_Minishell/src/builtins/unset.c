/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:23:44 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:23:44 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

static int	unset_syntax(char *str)
{
	int	i;

	if (ft_isdigit(str[0]))
		return (printf("%s: Not a valid identifier\n", str), 0);
	i = -1;
	while (str[++i])
		if (str[i] != '_' && !ft_isalnum(str[i]))
			return (printf("%s: Not a valid identifier\n", str), 0);
	return (1);
}

void	unset_command(t_env *env, char **strs)
{
	int	i;

	(void)env;
	i = 1;
	while (strs[i])
	{
		if (unset_syntax(strs[i]) == 1)
			delete_env(&env, strs[i]);
		i++;
	}
}
