#include "../header/header.h"
#include <stdio.h>

void	print_data(t_data data)
{
	printf("=== data ===\n");
	printf("adrs data = %p\n", &data);
	printf("data.nb_philo = %ld\n", data.nb_philo);
	printf("data.time_die = %ld\n", data.time_die);
	printf("data.time_eat = %ld\n", data.time_eat);
	printf("data.time_sleep = %ld\n", data.time_sleep);
	printf("data.nb_meal_per_philo = %ld\n", data.nb_meal_per_philo);
	printf("--------------------\n");
}

void	print_philo(t_philo **philo)
{
	int	i = 0;
	t_data *data = philo[i]->data;

	printf("\n=== tab philo ===\n");

	while (i < data->nb_philo)
	{
		printf("\n ___ philo ___\n");
		printf("id = %d\n", philo[i]->id);
		printf("data = %p\n", philo[i]->data);
//		printf("left_fork = %p\n", philo[i]->left_fork);
//		printf("right_fork = %p\n", philo[i]->right_fork);
		i++;
	}
}
