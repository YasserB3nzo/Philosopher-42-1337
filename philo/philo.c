/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:43:35 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/31 21:34:51 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dream(t_philosopher *philo)
{
	print_message("is sleeping", philo, philo->philo_id);
	ft_usleep(philo->data->time_to_sleep);
}

void	print_message(char *str, t_philosopher *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->write_lock);
	time = get_current_time() - philo->data->start_time;
	if (!dead_flag_check(philo))
		printf("\033[1;35m %zu %d %s\n \033[0m", time, id, str);
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	*get_g_data(void)
{
	static t_philo_data	data;

	return ((void *)&data);
}

int	main(int ac, char **av)
{
	t_philo_data	*data;
	t_philosopher	philosophers[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	data = get_g_data();
	if (!checkargument(ac, av))
		return (1);
	init_data(data, av);
	init_philos(philosophers, data, forks);
	if (data->number_of_philo == 1)
	{
		if (!one_casephilo(data, forks))
			return (1);
	}
	else
		init_threads(philosophers, data);
	destroy(data, forks);
	return (0);
}
