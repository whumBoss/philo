#include "../header/header.h"

static int	is_only_digit(char *str) {
	int i;

	i =0;
	while (str[i]) {
		if (str[i] < '0' || str[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

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

//		Init data dans le main pour eviter de malloc
	if (!is_only_digit(av[1]) || !is_only_digit(av[2]) || !is_only_digit(av[3]) || !is_only_digit(av[4]))
	{
		write(2, INPUT_ERROR, ft_strlen(INPUT_ERROR));
		return (1);
	}
	data.nb_philo = ft_atol(av[1]);
	data.time_die = ft_atol(av[2]);
	data.time_eat = ft_atol(av[3]);
	data.time_sleep = ft_atol(av[4]);

	if (av[5])
	{
		if (is_only_digit(av[5]))
			data.nb_meal_per_philo = ft_atoi(av[5]);
		else
		{
			write(2, INPUT_ERROR, ft_strlen(INPUT_ERROR));
			return (1);
		}
	}
	else
		data.nb_meal_per_philo = -1;
	data.start_time = 0;
	data.philo_finish_eaten_count = 0;
	data.end_prog = 0;

//		=== PARSING ===
	if(!init_data(&data, av)) // les infos ont ete verifier et les mutex initialiser
		return (1);

	philo = init_philo(&data); // les philos on ete malloc et assigner
	if (!init_philos_mutex(philo)) // les mutex on ete initialiser et les threads lancer sur leurs routines
		return (1);
	print_philo(philo); // => TEST
	
//		=== EXECUTION ===
	if (!begin_threads(&data, philo)) // Lance le thread monitor est lance, et les philos aussi
		return (1);

	pthread_join(data.monitor, NULL); // join monitor
	
	print_philo(philo);

	clear_everything(philo); // on clear tout. Soit wait les threads philos, destroy les mutex et free les philos


	// QUESTION : Les return value des threads on les recupere jamais? On est pas cense renvoyer un exit code different selon si les philos ont bien manger ou si un philo est dead? when, where, why?????
	
	return (0);
}
