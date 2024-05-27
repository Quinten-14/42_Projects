/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:57:04 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:57:06 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <pthread.h>
# include <stdbool.h>

typedef enum e_time_code
{
	SECONDS,
	MILLISECOND,
	MICROSECOND,
}						t_time_code;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philo_status;

typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;

typedef struct s_fork
{
	t_mtx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				meals_counter;
	bool				full;
	long				time_last_eat;
	t_fork				*fork1;
	t_fork				*fork2;
	pthread_t			thread_id;
	t_mtx				philo_mtx;
	t_data				*data;
}						t_philo;

struct					s_data
{
	long				amount_philo;
	long				time_die;
	long				time_eat;
	long				time_sleep;
	long				limit_meals;
	long				start_sim;
	bool				end_sim;
	bool				threads_ready;
	t_mtx				data_mutex;
	t_mtx				write_lock;
	t_fork				*forks;
	t_philo				*philos;
	pthread_t			monitor;
	long				threads_running;
};

#endif
