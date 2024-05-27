/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:12 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:56:13 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <pthread.h>

void	write_status(t_philo_status status, t_philo *philo)
{
	int		status_mtx;
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->data->start_sim;
	if (get_bool(&philo->philo_mtx, &philo->full))
		return ;
	status_mtx = pthread_mutex_lock(&philo->data->write_lock);
	mutex_error(status_mtx, 2);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		&& !sim_finish(philo->data))
		printf(W "%-6ld" RST " %d has taken a fork\n", elapsed, philo->id);
	else if (status == EATING && !sim_finish(philo->data))
		printf(W "%-6ld" C " %d is eating\n" RST, elapsed, philo->id);
	else if (status == SLEEPING && !sim_finish(philo->data))
		printf(W "%-6ld" RST " %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !sim_finish(philo->data))
		printf(W "%-6ld" RST " %d is thinking\n", elapsed, philo->id);
	else if (status == DIED)
		printf(RED "%-6ld %d died\n" RST, elapsed, philo->id);
	status_mtx = pthread_mutex_unlock(&philo->data->write_lock);
	mutex_error(status_mtx, 3);
}
