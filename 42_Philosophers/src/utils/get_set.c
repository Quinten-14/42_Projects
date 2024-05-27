/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:55:57 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:59 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <pthread.h>

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	int	status;

	status = pthread_mutex_lock(mutex);
	mutex_error(status, 2);
	*dest = value;
	status = pthread_mutex_unlock(mutex);
	mutex_error(status, 3);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	int		status;
	bool	ret;

	status = pthread_mutex_lock(mutex);
	mutex_error(status, 2);
	ret = *value;
	status = pthread_mutex_unlock(mutex);
	mutex_error(status, 3);
	return (ret);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	int	status;

	status = pthread_mutex_lock(mutex);
	mutex_error(status, 2);
	*dest = value;
	status = pthread_mutex_unlock(mutex);
	mutex_error(status, 3);
}

long	get_long(t_mtx *mutex, long *value)
{
	int		status;
	long	ret;

	status = pthread_mutex_lock(mutex);
	mutex_error(status, 2);
	ret = *value;
	status = pthread_mutex_unlock(mutex);
	mutex_error(status, 3);
	return (ret);
}

bool	sim_finish(t_data *data)
{
	return (get_bool(&data->data_mutex, &data->end_sim));
}
