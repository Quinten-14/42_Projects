/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:03:05 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:47:21 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//copy a memory area
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tdst;
	const char	*tsrc;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	tdst = (char *)dst;
	tsrc = (const char *)src;
	while (n--)
		tdst[n] = tsrc[n];
	return (dst);
}
