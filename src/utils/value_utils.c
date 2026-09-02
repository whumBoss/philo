#include "../../header/header.h"


// update_value();


int	read_value(pthread_mutex_t *mutex, int *value)
{
	int	read_value;

	pthread_mutex_lock(mutex);
	read_value = *value;
	pthread_mutex_unlock(mutex);
	return (read_value);
}

// update_last_meal();

