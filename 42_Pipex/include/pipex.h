/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:05:34 by qraymaek          #+#    #+#             */
/*   Updated: 2023/12/04 23:06:18 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*******************/
/*     Includes    */
/*******************/

// basic includes
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// system includes
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

/*******************/
/*      Macros    */
/*******************/

// Error handling defines
# define INPUT_ERROR 1
# define OPEN_ERROR 2
# define PIPE_ERROR 3
# define FORK_ERROR 4
# define PATH_ERROR 5
# define DUP2_ERROR 6
# define CLOSE_ERROR 7
# define EXECVE_ERROR 8
# define CMD_ERROR 9

// Fail statement
# define FAIL -1

// Pipe ends
# define IN 0
# define OUT 1

// File permissions
# define PERMS_R 0
# define PERMS_WCT 1
# define PERMS_WCA 2

/*******************/
/*    Functions    */
/*******************/

// Error handling
void	error(int n);

// File handler
int		file_opener(char *file, int perms);

// Protected operations
void	protected_dup2(int fd, int target_fd);
void	protected_close(int fd);

// Command parsing operations
void	remove_quotes(char **cmd_parsed);

// Fork for last command
void	last_command(char **av, char **envp, int ac);

// Execution function
void	exec(char *cmd, char **envp);

// utils
int		ft_strcmp(char *s1, char *s2);

// Freeing
void	ft_free_tab(char **tab);

// Path handling
char	*my_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);

// Bonus part (here_doc)
void	doc_put(char **av, int *p_fd);

#endif
