#include "../philo.h"

bool	check_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (ft_printf("Correct usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> (<number_of_times_each_philosopher_should_eat>)\n"), false);
	i = 1; //skips program name
	while (argv[i] != NULL)
	{
		if (!ft_isint(argv[i]) || ft_atoi(argv[i]) < 0)
			return (ft_printf("Provide only integer values bigger than zero(ERROR: %s)\n", argv[i]), false);
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
		return (ft_printf("Test with no more than 200 philosophers\n"));
	return (true);
}
