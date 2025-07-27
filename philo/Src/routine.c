/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:50:43 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/27 22:20:46 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	one_casephilo(philo_data *data, pthread_mutex_t *forks)
{
	pthread_mutex_lock(&forks[0]);
	printf("%ld 1 has taken a fork\n", get_current_time() - data->start_time);
	usleep(data->time_to_die * 1000);
	printf("%ld 1 died\n", get_current_time() - data->start_time);
	pthread_mutex_unlock(&forks[0]);
	return (0);
}
int	check_all_if_dead(philosopher *philo)
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
void	dream(philosopher *philo)
{
	print_message("is sleeping", philo, philo->philo_id);
	ft_usleep(philo->data->time_to_sleep);
}
void	think(philosopher *philo)
{
	print_message("is thinking", philo, philo->philo_id);
}
void	eat(philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo, philo->philo_id);
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo, philo->philo_id);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	print_message("is eating", philo, philo->philo_id);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
void	*philosopher_routine(void *arg)
{
	philosopher	*philo;
	philo_data	*data;

	philo = (philosopher *)arg;
	data = philo->data;
	if (philo->philo_id % 2 == 0)
		usleep(100);
	while (!dead_flag_check(philo) && check_all_if_dead(philo) == 0)
	{
		eat(philo);
		if (dead_flag_check(philo) || check_all_if_dead(philo))
			return (NULL);
		dream(philo);
		if (dead_flag_check(philo) || check_all_if_dead(philo))
			return (NULL);
		think(philo);
	}
	return (NULL);
}
