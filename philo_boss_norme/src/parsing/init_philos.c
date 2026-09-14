/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:26:01 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 19:20:48 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	init_philos_mutex(t_philo **philo)
{
	t_data	*data;
	int		i;

	i = 0;
	data = philo[i]->data;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&philo[i]->death_lock, NULL))
		{
			clear_philo_mutex_fail(philo, i, 0);
			return (0);
		}
		if (pthread_mutex_init(&philo[i]->lock_nb_meal_eaten, NULL))
		{
			clear_philo_mutex_fail(philo, i, 1);
			return (0);
		}
		if (pthread_mutex_init(&philo[i]->lock_last_meal_time, NULL))
		{
			clear_philo_mutex_fail(philo, i, 2);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	init_philo(t_philo *philo, int i)
{
	t_data	*data;

	data = philo->data;
	philo->data = data;
	philo->id = i + 1;
	philo->nb_meal_eaten = 0;
	philo->finished_eaten = 0;
	philo->dead = 0;
	philo->last_meal_time = 0;
	philo->right_fork = &data->lock_forks[i];
	if (data->nb_philo != 1)
		philo->left_fork = &data->lock_forks[(i + 1) % data->nb_philo];
	if (data->nb_philo == 1)
		philo->left_fork = NULL;
}

static void	malloc_error(t_data *data, t_philo **philo)
{
	if (philo)
		free(philo);
	clear_data(data);
	write(2, MALLOC_ERROR, ft_strlen(MALLOC_ERROR));
	return ;
}

t_philo	**init_philos(t_data *data)
{
	t_philo	**philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo *) * data->nb_philo);
	if (!philo)
	{
		malloc_error(data, NULL);
		return (NULL);
	}
	while (i < data->nb_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (!philo[i])
		{
			malloc_error(data, philo);
			return (NULL);
		}
		init_philo(philo[i], i);
		i++;
	}
	return (philo);
}
