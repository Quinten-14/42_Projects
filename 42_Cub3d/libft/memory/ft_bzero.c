/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:57:55 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:46:13 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//reset memory values to 0
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*u;

	u = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		u[i] = '\0';
		i++;
	}
	s = u;
}
