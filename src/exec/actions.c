 #include "../../header/header.h"

/*		=== ACTIONS ===

static int	print_action(t_philo *philo, char *str)
{

}

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
	if (!taking_forks(philo))
		return (0);

	//print l'action dans le terminal
	print_action(philo, "is eating");

	// unknown for now
	update_last_meal(? , ?);

	// custom sleep le temps du repas, pour rester lock durant tout ce temps
	custom_sleep(data, time_eat);
	
	// update le nb de meal que le philo a manger
	update_value();

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
