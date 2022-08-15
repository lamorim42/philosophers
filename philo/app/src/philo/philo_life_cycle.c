/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:16:01 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 16:27:10 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "philo.h"
#include "input.h"
#include "print.h"

static char	get_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (pthread_mutex_lock(fork) != 0)
		return (0);
	print_philo_activity(philo, "has taken a fork");
	return (1);
}

static int	eat(t_philo *philo)
{
	int	eat;

	eat = 0;
	if (get_fork(philo, &philo->fork))
	{
		if (!input_instance()->to_continue || input_instance()->n_philos == 1)
		{
			pthread_mutex_unlock(&philo->fork);
			eat = 1;
		}
		else if (get_fork(philo, &philo->next->fork))
		{
			print_philo_activity(philo, "is eating");
			philo->last_eat = ph_get_time(0);
			philo->n_eat++;
			ph_sleep(input_instance()->t_eat);
			pthread_mutex_unlock(&philo->next->fork);
		}
		if (!eat)
			pthread_mutex_unlock(&philo->fork);
	}
	return (eat);
}

static void	sleep(t_philo *philo)
{
	if (input_instance()->to_continue)
	{
		print_philo_activity(philo, "is sleeping");
		ph_sleep(input_instance()->t_sleep);
	}
}

static void	think(t_philo *philo, unsigned int s_time)
{
	if (input_instance()->to_continue)
	{
		print_philo_activity(philo, "is thinking");
		ph_sleep(s_time);
	}
}

void	*philo_life_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (input_instance()->start == 0)
		;
	if (philo->id % 2 == 1)
		think(philo, input_instance()->t_eat);
	while (input_instance()->to_continue)
	{
		if (eat(philo) && input_instance()->to_continue)
			break ;
		sleep(philo);
		think(philo, 0);
	}
	pthread_detach(philo->thread);
	return (NULL);
}
