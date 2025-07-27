/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:43:35 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/27 22:20:46 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	philo_data		*data;
	philosopher		philosophers[PHILO_MAX];
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
	destroy(data, philosophers, forks);
	return (0);
}
