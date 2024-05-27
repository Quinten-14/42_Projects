/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:51:46 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:46:28 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//allocate memory and initialize values to 0
void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmeb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmeb * size);
	return (ptr);
}
