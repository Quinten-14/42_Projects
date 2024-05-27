/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:24:56 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/17 18:25:07 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	tmp->prev = NULL;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pb\n");
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr("pa\n");
}
