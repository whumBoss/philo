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
//
# define ARGS_ERROR "invalid number of arguments\n"
# define INPUT_ERROR "invalid input value\n"

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

} t_data;

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
} t_philo;

// === FONCTIONS ===


// == PARSING ==

// parsing/init_data.c
int		init_data(t_data *data, char **av);

// parsing/init_philos.c
int		begin_philo(t_philo **philo);
t_philo	**init_philo(t_data *data);

// == EXEC == 

// exec/philo.c 
void	*philo_routine(void *arg);

// exec/actions.c
int	print_action(t_philo *philo, char *str);
int		eating(t_philo *philo);
// sleeping();
// thinking();


// exec/monitor.c
int	begin_monitor(t_data *data, t_philo **philo);
// static routine_monitor();

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
// last_meal_time_ago();
// philo_eaten_all_meal();
// philos_finished();
// philo_is_dead();


//	clear.c
int	clear_everything(t_philo **philos);

//	test.c
void	print_data(t_data data);
void	print_philo(t_philo **philo);

#endif
