/* 
on clear tout soit wait les threads philos, destroy les mutex et free les philos

static clear_philos
{
	while (i < nb_philo)
	{
		join threads philo[i]
		i++;
	}
	i = 0
	while (i < nb_philo)
	{
		destroy philo[i] mutex sauf forks
		free(philo[i])
		i++;
	}
	free(philo);
}

static clear_data
{
	while (i < nb_philo)
	{
		destroy mutex fork[i]
		i++;
	}
	destroy data's mutex
}

clear_everything
{
	clear_philos if??
	clear_data if??
	return (?) ou exit (?)
}
*/
