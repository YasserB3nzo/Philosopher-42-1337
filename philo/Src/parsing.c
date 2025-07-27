/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:13:58 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/27 16:14:01 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	checkargument(int ac, char **av)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	if (ac == 5 || ac == 6)
	{
		while (i < ac - 1)
		{
			number = ft_atoi(av[i + 1]);
			if (i == 0 && (number < 1 || number > 200))
				return (error_message());
			else if (i == 1 && number < 1)
				return (error_message());
			else if (i == 2 && number < 1)
				return (error_message());
			else if (i == 3 && number < 1)
				return (error_message());
			else if (i == 4 && number < 0)
				return (error_message());
			i++;
		}
	}
	else
		return (error_message());
	return (1);
}
