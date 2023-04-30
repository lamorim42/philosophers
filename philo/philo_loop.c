/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:24:31 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 01:29:50 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "input.h"
#include "utils.h"
#include <stdio.h>

static void	think(t_philo *philo, unsigned int time)
{
	pthread_mutex_lock(&input_instance()->m_continue);
	if (input_instance()->to_continue)
	{
		print_action(philo, "thinking");
	}
	pthread_mutex_unlock(&input_instance()->m_continue);
	ft_sleep(time);
}

static void	sleep(t_philo *philo)
{
	pthread_mutex_lock(&input_instance()->m_continue);
	if (input_instance()->to_continue)
	{
		print_action(philo, "sleeping");
	}
	pthread_mutex_unlock(&input_instance()->m_continue);
	ft_sleep(input_instance()->t_sleep);
}

void	*philo_loop(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *) ptr;
	pthread_mutex_lock(&input_instance()->print);
	philo->start = get_time(0);
	pthread_mutex_unlock(&input_instance()->print);
	if (philo->id % 2 == 1)
		think(philo, input_instance()->t_eat);
	while (1)
	{
		pthread_mutex_lock(&input_instance()->m_continue);
		if (!input_instance()->to_continue)
			break ;
		pthread_mutex_unlock(&input_instance()->m_continue);
		sleep(philo);
		think(philo, 0);
	}
	pthread_mutex_unlock(&input_instance()->m_continue);
	return (NULL);
}
