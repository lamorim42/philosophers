/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:33:52 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 21:33:54 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*is_dead(void *philo_i)
{
	t_philo	*philo;

	philo = (t_philo *)philo_i;
	ft_sleep(philo->input->t_die + 1);
	pthread_mutex_lock(&philo->input->mutex_control_eat);
	pthread_mutex_lock(&philo->input->mutex_control);
	if (!is_to_stop(philo)
		&& !philo->is_end
		&& ((get_time() - philo->time_last_eat) >= (long)(philo->input->t_die)))
	{
		pthread_mutex_unlock(&philo->input->mutex_control_eat);
		pthread_mutex_unlock(&philo->input->mutex_control);
		pthread_mutex_lock(&philo->input->mutex_print);
		print_action("died\n", philo);
		pthread_mutex_unlock(&philo->input->mutex_print);
		write_to_stop(philo);
	}
	pthread_mutex_unlock(&philo->input->mutex_control_eat);
	pthread_mutex_unlock(&philo->input->mutex_control);
	return (NULL);
}

static void	*thread_routine(void *philo_i)
{
	t_philo	*philo;

	philo = (t_philo *)philo_i;
	if (philo->id % 2 == 0)
		ft_sleep(philo->input->t_eat / 10);
	while (!is_to_stop(philo))
	{
		pthread_create(&philo->death_thread, NULL, is_dead, philo_i);
		philo_loop(philo);
		pthread_detach(philo->death_thread);
		if (++philo->count_eat == philo->input->max_eat)
		{
			pthread_mutex_lock(&philo->input->mutex_control);
			philo->is_end = TRUE;
			philo->input->count_philo_eat++;
			if (philo->input->count_philo_eat == (int)philo->input->n_philo)
			{
				pthread_mutex_unlock(&philo->input->mutex_control);
				write_to_stop(philo);
			}
			pthread_mutex_unlock(&philo->input->mutex_control);
			return (NULL);
		}
	}
	return (NULL);
}

int	make_threads(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->input.n_philo)
	{
		table->philos[i].input = &table->input;
		pthread_create(&table->philos[i].main_thread, NULL, thread_routine,
			&table->philos[i]);
		i++;
	}
	return (1);
}
