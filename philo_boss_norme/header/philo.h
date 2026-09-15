/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:25:02 by wihumeau          #+#    #+#             */
/*   Updated: 2026/09/14 19:22:12 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// === INCLUDES ===
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

// === MACROS ===

# define INT_MAX 2147483647
# define ARGS_ERROR "invalid number of arguments\n"
# define INPUT_ERROR "invalid input value\n"
# define DATA_MUTEX_ERROR "data's mutex could not be initialised\n"
# define PHILO_MUTEX_ERROR "philo's mutex could not be initialised\n"
# define MALLOC_ERROR "malloc failed\n"

// === STRUCTURES ===
typedef struct s_data
{
	pthread_t		monitor;
	pthread_mutex_t	lock_forks[200];
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_end_prog;
	long			nb_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				nb_meal_per_philo;
	long			start_time;
	int				philo_finish_eaten_count;
	int				end_prog;

}	t_data;

typedef struct s_philo
{
	pthread_t		philo;
	t_data			*data;
	int				id;
	int				nb_meal_eaten;
	int				finished_eaten;
	int				dead;
	long			last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	lock_nb_meal_eaten;
	pthread_mutex_t	lock_last_meal_time;
	pthread_mutex_t	death_lock;
}	t_philo;

// === FONCTIONS ===

// == PARSING ==

// parsing/init_data.c
int		init_data(t_data *data, char **av);

// parsing/init_philos.c
t_philo	**init_philos(t_data *data);
int		init_philos_mutex(t_philo **philo);

// == EXEC == 

// exec/philo.c 
void	*philo_routine(void *arg);
int		get_philos_started(t_philo **philo);

// exec/actions.c
int		eating(t_philo *philo);
int		thinking(t_philo *philo);
int		sleeping(t_philo *philo);

// exec/monitor.c
int		begin_threads(t_data *data, t_philo **philo);

// == UTILS ==

//	utils_gen.c
void	custom_sleep(t_data *data, size_t sleep_time);
long	get_time_of_day(void);
int		ft_strlen(const char *str);
long	ft_atol(const char *nptr);
int		ft_atoi(const char *str);

//	utils_value.c
void	update_value(pthread_mutex_t *mutex, int *value);
int		read_value(pthread_mutex_t *mutex, int *value);
void	update_last_meal(t_philo *philo);
long	read_last_meal(t_philo *philo);

//	utils_monitor.c
long	last_meal_time_ago(t_philo *philo);
int		philo_eaten_all_meal(t_philo *philo);
int		philos_finished(t_philo *philo);
int		philo_is_dead(t_philo *philo);
int		print_action(t_philo *philo, char *str);

//	clear_data.c
void	clear_forks_mutex(t_data *data);
void	clear_data(t_data *data);
int		clear_everything(t_philo **philos);

//	clear_philos.c
void	clear_philos(t_philo **philos, int nb);
void	clear_nb_philos(t_philo **philos, int nb);
void	clear_philo_mutex_fail(t_philo **philo, int i, int flag);

//	test.c
void	print_data(t_data data);
void	print_philo(t_philo **philo);

#endif
