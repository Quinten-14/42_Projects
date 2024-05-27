/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:15:16 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 23:19:18 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//replace a string within another string with yet another string
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subs;	
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = *(s + start + i);
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
