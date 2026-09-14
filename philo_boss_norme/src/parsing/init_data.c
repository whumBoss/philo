/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:25:57 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 16:38:22 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static int	data_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->lock_forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->lock_print, NULL) != 0)
	{
		clear_forks_mutex(data);
		return (0);
	}
	if (pthread_mutex_init(&data->lock_end_prog, NULL) != 0)
	{
		clear_forks_mutex(data);
		pthread_mutex_destroy(&data->lock_print);
		return (0);
	}
	return (1);
}

static int	values_validation(t_data data)
{
	return (data.nb_philo > 0 && data.nb_philo <= 200
		&& data.time_die > 0 && data.time_eat > 0 && data.time_sleep > 0 
		&& data.time_die < INT_MAX && data.time_eat < INT_MAX 
		&& data.time_sleep < INT_MAX);
}

static int	data_validation(t_data data, char **av)
{
	if (!values_validation(data))
	{
		write(2, INPUT_ERROR, ft_strlen(INPUT_ERROR));
		return (0);
	}
	if (av[5])
	{
		if (data.nb_meal_per_philo < 0 || data.nb_meal_per_philo > INT_MAX)
		{
			write(2, INPUT_ERROR, ft_strlen(INPUT_ERROR));
			return (0);
		}
	}
	return (1);
}

int	init_data(t_data *data, char **av)
{
	if (!data_validation(*data, av))
		return (0);
	if (!data_mutex(data))
		return (0);
	return (1);
}
