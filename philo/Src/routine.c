/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:50:43 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/26 17:09:50 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int    one_casephilo(philo_data *data)
{
    pthread_mutex_lock(&data->forks[0]);
    printf("%ld 1 has taken a fork\n", timestamp_in_ms() - data->start_time);
    usleep(data->time_to_die * 1000);
    printf("%ld 1 died\n", timestamp_in_ms() - data->start_time);
    pthread_mutex_unlock(&data->forks[0]);
    return (0); 
}
void    *philosopher_routine(void *arg)
{
   while(1)
    {
        philosopher *philo = (philosopher *)arg;
        philo_data *data = philo->data;

        pthread_mutex_lock(philo->left_fork);
        printf("%ld %d has taken a fork\n", timestamp_in_ms() - data->start_time, philo->philo_id);
        
        pthread_mutex_lock(philo->right_fork);
        printf("%ld %d has taken a fork\n", timestamp_in_ms() - data->start_time, philo->philo_id);

        printf("%ld %d is eating\n", timestamp_in_ms() - data->start_time, philo->philo_id);
        usleep(data->time_to_eat * 1000);
        philo->meal_counter++;
        philo->last_meal_time = timestamp_in_ms();

        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);

        printf("%ld %d is sleeping\n", timestamp_in_ms() - data->start_time, philo->philo_id);
        usleep(data->time_to_sleep * 1000);

        printf("%ld %d is thinking\n", timestamp_in_ms() - data->start_time, philo->philo_id);
}
}

//  Data races occur 
// when multiple tasks or threads access a shared resource 
// without sufficient protections, 
// leading to undefined or unpredictable behavior.