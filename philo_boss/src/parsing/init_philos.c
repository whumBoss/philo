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
			return (0);
		if (pthread_mutex_init(&philo[i]->lock_nb_meal_eaten, NULL))
			return (0);
		if (pthread_mutex_init(&philo[i]->lock_last_meal_time, NULL))
			return (0);

		i++;
	}
	return (1);
}

//int	begin_philo(t_philo **philo)
//{
//	if (!init_philos_mutex(philo))
//		return (0);
//	print_philo(philo);
//	return (1);
//}

t_philo	**init_philo(t_data *data)
{
	t_philo	**philo;
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo *)* data->nb_philo);
	if (!philo)
		return (NULL);
	while (i < data->nb_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (!philo[i])
			return (NULL);
		// printf("malloc philo %ld,      %ld\n", sizeof(t_data), sizeof(t_data *) );
		// philo[i]->data = malloc(sizeof(t_data *));
		// if (!philo[i]->data)
		// 	return NULL;
		philo[i]->data = data;
		philo[i]->id = i + 1;
		philo[i]->nb_meal_eaten = 0;
		philo[i]->finished_eaten = 0;
		philo[i]->dead = 0;
		philo[i]->last_meal_time = 0;
		philo[i]->right_fork = &data->lock_forks[i];
		if (data->nb_philo != 1)
			philo[i]->left_fork = &data->lock_forks[(i + 1) % data->nb_philo];
		if (data->nb_philo == 1)
			philo[i]->left_fork = NULL;
		i++;
	}
	return (philo);
}

