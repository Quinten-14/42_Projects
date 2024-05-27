/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:25:27 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:25:28 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

void	handle_c(int num)
{
	(void)num;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigint_handler_in_process(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_sig.here_doc_pid > 0)
	{
		kill(g_sig.here_doc_pid, SIGTERM);
		unlink("/tmp/here_doc");
		g_sig.abort_exec = true;
	}
	else
		write(STDOUT_FILENO, "\n", 1);
}

void	sigquit_handler_in_process(int sig)
{
	(void)sig;
	ft_putstr_fd("Quit (core dumped)\n", 2);
}
