/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:59:38 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 20:59:40 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_to_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->mutex_dead);
	if (philo->input->to_stop)
	{
		pthread_mutex_unlock(&philo->input->mutex_dead);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->input->mutex_dead);
	return (FALSE);
}

void	write_to_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->mutex_dead);
	philo->input->to_stop = TRUE;
	pthread_mutex_unlock(&philo->input->mutex_dead);
}
