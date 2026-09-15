/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:26:07 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 16:47:49 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_forks_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->lock_forks[i]);
		i++;
	}
	return ;
}

void	clear_data(t_data *data)
{
	clear_forks_mutex(data);
	pthread_mutex_destroy(&data->lock_print);
	pthread_mutex_destroy(&data->lock_end_prog);
	return ;
}

int	clear_everything(t_philo **philos)
{
	t_data	*data;

	data = philos[0]->data;
	clear_philos(philos, data->nb_philo);
	clear_data(data);
	return (1);
}
