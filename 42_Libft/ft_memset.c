/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:08:45 by qraymaek          #+#    #+#             */
/*   Updated: 2023/10/14 15:08:45 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*placeholder;

	placeholder = (char *)b;
	while (len > 0)
	{
		placeholder[len - 1] = c;
		len--;
	}
	return (b);
}
