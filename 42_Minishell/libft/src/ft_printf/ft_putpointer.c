/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:13:47 by qraymaek          #+#    #+#             */
/*   Updated: 2023/10/26 19:13:48 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"
#include "../../../include/libft.h"

// use the strlen from libft

// gets the length of not only the string but everything. used later for calloc
// static size_t	ft_len(unsigned long long n, char *base)
size_t	ft_len(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_outputhex_printf(unsigned long long n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	num_len = ft_len(n, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len--;
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

void	ft_putpointer_printf(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_address;

	if (!ptr)
	{
		ft_putstring_printf("(null)", counter);
		return ;
	}
	ptr_address = (unsigned long)ptr;
	ft_putstring_printf("0x", counter);
	str = ft_outputhex_printf(ptr_address, HEX_LOW_BASE);
	ft_putstring_printf(str, counter);
	free(str);
}
