/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:22:51 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:22:52 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "./data.h"

/* Input */
t_ASTNode	*input(t_data *data);
char		**convert_input(char *s);
t_input		*lexer(char *prompt);
t_ASTNode	*add_ast_node(t_input *input, t_ASTNode *current, int *element);
t_input		*destroy_node(t_input *input);
t_ASTNode	*parse_to_ast(t_input *input);
t_ASTNode	*delete_ast_node(t_ASTNode *current);
void		free_ast(t_ASTNode *head);
void		init_data(t_data *data, char **envp);
t_input		*check_syntax(t_input *input_list);
void		free_input(t_input *input);

/* Environment */
t_env		*init_env_list(char **envp);
char		*get_from_env(t_env *env, char *search);
void		update_env(t_env **head, char *var, char *update_val);
void		create_env(t_env **env, char *var, char *update_val);
void		delete_env(t_env **env, char *search);
void		free_env_list(t_env *head);
bool		var_exists(t_env *env, char *var);
void		increment_shell_lvl(t_env *env);

/* Expander */
void		expander(t_ASTNode *head, t_data *data);

/* Builtins */
int			env_command(t_env *env);
int			get_pwd(void);
void		unset_command(t_env *env, char **strs);
void		cd_command(char **strs, t_env *env);
void		exit_command(t_data *data, char **prompt);
int			echo_command(char **args);
void		export_command(char **strs, t_env *env);

/* Executer */
void		command_executor(t_ASTNode *node, t_data *data);
int			run_binary(char *cmd, t_data *data, char **argv);
void		execute_pipe(t_ASTNode *node, t_data *data);
void		executor(t_ASTNode *node, t_data *data);

/* Redirections */
void		redir(t_data *data, t_ASTNode *node);
void		input_redir(t_data *data, t_ASTNode *node);
char		*here_doc(t_data *data, t_ASTNode *node);

/* Redir Utils */
void		ft_close(int fd);
void		back_to_std(t_data *data);
void		close_fds(t_data *data);
void		reset_fds(t_data *data);

/* File Descriptors */
void		ft_close(int fd);
void		reset_fd(t_data *data);
void		close_fds(t_data *data);
void		reset_fds(t_data *data);

/* Signals */
void		run_signals(int sig);
t_ASTNode	*handle_d(t_data *data);

/* Utils */
void		throw_fatal(char *str, int exit_code);
void		free_array(char **array);
char		*get_process_id(void);
t_ASTNode	*ft_error(char *str);
char		**env_list_to_array(t_env *env);
void		free_env_array(char **env);

#endif
