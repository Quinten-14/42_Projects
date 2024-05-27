/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:04:58 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:47:40 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//move a memory area
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tdst;
	char	*tsrc;

	tdst = (char *)dst;
	tsrc = (char *)src;
	if (dst == src)
		return (dst);
	if (tsrc < tdst)
	{
		while (n--)
			*(tdst + n) = *(tsrc + n);
		return (dst);
	}
	while (n--)
		*tdst++ = *tsrc++;
	return (dst);
}
