/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:13:45 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/27 16:13:48 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	timestamp_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
int	error_message(void)
{
	write(2, "Error: Invalid arguments\n", 24);
	return (0);
}
// void	destroy(philo_data *data, philosopher *philosophers,
// 		pthread_mutex_t *forks)
// {
// 	int	i;

// 	// Destroy fork mutexes
// 	i = 0;
// 	while (i < data->number_of_philo)
// 		pthread_mutex_destroy(&data->forks[i]);
// 	// Destroy global mutexes
// 	pthread_mutex_destroy(&data->write_lock);
// 	pthread_mutex_destroy(&data->dead_lock);
// 	pthread_mutex_destroy(&data->meal_lock);
// 	// Free forks array
// 	free(data->forks);
// }

void	*get_g_data(void)
{
	static philo_data	data;

	return ((void *)&data);
}
long	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;
	int		j;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	num = 0;
	j = i;
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
		j++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num = num + (str[i] - '0');
		++i;
		if (num > INT_MAX)
			break ;
	}
	return (num * sign);
}
