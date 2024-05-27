/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:03 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:56:06 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <sys/time.h>

void	wait_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->threads_ready))
		;
}

long	gettime(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		throw_error("GTOD failed");
	if (SECONDS == time_code)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLISECOND == time_code)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND == time_code)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		throw_error("Wrong input to gettime");
	return (1);
}

void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;

	start = gettime(MICROSECOND);
	while (gettime(MICROSECOND) - start < usec)
	{
		if (sim_finish(data))
			break ;
		elapsed = gettime(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
		{
			while (gettime(MICROSECOND) - start < usec)
				;
		}
	}
}

bool	threads_checker(t_mtx *mutex, long *nbr_threads, long philo_amount)
{
	bool	ret;
	int		status;

	ret = false;
	status = pthread_mutex_lock(mutex);
	mutex_error(status, 2);
	if (*nbr_threads == philo_amount)
		ret = true;
	status = pthread_mutex_unlock(mutex);
	mutex_error(status, 3);
	return (ret);
}

void	philo_desync(t_philo *philo)
{
	if (philo->data->amount_philo % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->data);
	}
	else
	{
		if (philo->id % 2 == 0)
			thinking(philo, true);
	}
}
