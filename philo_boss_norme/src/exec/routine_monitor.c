/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:25:40 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 15:25:41 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_philo(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (last_meal_time_ago(philo) >= data->time_die && data->nb_philo > 1)
		update_value(&philo->death_lock, &philo->dead);
	if (philo_eaten_all_meal(philo))
		data->philo_finish_eaten_count++;
}

static void	*routine_monitor(void *arg)
{
	t_philo	**philo;
	t_data	*data;
	int		i;

	philo = (t_philo **)arg;
	data = philo[0]->data;
	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			check_philo(philo[i]);
			if (philo_is_dead(philo[i]) || philos_finished(philo[i]))
			{
				update_value(&data->lock_end_prog, &data->end_prog);
				break ;
			}
			i++;
		}
		usleep(110);
		if (data->end_prog)
			break ;
	}
	return (NULL);
}

int	begin_threads(t_data *data, t_philo **philo)
{
	data->start_time = get_time_of_day();
	if (pthread_create(&data->monitor, NULL, routine_monitor, philo) != 0)
		return (0);
	if (!get_philos_started(philo))
		return (0);
	return (1);
}
