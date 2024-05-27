/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:04:42 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/27 17:28:26 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

t_stack	*enter_input(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < ac - 1)
	{
		checks(av[i + 1], stack_a);
		stack_a = add_node(stack_a, ft_atoi(av[i + 1]));
		i++;
	}
	return (stack_a);
}

t_stack	*get_input(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	stack_a = enter_input(ac, av);
	return (stack_a);
}
