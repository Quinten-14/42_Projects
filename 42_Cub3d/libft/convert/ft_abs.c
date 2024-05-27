/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:48:55 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:26:54 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//calculate the absolute value of an integer
int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}
