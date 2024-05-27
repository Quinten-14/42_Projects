/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:57:11 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:57:13 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "./data.h"

void	input_parser(t_data *data, char **av);
void	init_data(t_data *data);
void	thread_error(int status, int code);
void	mutex_error(int status, int code);
void	throw_error(char *str);

void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_long(t_mtx *mutex, long *dest, long value);
long	get_long(t_mtx *mutex, long *value);
void	increase_long(t_mtx *mutex, long *value);
bool	sim_finish(t_data *data);

void	thinking(t_philo *philo, bool pre_sim);

void	write_status(t_philo_status status, t_philo *philo);
void	*monitor_sim(void *data_param);

void	sim_start(t_data *data);

void	wait_threads(t_data *data);
bool	threads_checker(t_mtx *mutex, long *nbr_threads, long philo_amount);
long	gettime(t_time_code time_code);
void	precise_usleep(long usec, t_data *data);
void	philo_desync(t_philo *philo);

void	clean(t_data *data);

#endif
