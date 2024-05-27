/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:39:31 by qraymaek          #+#    #+#             */
/*   Updated: 2023/10/26 21:39:40 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

void	ft_putnumber_printf(int number, size_t *counter)
{
	if (number == -2147483648)
	{
		ft_putnumber_printf((number / 10), counter);
		ft_putchar_printf('8', counter);
	}
	else if (number < 0)
	{
		ft_putchar_printf('-', counter);
		ft_putnumber_printf(-number, counter);
	}
	else
	{
		if (number > 9)
			ft_putnumber_printf((number / 10), counter);
		ft_putchar_printf(('0' + number % 10), counter);
	}
}

void	ft_putunsignedint_printf(unsigned int number, size_t *counter)
{
	if (number > 9)
		ft_putunsignedint_printf((number / 10), counter);
	ft_putchar_printf(('0' + number % 10), counter);
}
