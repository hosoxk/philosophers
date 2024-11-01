#ifndef PHILO_H
# define PHILO_H

# include "./sources/libft/libft.h"
# include "./sources/libft/sources/ft_printf/ft_printf.h"
# include <stdbool.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t	thread;
	int		id;
	bool		eating;
	int		meals_eaten;
	int		last_meal;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		start_time;
	int		num_of_philos;
	int		num_times_to_eat;
	int		*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_program
{
	int		dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo		*philos;
}	t_program;

//parsing
bool	check_input(int argc, char **argv);
//initializing
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int num_of_philos);
void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char **agv);
void	init_input(t_philo *philo, char **argv);
#endif
