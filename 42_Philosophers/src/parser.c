/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:55:25 by qraymaek          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:28 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static long	ft_atol(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			throw_error("Entered values can only be positive");
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > INT_MAX)
		throw_error("The max value you can enter is an INT_MAX");
	if (result == 0)
	{
		throw_error("The input must be a digit");
	}
	return (result);
}

void	input_parser(t_data *data, char **av)
{
	data->amount_philo = ft_atol(av[1]);
	data->time_die = ft_atol(av[2]) * 1000;
	data->time_eat = ft_atol(av[3]) * 1000;
	data->time_sleep = ft_atol(av[4]) * 1000;
	if (data->time_die < 6e4 || data->time_eat < 6e4 || data->time_sleep < 6e4)
		throw_error("Timestamp needs to be bigger than 60ms");
	if (av[5])
		data->limit_meals = ft_atol(av[5]);
	else
		data->limit_meals = -1;
}
