/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:56:14 by lpeeters          #+#    #+#             */
/*   Updated: 2023/11/21 20:12:22 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//join two strings into an array
char	**mk_arr(char *s1, char *s2)
{
	char	**arr;

	if (!s1 || !s2)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * 3);
	if (!arr)
		return (NULL);
	arr[0] = ft_strdup(s1);
	arr[1] = ft_strdup(s2);
	if (!arr[0] || !arr[1])
		return (NULL);
	return (arr[2] = NULL, arr);
}
