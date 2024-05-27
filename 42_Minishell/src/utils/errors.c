/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:25:40 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/21 01:25:41 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/minishell.h"

void	throw_fatal(char *str, int exit_code)
{
	printf(ANSI_RED "%s\n" ANSI_RESET, str);
	exit(exit_code);
}

t_ASTNode	*ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (NULL);
}
