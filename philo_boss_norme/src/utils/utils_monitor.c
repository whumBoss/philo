/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:26:21 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 16:23:52 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *philo)
{
	if (read_value(&philo->death_lock, &philo->dead))
	{
		print_action(philo, "died", 1);
		return (1);
	}
	return (0);
}

int	philos_finished(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->philo_finish_eaten_count == data->nb_philo)
	{
		update_value(&data->lock_end_prog, &data->end_prog);
		return (1);
	}
	return (0);
}

int	philo_eaten_all_meal(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (read_value(&philo->lock_nb_meal_eaten, &philo->nb_meal_eaten)
		== data->nb_meal_per_philo && !philo->finished_eaten)
	{
		philo->finished_eaten = 1;
		return (1);
	}
	return (0);
}

long	last_meal_time_ago(t_philo *philo)
{
	long	time;
	t_data	*data;

	data = philo->data;
	time = get_time_of_day() - data->start_time;
	return (time - read_last_meal(philo));
}

int	print_action(t_philo *philo, char *str, int flag)
{
	t_data	*data;
	long	current_time;
	long	time;

	data = philo->data;
	pthread_mutex_lock(&data->lock_print);
	if (read_value(&data->lock_end_prog, &data->end_prog))
	{
		pthread_mutex_unlock(&data->lock_print);
		return (0);
	}
	current_time = get_time_of_day();
	time = current_time - data->start_time;
	printf("%ld : philo %d %s\n", time, philo->id, str);
	if (flag == 1)
		update_value(&data->lock_end_prog, &data->end_prog);
	pthread_mutex_unlock(&data->lock_print);
	return (1);
}
