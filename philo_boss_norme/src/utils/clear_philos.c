/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 19:06:38 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 19:21:50 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	clear_philos(t_philo **philos, int nb)
{
	int		i;
	t_data	*data;

	i = 0;
	data = philos[i]->data;
	while (i < nb)
	{
		pthread_join(philos[i]->philo, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&philos[i]->lock_nb_meal_eaten);
		pthread_mutex_destroy(&philos[i]->lock_last_meal_time);
		pthread_mutex_destroy(&philos[i]->death_lock);
		if (philos[i])
			free(philos[i]);
		i++;
	}
	free(philos);
	return ;
}

void	clear_nb_philos(t_philo **philos, int nb)
{
	t_data	*data;
	int		i;

	i = 0;
	data = philos[i]->data;
	if (nb == 0)
	{
		while (i < data->nb_philo)
		{
			free(philos[i]);
			i++;
		}
		free(philos);
	}
	else if (nb > 0)
		clear_philos(philos, nb);
	return ;
}

void	clear_philo_mutex_fail(t_philo **philo, int i, int flag)
{
	t_data	*data;

	data = philo[0]->data;
	if (flag == 1)
		pthread_mutex_destroy(&philo[i]->death_lock);
	if (flag == 2)
	{
		pthread_mutex_destroy(&philo[i]->death_lock);
		pthread_mutex_destroy(&philo[i]->lock_nb_meal_eaten);
	}
	clear_data(data);
	clear_nb_philos(philo, i);
	return ;
}

