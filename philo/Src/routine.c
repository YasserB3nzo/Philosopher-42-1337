/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:50:43 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/08/03 00:53:55 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philosopher *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	print_message("is eating", philo, philo->philo_id);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	think(t_philosopher *philo)
{
	unsigned long	think_time;

	print_message("is thinking", philo, philo->philo_id);
	if (philo->data->number_of_philo % 2 == 1)
	{
		think_time = (philo->data->time_to_eat * 2)
			- philo->data->time_to_sleep;
		if (think_time > 0 && think_time < philo->data->time_to_die / 2)
			ft_usleep(think_time);
	}
}

static int	should_stop_simulation(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead_flag || philo->data->eat_flag)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (0);
}

static int	meals_completed(t_philosopher *philo)
{
	int	completed;

	if (philo->data->meals == -1)
		return (0);
	pthread_mutex_lock(&philo->data->meal_lock);
	completed = (philo->meal_counter >= philo->data->meals);
	pthread_mutex_unlock(&philo->data->meal_lock);
	return (completed);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (!should_stop_simulation(philo))
	{
		if (meals_completed(philo))
			break ;
		eat(philo);
		if (should_stop_simulation(philo))
			break ;
		think(philo);
		if (should_stop_simulation(philo))
			break ;
		dream(philo);
	}
	return (NULL);
}
