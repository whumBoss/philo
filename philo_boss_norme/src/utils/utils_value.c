/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:26:25 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 15:26:26 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_value(pthread_mutex_t *mutex, int *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
}

int	read_value(pthread_mutex_t *mutex, int *value)
{
	int	read_value;

	pthread_mutex_lock(mutex);
	read_value = *value;
	pthread_mutex_unlock(mutex);
	return (read_value);
}

void	update_last_meal(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&philo->lock_last_meal_time);
	philo->last_meal_time = get_time_of_day() - data->start_time;
	pthread_mutex_unlock(&philo->lock_last_meal_time);
}

long	read_last_meal(t_philo *philo)
{
	long	last_meal_time;

	pthread_mutex_lock(&philo->lock_last_meal_time);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->lock_last_meal_time);
	return (last_meal_time);
}
