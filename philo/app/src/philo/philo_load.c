/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:01:21 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 16:27:22 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "philo.h"
#include "input.h"
#include <stdlib.h>

static t_philo	*philo_creat(void)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	new->id = 0;
	new->n_eat = 0;
	new->last_eat = 0;
	new->checked = 0;
	new->prev = new;
	new->next = new;
	pthread_mutex_init(&new->fork, NULL);
	return (new);
}

static void	philo_add_back(t_philo *new)
{
	t_philo	*prev;

	if (!(*philo_instance()))
	{
		(*philo_instance()) = new;
		(*philo_instance())->id = 0;
	}
	else
	{
		prev = (*philo_instance())->prev;
		(*philo_instance())->prev = new;
		new->next = prev->next;
		prev->next = new;
		new->prev = prev;
		new->id = prev->id + 1;
	}
	pthread_create(&new->thread, NULL, &philo_life_cycle, new);
}

void	philo_load(void)
{
	unsigned int	i;

	i = 0;
	while (i < input_instance()->n_philos)
	{
		philo_add_back(philo_creat());
		i++;
	}
}
