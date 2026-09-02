/*		=== MONITOR ===
le thread monitor est lancer sur sa routine et on le wait

static check_data
{
	// met a jour les infos concernant la mort du philo ou la fin de tout les repas du philo, soit si ce philo est termine ou pas encore
	si le last_meal_time_ago() >= time_to_die
		update_value(philo->dead_lock, philo->dead)
	si le philo_eaten_all_meal()
		data->philo_finish_eaten_count;
}

static routine_monitor(void arg)
{
	recast l'arg
	custom sleep monitor but whyyyyyyyyyyyyy?
	while (1)
	{
		i = 0 on remet i a zero pour re-check tout les philo a chaque boucle
		while (i < nb_philo)
		{
			check_philo => met a jour les valeur concernant les repas ou la mort du philo
			// si le philo est mort ou ils ont tous fini de manger, on met le flag stop dans data et on sors de la petite boucle
			if (le philo est mort(philo[i]) || les philos on tous manger(philo[i], data->philo_finish_eaten_count))
			{
				update_value(data->stop_lock?, data->stop?)
				break; => la petite boucle
			}
		}
		sleep => whyyyyyyyyyyyyy?????
		// si le flag stop est vrai, on stop la grande boucle, soit on termine le thread monitor, donc fin de programme
		if (data->stop)
			break; => la grande boucle
	}
	return (NULL) => why? pas d'exit code necessaire?
}

begin_monitor(data, **philo)
{
	pthread_create(monitor, routine_monitor, **philo);
	pthread_join(monitor);
}

*/
