/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:18:32 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/16 18:05:32 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_n;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_n = stack;
		}
		stack = stack->next;
	}
	return (min_n);
}

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*target_n;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->nbr > b->nbr && curr_a->nbr < best_match_index)
			{
				best_match_index = curr_a->nbr;
				target_n = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_n;
		b = b->next;
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
