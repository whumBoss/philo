#include "../../header/header.h"
#include <stdio.h>

//		=== MONITOR ===
// le thread monitor est lancer sur sa routine et on le wait

// met a jour les infos concernant la mort du philo ou la fin de tout les repas du philo, soit si ce philo est termine ou pas encore
static void	check_philo(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (last_meal_time_ago(philo) >= data->time_die && data->nb_philo > 1)
		update_value(&philo->death_lock, &philo->dead);
	// printf("dead = %d\n", philo->dead);// TEST
	if (philo_eaten_all_meal(philo))
		data->philo_finish_eaten_count++;
}

static void *routine_monitor(void *arg)
{
	t_philo	**philo;
	t_data	*data;
	int		i;

	philo = (t_philo **)arg;
	data = philo[0]->data;

	//printf("le monitor est lancer\n");
	//custom_sleep(data, data->time_eat - 100); // => POURQUOI
	while (1)
	{
		i = 0; // on remet i a zero pour re-check tout les philo a chaque boucle
		while (i < data->nb_philo)
		{
			check_philo(philo[i]); //=> met a jour les valeur concernant les repas ou la mort du philo
			// si le philo est mort ou ils ont tous fini de manger, on met le flag stop dans data et on sors de la petite boucle
 			if (philo_is_dead(philo[i]) || philos_finished(philo[i]))
			{
				// printf("passe dans la condition\n");
				update_value(&data->lock_end_prog, &data->end_prog);
				break; // => la petite boucle
			}
			i++;
		}
		usleep(110); // => POURQUOI?
		// si le flag stop est vrai, on stop la grande boucle, soit on termine le thread monitor, donc fin de programme
		if (data->end_prog)
			break; // => la grande boucle
	}
	return (NULL); // => why? pas d'exit code necessaire?
}


int	begin_threads(t_data *data, t_philo **philo)
{
	data->start_time = get_time_of_day();
	if (pthread_create(&data->monitor, NULL, routine_monitor, philo) != 0)
		return (0);
	if (!get_philos_started(philo))
		return (0);
	return (1);
}

