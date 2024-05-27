/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:21:28 by lpeeters          #+#    #+#             */
/*   Updated: 2024/04/06 00:22:06 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//file name validation
int	extension_checker(char *file_name, char *extension)
{
	char	*file_type;

	file_type = ft_strrchr(file_name, '.');
	if (!file_type || ft_strcmp(file_type, extension))
		return (0);
	return (1);
}
