/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:13:58 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/28 16:36:58 by ybenzidi         ###   ########.fr       */
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
