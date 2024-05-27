/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:14:08 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:32:11 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//calculate the length of a number
static int	numlen(int n)
{
	long	ctr;

	ctr = 0;
	if (n < 0)
	{
		ctr++;
		n = -n;
	}
	if (n == 0)
		return (ctr = 1);
	while (n > 0)
	{
		ctr++;
		n /= 10;
	}
	return (ctr);
}

//convert an integer to a string
char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == 0)
	{
		str[0] = '0';
	}
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--len] = ((n % 10) + 48);
		n /= 10;
	}
	return (str);
}
