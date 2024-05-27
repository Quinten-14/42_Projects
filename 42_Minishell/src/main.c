/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:26:18 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:26:18 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/minishell.h"

t_signal	g_sig;

// Main Function
int	main(int ac, char **av, char **envp)
{
	t_data		data;
	t_ASTNode	*head;

	(void)ac;
	(void)av;
	reset_fds(&data);
	init_data(&data, envp);
	data.env_list = init_env_list(envp);
	increment_shell_lvl(data.env_list);
	while (data.exit == false)
	{
		run_signals(1);
		data.env = env_list_to_array(data.env_list);
		head = input(&data);
		if (head)
		{
			executor(head, &data);
			free_ast(head);
		}
		free_env_array(data.env);
	}
	if (data.exit == true)
		free_env_list(data.env_list);
	return (data.ret);
}
