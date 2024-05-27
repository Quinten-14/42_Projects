/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:51 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:52 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include "../../../include/minishell.h"

char	**split_input(char const *s);
void	handle_special(char *str, char *new_str, int *i, int *j);
int		handle_single_quote(char *str, char *new_str, int *i, int *j);
int		handle_double_quote(char *str, char *new_str, int *i, int *j);

int	count_size(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strchr("<>|;&$", str[i]))
			len += 2;
		i++;
	}
	return (len + i + 1);
}

int	adjust_str(char *str, char *new_str, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1 && str[j])
	{
		if (str[j] == 34)
		{
			if (!handle_double_quote(str, new_str, &i, &j))
				return (0);
		}
		else if (str[j] == 39)
		{
			if (!handle_single_quote(str, new_str, &i, &j))
				return (0);
		}
		else if (ft_strchr("|<>;&", str[j]))
			handle_special(str, new_str, &i, &j);
		else
			new_str[i++] = str[j++];
	}
	return (1);
}

char	**convert_input(char *str)
{
	int		size;
	char	*new_str;
	char	**split;

	size = count_size(str);
	new_str = ft_calloc(sizeof(char), size);
	if (!new_str)
		return (0);
	if (!adjust_str(str, new_str, size))
	{
		free(new_str);
		return (0);
	}
	split = split_input(new_str);
	free(new_str);
	if (!split)
		return (0);
	return (split);
}
