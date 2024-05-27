/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:32:10 by wmarien           #+#    #+#             */
/*   Updated: 2023/10/06 22:26:27 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//create a singly linked list
t_list	*ft_lstnew(void *content)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = 0);
	rtn->next = 0;
	rtn->content = content;
	return (rtn);
}
