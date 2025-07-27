/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:50:43 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/27 16:51:58 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	one_casephilo(philo_data *data)
{
	pthread_mutex_lock(&data->forks[0]);
	printf("%ld 1 has taken a fork\n", timestamp_in_ms() - data->start_time);
	usleep(data->time_to_die * 1000);
	printf("%ld 1 died\n", timestamp_in_ms() - data->start_time);
	pthread_mutex_unlock(&data->forks[0]);
	return (0);
}
void	*philosopher_routine(void *arg)
{
	philosopher	*philo;
	philo_data	*data;

    philo = (philosopher *)arg;
    data = philo->data;

	while (1)
	{
        
	}
}

//  Data races occur
// when multiple tasks or threads access a shared resource
// without sufficient protections,
// leading to undefined or unpredictable behavior.