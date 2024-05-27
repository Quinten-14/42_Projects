/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:51:02 by qraymaek          #+#    #+#             */
/*   Updated: 2024/01/08 17:51:06 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_matrix(int **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

void	free_iso_matrix(int ***iso_matrix, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < rows)
		{
			if (iso_matrix[i][j] != NULL)
			{
				free(iso_matrix[i][j]);
				iso_matrix[i][j] = NULL;
			}
			++j;
		}
		free(iso_matrix[i]);
		iso_matrix[i] = NULL;
		++i;
	}
	free(iso_matrix);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
