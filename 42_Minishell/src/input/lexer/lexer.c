/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-paep <lde-paep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:48 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 08:28:52 by lde-paep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include "../../../include/minishell.h"

void		add_node_input(t_input **head, char *str, int i, char **arr);
t_input		*new_list(char *str, int i, char **arr);
void		print_list(t_input *head);
bool		check_expansion(char *str);

static bool	check_redir(char *str)
{
	if (ft_strcmp(str, "<<") == 0 || ft_strcmp(str, "<") == 0 || ft_strcmp(str,
			">>") == 0 || ft_strcmp(str, ">") == 0)
		return (true);
	else
		return (false);
}

static char	*redir_type(char *str)
{
	if (ft_strcmp(str, "<<") == 0)
		return ("here_doc");
	else if (ft_strcmp(str, "<") == 0)
		return ("less");
	else if (ft_strcmp(str, ">") == 0)
		return ("great");
	else
		return ("dgreat");
}

char	*check_types(char *str, int i, char **arr)
{
	char		*type;
	static bool	command_inline;

	if (i == 0)
		command_inline = false;
	if (check_redir(str) == true)
		type = redir_type(str);
	else if (ft_strcmp(str, "|") == 0)
	{
		type = "pipe";
		command_inline = false;
	}
	else if (i > 0 && (check_redir(arr[i - 1]) == true))
		type = "file";
	else if (check_expansion(str) && ft_strlen(str) != 1)
		type = "Var-Expansion";
	else if (i == 0 || !command_inline)
	{
		type = "command";
		command_inline = true;
	}
	else
		type = "word";
	return (type);
}

t_input	*lexer(char *prompt)
{
	char	**splitted;
	t_input	*input_list;
	int		i;

	input_list = NULL;
	splitted = convert_input(prompt);
	if (!splitted || !splitted[0])
	{
		free_array(splitted);
		return (NULL);
	}
	input_list = new_list(splitted[0], 0, splitted);
	if (!input_list)
		return (NULL);
	i = 1;
	while (splitted[i])
	{
		add_node_input(&input_list, splitted[i], i, splitted);
		i++;
	}
	if (DEBUG_MODE)
		print_list(input_list);
	free_array(splitted);
	return (check_syntax(input_list));
}
