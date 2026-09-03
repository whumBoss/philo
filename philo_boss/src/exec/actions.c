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


static int	taking_forks(t_philo *philo)
{
	// recup data
	t_data	*data;

	data = philo->data;
	
	// prendre la fourchette de droite et ecrire l'action
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");

	// 1 cas speciale
	// il y a un philo et il a pas de fourchette a gauche
	if (!philo->left_fork && data->nb_philo == 1 )
	{
		custom_sleep(data, data->time_die);
		// QUESTION : quand est ce qu'on dis qu'il est mort??
		pthread_mutex_unlock(philo->right_fork);
		return(0);
		// QUESTION : donc il a pas reussis a manger, il a attendus le temps de mourrir, quand est ce qu'il meurs pour de vrai??
	}
	
	//prendre la fourchette de gauche et ecrire
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	return (1);
	// les fourchettes on bien ete prises
	
	// QUESTION : pas de verif sur les lock des mutex?? on est tjrs sur que c'est ok??
	// QUESTION : ou verif sur l'existance des mutex? deja fait dans le parsing?

}

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
