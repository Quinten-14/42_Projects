/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:01:02 by qraymaek          #+#    #+#             */
/*   Updated: 2023/10/17 12:04:53 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*saved_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);
	saved_lst = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew((*f)(lst->content));
		if (!new_lst->next)
		{
			ft_lstclear(&saved_lst, del);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst->next = NULL;
	return (saved_lst);
}
