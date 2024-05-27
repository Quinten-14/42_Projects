/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:21:42 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:24:52 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//create a singly linked list entry at the end
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (*lst)
	{
		t = ft_lstlast(*lst);
		t->next = &*new;
	}
	else
		*lst = new;
}
