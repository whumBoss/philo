#include "../../header/header.h"

//		=== PHILO ===

//Routine realisee par les threads philo, recoive en arg une stuct philo
void	*philo_routine(void *arg)
{
//	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg; //re-cast l'arg en t_philo
//	data = philo->data; //data = recup data dans philo


	// faire sleep les threads pair pour que ils mangent pas en meme temps que leurs voisins
	if (philo->id % 2 == 0)
		usleep(100);

	// Boucle infini pour faire manger, penser, dormir le philo. Si une des actions est fausse, break la boucle
	while (1)
	{
		if (!eating(philo) || !thinking(philo) || !sleeping(philo))
			break;
	}
	return (NULL); //=> tjrs pas de return value? en cas d'erreur?
}

int	get_philos_started(t_philo **philo)
{
	t_data	*data;
	int	i;

	i = 0;
	data = philo[i]->data;
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i]->philo, NULL, philo_routine, philo[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

