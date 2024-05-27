/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:55:42 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:43 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	clean(t_data *data)
{
	int		status;
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->amount_philo)
	{
		philo = data->philos + i;
		status = pthread_mutex_destroy(&philo->philo_mtx);
		mutex_error(status, 3);
	}
	status = pthread_mutex_destroy(&data->write_lock);
	mutex_error(status, 3);
	status = pthread_mutex_destroy(&data->data_mutex);
	mutex_error(status, 3);
	free(data->forks);
	free(data->philos);
}
