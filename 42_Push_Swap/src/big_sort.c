/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:09:20 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/24 23:58:06 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_n)
{
	while (*b != cheapest_n->target && *a != cheapest_n)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_n;

	cheapest_n = find_cheapest(*a);
	if (cheapest_n->above_median && cheapest_n->target->above_median)
		rotate_both_stacks(a, b, cheapest_n);
	else if (!(cheapest_n->above_median) && !(cheapest_n->target->above_median))
		rev_rotate_both(a, b, cheapest_n);
	prep_for_push(a, cheapest_n, 'a');
	prep_for_push(b, cheapest_n->target, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b);
}

static void	min_on_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
