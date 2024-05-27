/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:55:46 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:48 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <errno.h>
#include <sys/errno.h>

void	thread_error(int status, int code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		throw_error("No resources to create another thread");
	else if (status == EPERM)
		throw_error("The caller does not have appropriate permission");
	else if (status == EINVAL && code == 1)
		throw_error("The value specified by attr is invalid.");
	else if (status == EINVAL && (code == 2 || code == 3))
		throw_error("The value specified by thread is not joinable");
	else if (status == ESRCH)
		throw_error("No thread could be found corresponding to thread id");
	else if (status == EDEADLK)
		throw_error("A deadlock was detected");
}

void	mutex_error(int status, int code)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (code == 2 || code == 3))
		throw_error("The value specified by mutex is invalid");
	else if (EINVAL == status && code == 1)
		throw_error("The value specified by attr is invalid.");
	else if (EDEADLK == status)
		throw_error("A deadlock would occur if the thread was blocked");
	else if (EPERM == status)
		throw_error("The current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		throw_error("The process cannot allocate memory to create mutex.");
	else if (EBUSY == status)
		throw_error("Mutex is locked");
}

void	throw_error(char *str)
{
	printf(RED "%s\n" RST, str);
	exit(EXIT_FAILURE);
}
