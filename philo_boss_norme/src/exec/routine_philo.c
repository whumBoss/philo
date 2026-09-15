/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:25:48 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 15:25:49 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (!eating(philo) || !thinking(philo) || !sleeping(philo))
			break ;
	}
	return (NULL);
}

int	get_philos_started(t_philo **philo)
{
	t_data	*data;
	int		i;

	i = 0;
	data = philo[i]->data;
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i]->philo, NULL, philo_routine,
				philo[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
