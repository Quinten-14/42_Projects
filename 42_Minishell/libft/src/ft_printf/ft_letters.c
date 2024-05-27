/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:46:03 by qraymaek          #+#    #+#             */
/*   Updated: 2023/10/26 16:46:04 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

void	ft_putchar_printf(char c, size_t *counter)
{
	write(1, &c, 1);
	*counter += 1;
}

void	ft_putstring_printf(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_printf(*str, counter);
		str++;
	}
}
