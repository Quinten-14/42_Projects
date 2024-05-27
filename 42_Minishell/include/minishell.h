/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:22:58 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:22:59 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* Includes Section */

# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "./data.h"
# include "./functions.h"

/* Defines Section */

# ifndef DEBUG_MODE
#  define DEBUG_MODE false
# endif

/* Colors */
# define ANSI_RED "\x1b[31m"
# define ANSI_GREEN "\x1b[32m"
# define ANSI_YELLOW "\x1b[33m"
# define ANSI_BLUE "\x1b[34m"
# define ANSI_MAGENTA "\x1b[35m"
# define ANSI_CYAN "\x1b[36m"
# define ANSI_WHITE "\x1b[37m"
# define ANSI_RESET "\x1b[0m"

/* Global Variable */

extern t_signal	g_sig;

#endif
