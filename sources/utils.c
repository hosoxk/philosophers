#include "../philo.h"

void	error_exit(const char *error)
{
	printf(BOLD_RED"%s\n"RESET, error);
	exit(EXIT_FAILURE);
}
