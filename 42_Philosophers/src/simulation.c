/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:55:11 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:13 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

void	thinking(t_philo *philo, bool pre_sim)
{
	long	time_eat;
	long	time_think;
	long	time_sleep;

	if (!pre_sim)
		write_status(THINKING, philo);
	if (philo->data->amount_philo % 2 == 0)
		return ;
	time_eat = philo->data->time_eat;
	time_sleep = philo->data->time_sleep;
	time_think = time_eat * 2 - time_sleep;
	if (time_think < 0)
	{
		time_think = 0;
	}
	precise_usleep(time_think * 0.35, philo->data);
}

static void	eat(t_philo *philo)
{
	int	status;

	status = pthread_mutex_lock(&philo->fork1->fork);
	mutex_error(status, 2);
	write_status(TAKE_FIRST_FORK, philo);
	status = pthread_mutex_lock(&philo->fork2->fork);
	mutex_error(status, 2);
	write_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mtx, &philo->time_last_eat, gettime(MILLISECOND));
	philo->meals_counter++;
	write_status(EATING, philo);
	precise_usleep(philo->data->time_eat, philo->data);
	if (philo->data->limit_meals > 0
		&& philo->meals_counter == philo->data->limit_meals)
		set_bool(&philo->philo_mtx, &philo->full, true);
	status = pthread_mutex_unlock(&philo->fork1->fork);
	mutex_error(status, 3);
	status = pthread_mutex_unlock(&philo->fork2->fork);
	mutex_error(status, 3);
}

void	*lone(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->data);
	set_long(&philo->philo_mtx, &philo->time_last_eat, gettime(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->threads_running);
	write_status(TAKE_FIRST_FORK, philo);
	while (!sim_finish(philo->data))
		usleep(200);
	return (NULL);
}

void	*multi_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->data);
	set_long(&philo->philo_mtx, &philo->time_last_eat, gettime(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->threads_running);
	philo_desync(philo);
	while (!sim_finish(philo->data))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->data->time_sleep, philo->data);
		thinking(philo, false);
	}
	return (NULL);
}

void	sim_start(t_data *data)
{
	int	i;

	i = -1;
	if (data->limit_meals == 0)
		return ;
	else if (data->amount_philo == 1)
		thread_error(pthread_create(&data->philos[0].thread_id, NULL, lone,
				&data->philos[0]), 1);
	else
	{
		while (++i < data->amount_philo)
			thread_error(pthread_create(&data->philos[i].thread_id, NULL,
					multi_sim, &data->philos[i]), 1);
	}
	thread_error(pthread_create(&data->monitor, NULL, monitor_sim, data), 1);
	data->start_sim = gettime(MILLISECOND);
	set_bool(&data->data_mutex, &data->threads_ready, true);
	i = -1;
	while (++i < data->amount_philo)
		thread_error(pthread_join(data->philos[i].thread_id, NULL), 2);
	set_bool(&data->data_mutex, &data->end_sim, true);
	thread_error(pthread_join(data->monitor, NULL), 2);
}
