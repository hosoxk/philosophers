#ifndef PHILO_H
# define PHILO_H

#include "./sources/libft/libft.h"
#include "./sources/libft/sources/ft_printf/ft_printf.h"
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> //mutex and threads
#include <sys/time.h> //gettimeofday
#include <limits.h> //INT_MAX

//*** ANSI escape sequences for bold text colors ***
// Usage: printf(BOLD_RED "This text is bold red!" RESET "\n");

#define RESET		"\033[0m"
#define BOLD_RED	"\033[1;31m"
#define BOLD_GREEN	"\033[1;32m"
#define BOLD_YELLOW	"\033[1;33m"
#define BOLD_BLUE	"\033[1;34m"
#define BOLD_MAGENTA	"\033[1;35m"
#define BOLD_CYAN	"\033[1;36m"
#define BOLD_WHITE	"\033[1;37m"

//*** structures ***

typedef pthread_mutex_t	t_mtx;

/*
* IOU for compiler
*/
typedef struct s_table	t_table;

typedef struct	s_fork
{
	t_mtx	fork;
	int	fork_id;
}	t_fork;

typedef struct s_philo
{
	int		id;
	long		meals_counter;
	bool		full;
	long		last_meal_time; //time passed from last meal
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

typedef struct	s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation;
	bool	end_simulation; //a philo dies or all philos are full
	t_fork	*forks; //array forks
	t_philo	*philos; //array philos
}	t_table;

//*** prototypes ***

//parsing
void	parse_input(t_table *table, char **argv);
//initializing
//utils
void	error_exit(const char *error);

# endif
