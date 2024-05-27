/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:55:32 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:33 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	increase_long(t_mtx *mutex, long *value)
{
	int	status;

	status = pthread_mutex_lock(mutex);
	mutex_error(status, 2);
	(*value)++;
	status = pthread_mutex_unlock(mutex);
	mutex_error(status, 3);
}

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	to_die;

	if (get_bool(&philo->philo_mtx, &philo->full))
		return (false);
	elapsed = gettime(MILLISECOND) - get_long(&philo->philo_mtx,
			&philo->time_last_eat);
	to_die = philo->data->time_die / 1e3;
	if (elapsed > to_die)
		return (true);
	return (false);
}

void	*monitor_sim(void *data_param)
{
	t_data	*data;
	int		i;

	data = (t_data *)data_param;
	while (!threads_checker(&data->data_mutex, &data->threads_running,
			data->amount_philo))
		;
	while (!sim_finish(data))
	{
		i = -1;
		while (++i < data->amount_philo && !sim_finish(data))
		{
			if (philo_died(data->philos + i))
			{
				set_bool(&data->data_mutex, &data->end_sim, true);
				write_status(DIED, data->philos + i);
			}
		}
	}
	return (NULL);
}
