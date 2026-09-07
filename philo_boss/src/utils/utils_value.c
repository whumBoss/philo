#include "../../header/header.h"

// incremente la valeur
void	update_value(pthread_mutex_t *mutex, int *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
}

// lis la valeur pour l'utiliser
int	read_value(pthread_mutex_t *mutex, int *value)
{
	int	read_value;

	pthread_mutex_lock(mutex);
	read_value = *value;
	pthread_mutex_unlock(mutex);
	return (read_value);
}

// calcule le time du meal
void	update_last_meal(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&philo->lock_last_meal_time);
	philo->last_meal_time = get_time_of_day() - data->start_time;
	pthread_mutex_unlock(&philo->lock_last_meal_time);
}

// lis le time du meal pour l'utiliser
long	read_last_meal(t_philo *philo)
{
	long	last_meal_time;

	pthread_mutex_lock(&philo->lock_last_meal_time);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->lock_last_meal_time);
	return (last_meal_time);
}
