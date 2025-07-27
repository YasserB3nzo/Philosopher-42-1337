/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:30:16 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/27 22:20:46 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_message(char *str, philosopher *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->write_lock);
	time = get_current_time() - philo->data->start_time;
	if (!dead_flag_check(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(&philo->data->write_lock);
}

int	dead_flag_check(philosopher *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (0);
}
int	philosopher_dead(philosopher *philo)
{
	pthread_mutex_lock(&philo->data->meal_lock);
	if (get_current_time() - philo->last_meal_time >= philo->data->time_to_die)
		return (pthread_mutex_unlock(&philo->data->meal_lock), 1);
	pthread_mutex_unlock(&philo->data->meal_lock);
	return (0);
}
int	check_if_dead(philosopher *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].data->number_of_philo)
	{
		if (philosopher_dead(&philos[i]))
		{
			print_message("died", &philos[i], philos[i].philo_id);
			pthread_mutex_lock(&philos[i].data->dead_lock);
			philos[i].one_dead_flag = 1;
			pthread_mutex_unlock(&philos[i].data->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}
int	check_if_all_ate(philosopher *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].data->meals == -1)
		return (0);
	while (i < philos[0].data->number_of_philo)
	{
		pthread_mutex_lock(&philos[0].data->meal_lock);
		if (philos[i].meal_counter >= philos[0].data->meals)
			finished_eating++;
		pthread_mutex_unlock(&philos[0].data->meal_lock);
		i++;
	}
	if (finished_eating == philos[0].data->number_of_philo)
	{
		pthread_mutex_lock(&philos[0].data->dead_lock);
		philos[0].data->dead_flag = 1;
		pthread_mutex_unlock(&philos[0].data->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	philosopher *philos;
	philos = (philosopher *)arg;

	while (1)
	{
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	}
	return (NULL);
}