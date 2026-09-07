#include "../../header/header.h"
// 		=== UTILS_MONITOR ===


// verifie si le flag dead est vrai et print le message si vrai
int	philo_is_dead(t_philo *philo)
{
	if (read_value(&philo->death_lock, &philo->dead))
	{
		print_action(philo, "died");
		return (1);
	}
	return (0);
}

int	philos_finished(t_philo *philo)
{
	t_data	*data;
	int		must_eat;

	data = philo->data;
	return (data->philo_finish_eaten_count == data->nb_philo); // verif si nb_meal_per_philo est a -1, whyyyyyyyyyyyyy?????
}

// compare le nb de meal eaten au nb de meal qu'il dois manger et mettre le flag finish a jour
int	philo_eaten_all_meal(t_philo *philo)
{
	t_data *data;

	data = philo->data;
	if (read_value(&philo->lock_nb_meal_eaten, &philo->nb_meal_eaten) == data->nb_meal_per_philo && !philo->finished_eaten)
	{
		philo->finished_eaten = 1;
		return (1);
	}
	return (0);
}

// calcule le dernier repas etait il y a combien de temps
long	last_meal_time_ago(t_philo *philo)
{
	long	time;
	t_data	*data;

	data = philo->data;
	time = get_time_of_day() - data->start_time;
	return (time - read_last_meal(philo));
}

