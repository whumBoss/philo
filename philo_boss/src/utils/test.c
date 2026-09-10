#include "header.h"

void	print_data(t_data data)
{
	printf("=== data ===\n");
	printf("adrs data = %p\n", &data);
	printf("data.nb_philo = %ld\n", data.nb_philo);
	printf("data.time_die = %ld\n", data.time_die);
	printf("data.time_eat = %ld\n", data.time_eat);
	printf("data.time_sleep = %ld\n", data.time_sleep);
	printf("data.nb_meal_per_philo = %d\n", data.nb_meal_per_philo);
	printf("data.start_time = %ld\n", data.start_time);
	printf("data.philo_finish_eaten_count = %d\n", data.philo_finish_eaten_count);
	printf("data.end_prog = %d\n", data.end_prog);
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
		printf("philo[%d]->id = %d\n", philo[i]->id, philo[i]->id);
		printf("philo[%d]->data = %p\n", philo[i]->id, philo[i]->data);
		printf("philo[%d]->nb_meal_eaten = %d\n", philo[i]->id, philo[i]->nb_meal_eaten);
		printf("philo[%d]->finished_eaten = %d\n", philo[i]->id, philo[i]->finished_eaten);
		printf("philo[%d]->dead = %d\n", philo[i]->id, philo[i]->dead);
		printf("philo[%d]->last_meal_time = %ld\n\n", philo[i]->id, philo[i]->last_meal_time);
		i++;
	}
	printf("--------------------\n\n");

}
