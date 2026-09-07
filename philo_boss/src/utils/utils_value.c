#include "../../header/header.h"


void	update_value(pthread_mutex_t *mutex, int *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
}


int	read_value(pthread_mutex_t *mutex, int *value)
{
	int	read_value;

	pthread_mutex_lock(mutex);
	read_value = *value;
	pthread_mutex_unlock(mutex);
	return (read_value);
}

void	update_last_meal(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&philo->lock_last_meal_time_ago);
	philo->last_meal_time_ago = get_time_of_day() - data->start_time;
	pthread_mutex_unlock(&philo->lock_last_meal_time_ago);
}

// read_last_meal()

