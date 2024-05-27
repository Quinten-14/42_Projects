/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:13:28 by lpeeters          #+#    #+#             */
/*   Updated: 2024/04/12 16:47:26 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//free the memory of an int array
void	free_int_arr(int **arr, size_t size)
{
	size_t	i;

	if (!arr)
		return ;
	i = -1;
	while (++i < size)
		free(arr[i]);
	free(arr);
}
