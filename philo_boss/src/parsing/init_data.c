#include "../../header/header.h"

static int	data_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->lock_forks[i], NULL) != 0) 
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->lock_print, NULL) != 0)
return (0);
	if (pthread_mutex_init(&data->lock_end_prog, NULL) != 0)
		return (0);
	return (1);
}

static int	values_validation(t_data data)
{
	return (data.nb_philo > 0 && data.nb_philo <= 200 && data.time_die > 0 && data.time_eat > 0 && data.time_sleep > 0);
	//pas de limite de temps max?
}

static int	data_validation(t_data data, char **av)
{
	if (!values_validation(data))
	{
		write(2, INPUT_ERROR, ft_strlen(INPUT_ERROR));
		return (0);
	}
	if (av[5])
	{
		if (data.nb_meal_per_philo < 0)
		{
			write(2, INPUT_ERROR, ft_strlen(INPUT_ERROR));
			return (0);
		}
	}
	return (1);
}


// static void	data_initialisation(t_data *data, char **av){
// 	data->nb_philo = ft_atol(av[1]);
// 	data->time_die = ft_atol(av[2]);
// 	data->time_eat = ft_atol(av[3]);
// 	data->time_sleep = ft_atol(av[4]);
// 	if (av[5])
// 		data->nb_meal_per_philo = ft_atoi(av[5]);
// 	else
// 		data->nb_meal_per_philo = -1;
// 	data->start_time = 0;
// 	data->philo_finish_eaten_count = 0;
// 	data->end_prog = 0;
// }

int	init_data(t_data *data, char **av)
{
	// data_initialisation(data, av);
	if (!data_validation(*data, av))
		return (0);
	if (!data_mutex(data))
		return (0);
	print_data(*data); //a commenter
	return (1);
}


