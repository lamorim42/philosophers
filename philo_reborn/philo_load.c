/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:34:21 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 11:34:54 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

void	philo_load(t_table *table)
{
	unsigned int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->input.n_philo);
	while (i < table->input.n_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].time_last_eat = table->input.start_time;
		table->philo[i].eat_count = 0;
		table->philo[i].eat_end = 0;
		table->philo[i].input = &table->input;
		pthread_mutex_init(&table->philo[i].fork, NULL);
		if (table->input.n_philo == 1)
			return ;
		if (i == table->input.n_philo - 1)
			table->philo[i].next_fork = &table->philo[0].fork;
		else
			table->philo[i].next_fork = &table->philo[i + 1].fork;
		i++;
	}
}
