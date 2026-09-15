/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:25:36 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 15:36:33 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	taking_scd_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
	return (1);
}

static int	taking_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
	if (!philo->left_fork && data->nb_philo == 1)
	{
		custom_sleep(data, data->time_die);
		pthread_mutex_lock(&philo->death_lock);
		philo->dead = 1;
		pthread_mutex_unlock(&philo->death_lock);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	taking_scd_fork(philo);
	return (1);
}

int	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (read_value(&data->lock_end_prog, &data->end_prog))
		return (0);
	if (!taking_forks(philo))
		return (0);
	print_action(philo, "is eating");
	update_last_meal(philo);
	update_value(&philo->lock_nb_meal_eaten, &philo->nb_meal_eaten);
	custom_sleep(data, data->time_eat);
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	return (1);
}

int	thinking(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (read_value(&data->lock_end_prog, &data->end_prog))
		return (0);
	print_action(philo, "is thinking");
	custom_sleep(data, data->time_sleep);
	return (1);
}

int	sleeping(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (read_value(&data->lock_end_prog, &data->end_prog))
		return (0);
	print_action(philo, "is sleeping");
	if (data->nb_philo % 2 != 0)
		custom_sleep(data, 100);
	return (1);
}
