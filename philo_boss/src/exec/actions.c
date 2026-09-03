 #include "../../header/header.h"

//		=== ACTIONS ===

static int	print_action(t_philo *philo, char *str)
{
	//assigner data dans data
	t_data	*data;
	long	time;

	data = philo->data;

	//verif si le prog dois finir
	if (read_value(&data->lock_end_prog, &data->end_prog))
		return (0);

	//copier le time
	time = get_time_of_day();

	//ecrire
	pthread_mutex_lock(&data->lock_print);
	printf("%ld : philo %d %s", time, philo->id, str);
	pthread_mutex_unlock(&data->lock_print);

	return (1);
}

/*
static int	taking_forks(t_philo *philo)
{

}
*/

int	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;

	// verif si il faut arreter le prog
	if (read_value(&data->lock_end_prog, &data->end_prog))
		return (0);

	// prendre le fourchettes avec une verif
	//if (!taking_forks(philo))
	//	return (0);
	
	pthread_mutex_lock(philo->left_fork); //a supr
	pthread_mutex_lock(philo->right_fork); // a supr

	//print l'action dans le terminal
	print_action(philo, "is eating");

	// unknown for now
	//update_last_meal(? , ?);

	// update le nb de meal que le philo a manger
	//update_value();

	// custom sleep le temps du repas, pour rester lock durant tout ce temps
	custom_sleep(data, data->time_eat);

	// unlock les fourchettes
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);

	return (1);
}

/*
int	thinking()
{

}

int	sleeping()
{

}
*/
