#include "../philo.h"

void error_message()
{
    write(2, "Error: Invalid arguments\n", 24);
    exit(EXIT_FAILURE);
}

// void	error_message(char *text, int signal)
// {
// 	if (text)
// 		write(2, text, ft_strlen(text) + 1);
// 	exit(signal);
// }