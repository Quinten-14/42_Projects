/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:26:58 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 23:16:33 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//append one string to another
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dsize;

	dsize = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[dsize] != '\0' && dsize < size)
		dsize++;
	i = dsize;
	while (src[dsize - i] && dsize + 1 < size)
	{
		dst[dsize] = src[dsize - i];
		dsize++;
	}
	if (i < size)
		dst[dsize] = '\0';
	return (i + ft_strlen(src));
}
