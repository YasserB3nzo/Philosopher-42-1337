#include "../philo.h"

void checkargument(int ac, char **av)
{
    int number;
    int i;

    i = 0;
    number = 0;

    // Accept both 5 and 6 arguments (including program name)
    if(ac == 5 || ac == 6)
    {
        while(i < ac - 1)
        {
            number = ft_atoi(av[i+1]);
            
            // Validate each argument based on its position
            if (i == 0 && (number < 1 || number > 200)) // number_of_philosophers (1-200)
            {
                error_message();
            }
            else if (i == 1 && number < 1) // time_to_die (must be positive)
            {
                error_message();
            }
            else if (i == 2 && number < 1) // time_to_eat (must be positive)
            {
                error_message();
            }
            else if (i == 3 && number < 1) // time_to_sleep (must be positive)
            {
                error_message();
            }
            else if (i == 4 && number < 0) // number_of_times_to_eat (optional, can be 0)
            {
                error_message();
            }
            i++;
        }
    }
    else 
        error_message();
}
