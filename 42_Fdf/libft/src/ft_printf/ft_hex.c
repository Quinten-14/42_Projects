/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:11:46 by qraymaek          #+#    #+#             */
/*   Updated: 2023/10/26 22:11:47 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

void	ft_puthex_printf(unsigned int number, size_t *counter, char *base)
{
	char	*str;

	str = ft_outputhex_printf(number, base);
	ft_putstring_printf(str, counter);
	free(str);
}
