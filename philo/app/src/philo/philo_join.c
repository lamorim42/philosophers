/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:34 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 16:27:00 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "input.h"
#include <stdlib.h>
#include <pthread.h>

void	philo_join(void)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	philo = (*philo_instance());
	while (i < input_instance()->n_philos)
	{
		pthread_join(philo->thread, NULL);
		i++;
	}
}
