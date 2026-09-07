#include "../../header/header.h"

//		=== CLEAR === 
// on clear tout soit wait les threads philos, destroy les mutex et free les philos

static void	clear_philos(t_philo **philos)
{
	int		i;
	t_data	*data;

	i = 0;
	data = philos[i]->data;
	while (i < data->nb_philo)
	{
		pthread_join(philos[i]->philo, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&philos[i]->lock_nb_meal_eaten);
		pthread_mutex_destroy(&philos[i]->death_lock);
		free(philos[i]);
		i++;
	}
	free(philos);
}

static void	clear_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->lock_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->lock_print);
	pthread_mutex_destroy(&data->lock_end_prog);
}

int	clear_everything(t_philo **philos)
{
	clear_philos(philos); // if??
	clear_data(philos[0]->data); // if??
	return (1); //ou exit (?)
}

