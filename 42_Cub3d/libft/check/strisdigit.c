/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:59:23 by lpeeters          #+#    #+#             */
/*   Updated: 2024/04/12 11:30:26 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//check if given string contains only digits
int	strisdigit(char *str)
{
	int	x;

	x = -1;
	while (str[++x])
		if (!ft_isdigit(str[x]))
			return (0);
	return (1);
}
