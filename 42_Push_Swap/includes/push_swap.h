/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:52:15 by qraymaek          #+#    #+#             */
/*   Updated: 2023/11/27 16:39:00 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// structs
typedef struct s_stack
{
	long			nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// functions

// checks
void				check_dup(t_stack *stack);
void				check_int(char *str, t_stack *stack_a);
void				check_str(char *str, t_stack *stack_a);
void				checks(char *str, t_stack *stack_a);

// push operations
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);

// swap operations
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

// rotate operations
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rotate_both_stacks(t_stack **a, t_stack **b,
						t_stack *cheapest_n);

// reverse rotate operations
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// stack
t_stack				*stack_last(t_stack *stack);
t_stack				*add_node(t_stack *stack, long nbr);
int					stack_len(t_stack *stack);

// check sorted
bool				sorted(t_stack *stack);

// move utils
t_stack				*find_cheapest(t_stack *stack);
void				prep_for_push(t_stack **stack, t_stack *top_node,
						char stack_name);

// algorithm
void				sort_three(t_stack **a);
t_stack				*find_max(t_stack *stack);
void				current_index(t_stack *stack);
void				set_cheapest(t_stack *stack);
t_stack				*find_min(t_stack *stack);
void				init_nodes_a(t_stack *a, t_stack *b);
void				init_nodes_b(t_stack *a, t_stack *b);
void				sort_stacks(t_stack **a, t_stack **b);

// free
void				free_stack(t_stack **stack);
void				free_on_error(t_stack *stack);

// utils
void				ft_putchar(char c);
void				ft_putnbr(long n);
void				ft_putstr(char *str);
void				ft_putendl(char *str);

// input
t_stack				*get_input(int ac, char **av);

#endif
