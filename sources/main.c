#include "../philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		//1) errors checking, filling table table
		parse_input(&table, argv);
		//2) creating the actual thing
	//	data_init(&table);
		//3) simulation
	//	dinner_start(&table);
		//4) no leaks -> philos full || 1 philo died
	//	clean(&table);
	}
	else
		error_exit(BOLD_GREEN"Correct usage: ./philo <number_of_philosophers> <time_to_die>"
			"<time_to_eat> <time_to_sleep> (<number_of_times_each_philosopher_should_eat>)\n"RESET);
	init_data(&table);
	return (0);
}
