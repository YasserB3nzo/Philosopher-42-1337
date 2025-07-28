/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:31:34 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/27 22:20:46 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_data(philo_data *data, char **av)
{
	data->number_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->meals = ft_atoi(av[5]);
	else
		data->meals = -1;
	data->dead_flag = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	data->start_time = get_current_time();
}

void	init_philos(philosopher *philosophers, philo_data *data,
		pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->number_of_philo)
	{
		philosophers[i].philo_id = i + 1;
		philosophers[i].meal_counter = 0;
		philosophers[i].last_meal_time = data->start_time;
		philosophers[i].data = data;
		philosophers[i].eating = 0;
		pthread_mutex_init(&philosophers[i].meal_lock, NULL);
		if (i % 2 == 0) {
			philosophers[i].left_fork = &forks[(i + 1) % data->number_of_philo];
			philosophers[i].right_fork = &forks[i];
		} else {
			philosophers[i].left_fork = &forks[i];
			philosophers[i].right_fork = &forks[(i + 1) % data->number_of_philo];
		}
		i++;
	}
}
void	init_threads(philosopher *philosophers, philo_data *data)
{
	pthread_t	serbay;
	int			i;

	i = 0;
	if (pthread_create(&serbay, NULL, &monitor, philosophers) != 0)
	{
		write(2, "Error creating thread\n", 22);
		return ;
	}
	while (i < data->number_of_philo)
	{
		pthread_create(&philosophers[i].thread, NULL, philosopher_routine,
				&philosophers[i]);
		i++;
	}
	i = 0;
	pthread_join(serbay, NULL);
	while (i < data->number_of_philo)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
}
