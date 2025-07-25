/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:50:43 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/25 20:08:32 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *routine(void *arg)
{
    printf("philosopher %d is thinking\n", ((philosopher *)arg)->philo_id);
    return NULL;
}