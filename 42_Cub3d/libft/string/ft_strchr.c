/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:58 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 23:14:53 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//search for a character within a string
char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = (char) c;
	while (*s)
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	if (*s == a)
		return ((char *)s);
	return (0);
}
