/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:55:37 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:38 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <errno.h>
#include <pthread.h>

static void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	philo_nbr;

	philo_nbr = philo->data->amount_philo;
	philo->fork1 = &forks[(pos + 1) % philo_nbr];
	philo->fork2 = &forks[pos];
	if (philo->id % 2 == 0)
	{
		philo->fork1 = &forks[pos];
		philo->fork2 = &forks[(pos + 1) % philo_nbr];
	}
}

static void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;
	int		status;

	i = -1;
	while (++i < data->amount_philo)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->data = data;
		assign_forks(philo, data->forks, i);
		status = pthread_mutex_init(&philo->philo_mtx, NULL);
		mutex_error(status, 1);
	}
}

void	init_data(t_data *data)
{
	int	i;
	int	status;

	i = -1;
	data->end_sim = false;
	data->threads_ready = false;
	data->threads_running = 0;
	status = pthread_mutex_init(&data->data_mutex, NULL);
	mutex_error(status, 1);
	status = pthread_mutex_init(&data->write_lock, NULL);
	mutex_error(status, 1);
	data->philos = malloc(sizeof(t_philo) * data->amount_philo);
	data->forks = malloc(sizeof(t_fork) * data->amount_philo);
	if (!data->philos || !data->forks)
		throw_error("Malloc Error");
	while (++i < data->amount_philo)
	{
		status = pthread_mutex_init(&data->forks[i].fork, NULL);
		mutex_error(status, 1);
		data->forks[i].fork_id = i;
	}
	philo_init(data);
}
