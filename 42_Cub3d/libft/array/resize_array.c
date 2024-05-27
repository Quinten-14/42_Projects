/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:37:54 by lpeeters          #+#    #+#             */
/*   Updated: 2024/04/19 21:52:38 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//resize the memory of a 2d array
char	**resize_arr(char **arr, size_t y)
{
	char	**new_arr;
	size_t	i;

	new_arr = (char **)malloc(sizeof(char *) * (y + 1));
	if (!new_arr)
		return (NULL);
	if (arr)
	{
		i = -1;
		while (arr[++i] && i < y)
			new_arr[i] = arr[i];
		new_arr[i] = NULL;
		free(arr);
		arr = NULL;
	}
	return (new_arr);
}
