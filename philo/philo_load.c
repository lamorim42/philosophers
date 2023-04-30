/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:05:42 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 01:28:05 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "input.h"
#include "utils.h"
#include <stdlib.h>

static t_philo	*philo_create(void)
{
	t_philo	*new_philo;

	new_philo = (t_philo *) malloc(sizeof(t_philo));
	pthread_mutex_init(&new_philo->fork, NULL);
	new_philo->id = 0;
	new_philo->is_check = 0;
	new_philo->last_eat = 0;
	new_philo->n_eat = 0;
	// new_philo->start = get_time(0);
	new_philo->next = new_philo;
	new_philo->prev = new_philo;
	return (new_philo);
}

static void	philo_add(t_philo *new_philo)
{
	t_philo	*prev_philo;

	if (*philo_instance() == NULL)
	{
		*philo_instance() = new_philo;
	}
	else
	{
		prev_philo = (*philo_instance())->prev;
		(*philo_instance())->prev = new_philo;
		new_philo->next = prev_philo->next;
		prev_philo->next = new_philo;
		new_philo->prev = prev_philo;
		new_philo->id = prev_philo->id + 1;
	}
	pthread_create(&new_philo->thread, NULL, &philo_loop, new_philo);
}

void	philo_load(void)
{
	unsigned int	i;

	i = 0;
	while (i < (*input_instance()).n_philo)
	{
		philo_add(philo_create());
		i++;
	}
}
