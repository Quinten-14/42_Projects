/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:22:23 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 23:15:03 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//duplicate a string
char	*ft_strdup(const char *s)
{
	char			*dup;
	unsigned long	i;

	dup = malloc(ft_strlen(s) + 1);
	i = -1;
	if (!dup)
		return (0);
	while (s[++i] != '\0')
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
