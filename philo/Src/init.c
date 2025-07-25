/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:31:34 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/25 20:05:05 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void init_data(philo_data *data, char **av)
{
    data->number_of_philo = ft_atoi(av[1]); // verify atoi 
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if(av[5])
        data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        data->number_of_times_each_philosopher_must_eat = -1;
    data->dead_flag = 0;
    data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
    pthread_mutex_init(&data->write_lock, NULL);
    pthread_mutex_init(&data->dead_lock, NULL);
    pthread_mutex_init(&data->meal_lock, NULL);
    data->start_time = timestamp_in_ms();
}

void init_philos(philosopher *philosophers, philo_data *data,pthread_mutex_t *forks)
{
    int i;

    i = 0;
    while (i < data->number_of_philo)
    {
        philosophers[i].philo_id = i + 1; // ID starts from 1
        philosophers[i].meal_counter = 0;
        philosophers[i].last_meal_time = data->start_time;
        philosophers[i].data = data;
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % data->number_of_philo];
        pthread_create(&philosophers[i].thread, NULL, routine, &philosophers[i]);
        // pthread_join(philosophers[i].thread, NULL);
        i++;
    }
    i = 0;
    while (i < data->number_of_philo)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
}
// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//                    void *(*start_routine)(void *), void *arg);