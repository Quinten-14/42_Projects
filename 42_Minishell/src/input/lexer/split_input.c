/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:24:55 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:24:56 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include "../../../include/minishell.h"

static void	check_quotes(char c, bool *sq, bool *dq)
{
	if (c == 39 || c == 34)
	{
		if (c == 39 && *sq == true)
			*sq = false;
		else if (c == 39 && *sq == false && *dq == false)
			*sq = true;
		else if (c == 34 && *dq == true)
			*dq = false;
		else if (c == 34 && *dq == false && *sq == false)
			*dq = true;
	}
}

static int	countlen(char const *str)
{
	int		i;
	int		count;
	bool	sq;
	bool	dq;

	sq = false;
	dq = false;
	i = 0;
	count = 0;
	if (!*str)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] && !sq && !dq)
			count++;
		while (str[i] != ' ' && str[i])
		{
			check_quotes(str[i], &sq, &dq);
			i++;
		}
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, int j)
{
	size_t	size;
	bool	sq;
	bool	dq;

	sq = false;
	dq = false;
	size = 0;
	while (s[j] && (s[j] != ' ' || sq == true || dq == true))
	{
		check_quotes(s[j], &sq, &dq);
		j++;
		size++;
	}
	return (size);
}

static void	ft_free2(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

char	**split_input(char const *s)
{
	int		i;
	int		j;
	char	**str;
	size_t	len;

	i = -1;
	j = 0;
	str = (char **)malloc((countlen(s) + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (++i < countlen(s))
	{
		while (s[j] && s[j] == ' ')
			j++;
		len = ft_wordlen(s, j);
		str[i] = ft_substr(s, j, len);
		if (!str[i])
		{
			ft_free2(str, i);
			return (0);
		}
		j += len;
	}
	str[i] = 0;
	return (str);
}
