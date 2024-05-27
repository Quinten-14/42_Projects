/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:25:22 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 11:45:06 by lde-paep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

void		handle_c(int num);
void		sigint_handler_in_process(int sig);
void		sigint_handler(int sig);
void		sigquit_handler_in_process(int sig);

t_ASTNode	*handle_d(t_data *data)
{
	ft_putendl_fd("exit ", 2);
	data->exit = true;
	return (NULL);
}
;
void	run_signals(int sig)
{
	if (sig == 1)
	{
		signal(SIGINT, handle_c);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (sig == 2)
	{
		signal(SIGINT, sigint_handler_in_process);
		signal(SIGQUIT, sigquit_handler_in_process);
	}
	else if (sig == 3)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
	}
}
