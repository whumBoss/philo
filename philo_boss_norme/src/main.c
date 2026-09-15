/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:25:24 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 16:45:04 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	first_verif(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		write(2, ARGS_ERROR, ft_strlen(ARGS_ERROR));
		return (0);
	}
	if (!is_only_digit(av[1]) || !is_only_digit(av[2])
		|| !is_only_digit(av[3]) || !is_only_digit(av[4]))
	{
		write(2, INPUT_ERROR, ft_strlen(INPUT_ERROR));
		return (0);
	}
	return (1);
}

static int	start(t_data *data, t_philo **philo)
{
	if (!init_philos_mutex(philo))
		return (0);
	if (!begin_threads(data, philo))
	{
		clear_everything(philo);
		return (0);
	}
	pthread_join(data->monitor, NULL);
	clear_everything(philo);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	**philo;

	if (!first_verif(ac, av))
		return (1);
	data = (t_data){.nb_philo = ft_atol(av[1]), .time_die = ft_atol(av[2]),
		.time_eat = ft_atol(av[3]), .time_sleep = ft_atol(av[4]),
		.start_time = 0, .philo_finish_eaten_count = 0, .end_prog = 0};
	if (av[5] && is_only_digit(av[5]))
		data.nb_meal_per_philo = ft_atoi(av[5]);
	else if (av[5])
	{
		write(2, INPUT_ERROR, ft_strlen(INPUT_ERROR));
		return (1);
	}
	else
		data.nb_meal_per_philo = -1;
	if (!init_data(&data, av))
		return (1);
	philo = init_philos(&data);
	if (!start(&data, philo))
		return (1);
	return (0);
}
