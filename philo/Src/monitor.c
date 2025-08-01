/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:34:32 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/08/01 23:50:58 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dead_flag_check(t_philosopher *philo)
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

int	philosopher_dead(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->meal_lock);
	if (get_current_time() - philo->last_meal_time > philo->data->time_to_die
		&& philo->data->meal_c == 0)
		return (pthread_mutex_unlock(&philo->data->meal_lock), 1);
	pthread_mutex_unlock(&philo->data->meal_lock);
	return (0);
}

int	check_if_dead(t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].data->number_of_philo)
	{
		if (philosopher_dead(&philos[i]))
		{
			print_message("died", &philos[i], philos[i].philo_id);
			pthread_mutex_lock(&philos[i].data->dead_lock);
			philos[i].data->dead_flag = 1;
			pthread_mutex_unlock(&philos[i].data->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philosopher *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].data->meals == (-1))
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
		philos[0].data->eat_flag = 1;
		pthread_mutex_unlock(&philos[0].data->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philosopher	*philos;

	philos = (t_philosopher *)arg;
	while (1)
	{
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	}
	return (NULL);
}
