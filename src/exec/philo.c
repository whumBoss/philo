#include "../../header/header.h"

//		=== PHILO ===

//Routine realisee par les threads philo, recoive en arg une stuct philo
void	*philo_routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	//re-cast l'arg en t_philo
	//data = recup data dans philo
	philo = (t_philo *)arg;
	data = philo->data;

	// faire sleep les threads pair pour que ils mangent pas en meme temps que leurs voisins
	if (philo->id % 2 == 0)
		custom_sleep(data, data->time_eat);

	// Boucle infini pour faire manger, penser, dormir le philo. Si une des actions est fausse, break la Boucle
	while (1)
	{
		if (!eating(philo) || !thinking(philo) || !sleeping(philo))
			break;
	}
	return (NULL); //=> tjrs pas de return value? en cas d'erreur?
}
