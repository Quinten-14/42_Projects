/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <wmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:54:50 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:47:54 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//set the values of a memory area
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*u;

	u = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		u[i] = c;
		i++;
	}
	return (s = u);
}
