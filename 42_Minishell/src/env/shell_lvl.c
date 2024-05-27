/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:07 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:08 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

void	increment_shell_lvl(t_env *env)
{
	int		curr_lvl;
	char	*lvl;
	char	*shlvl;

	shlvl = get_from_env(env, "SHLVL");
	curr_lvl = ft_atoi(shlvl);
	free(shlvl);
	if (!curr_lvl)
		return ((void)update_env(&env, "SHLVL", "1"));
	if (curr_lvl < 0)
		return ((void)update_env(&env, "SHLVL", "1"));
	if (curr_lvl > 99)
	{
		lvl = ft_itoa(curr_lvl % 100 + 1);
		update_env(&env, "SHLVL", lvl);
		return ((void)free(lvl));
	}
	lvl = ft_itoa(curr_lvl + 1);
	update_env(&env, "SHLVL", lvl);
	return ((void)free(lvl));
}
