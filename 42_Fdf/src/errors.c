/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:31:32 by qraymaek          #+#    #+#             */
/*   Updated: 2024/01/15 12:22:29 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/ft_printf.h"
#include "../include/libft.h"

void	check_input(int ac, char *file_name)
{
	if (ac != 2)
	{
		ft_printf("Usage: ./fdf <map file>");
		exit(0);
	}
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".fdf", 4) != 0)
	{
		ft_printf("Wrong file extension");
		exit(0);
	}
}

void	map_checker(int width, int height)
{
	if (width == 0 || height == 0)
	{
		ft_printf("Failed to load map. Be sure you tried an existing map\n");
		exit(0);
	}
}
