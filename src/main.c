#include "../header/header.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	**philo;

//		Verif nb arg
	if (ac < 5 || ac > 6)
	{
		write(2, ARGS_ERROR, ft_strlen(ARGS_ERROR));
		return (1);
	}

//		=== PARSING ===
	if(!init_data(&data, av)) // les infos ont ete verifier et parser et les mutex initialiser
		return (1);

	philo = init_philo(&data); // les philos on ete malloc et assigner
	if (!begin_philo(philo)) // les mutex on ete initialiser et les threads lancer sur leurs routines
		return (1);
	
//		=== EXECUTION ===
	// begin_monitor(); // le thread monitor est lancer sur sa routine et on le wait 


	// on clear tout. Soit wait les threads philos, destroy les mutex et free les philos


	// QUESTION : Les return value des threads on les recupere jamais? On est pas cense renvoyer un exit code different selon si les philos ont bien manger ou si un philo est dead? when, where, why?????
	//
	return (0);
}
