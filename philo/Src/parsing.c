/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:13:58 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/08/03 00:57:39 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	checkargument(int ac, char **av)
{
	int	number;
	int	i;

	if (ac != 5 && ac != 6)
		return (error_message());
	i = 1;
	while (i < ac)
	{
		number = ft_atoi(av[i]);
		if (number <= 0)
			return (error_message());
		if (i == 1 && number > 200)
			return (error_message());
		i++;
	}
	return (1);
}

int	one_casephilo(t_philo_data *data, pthread_mutex_t *forks)
{
	pthread_mutex_lock(&forks[0]);
	printf("%ld 1 has taken a fork\n", get_current_time() - data->start_time);
	usleep(data->time_to_die * 1000);
	printf("%ld 1 died\n", get_current_time() - data->start_time);
	pthread_mutex_unlock(&forks[0]);
	return (0);
}

void	take_forks(t_philosopher *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		print_message("has taken a fork", philo, philo->philo_id);
		pthread_mutex_lock(philo->right_fork);
		print_message("has taken a fork", philo, philo->philo_id);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_message("has taken a fork", philo, philo->philo_id);
		pthread_mutex_lock(philo->left_fork);
		print_message("has taken a fork", philo, philo->philo_id);
	}
}

void	set_death_flag(t_philosopher *philos, int dead_philo_id)
{
	print_message("died", &philos[dead_philo_id],
		philos[dead_philo_id].philo_id);
	pthread_mutex_lock(&philos[dead_philo_id].data->dead_lock);
	philos[dead_philo_id].data->dead_flag = 1;
	pthread_mutex_unlock(&philos[dead_philo_id].data->dead_lock);
}
