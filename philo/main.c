/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:23:53 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 00:19:20 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "input.h"
#include "philo.h"
#include "utils.h"

#include <stdio.h>

static void	set_last_eat(void)
{
	unsigned int	i;
	unsigned int	last_eat;
	t_philo			*philo;

	i = 0;
	last_eat = get_time(0);
	philo = *philo_instance();
	while (i < input_instance()->n_philo)
	{
		philo->last_eat = last_eat;
		philo = philo->next;
		i++;
	}
}

static void	philo_clear(void)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	while (i < input_instance()->n_philo)
	{
		philo = *philo_instance();
		*philo_instance() = philo->next;
		pthread_mutex_destroy(&philo->fork);
		free(philo);
		i++;
	}
}

static void	philo_join(void)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	philo = *philo_instance();
	while (i < input_instance()->n_philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		i++;
	}
}

static void	loop(void)
{
	t_philo			*philo;
	unsigned int	count_eat;

	count_eat = 0;
	philo = *philo_instance();
	set_last_eat();
	input_instance()->start = get_time(0);
	while (input_instance()->to_continue)
	{
		if (get_time(philo->last_eat) > input_instance()->t_die)
		{
			input_instance()->to_continue = 0;
			print_action(philo, "died");
		}
		if (philo->n_eat == input_instance()->n_eat
			&& input_instance()->n_eat >= 0 && !philo->is_check)
		{
			philo->is_check = 1;
			count_eat++;
		}
		if (count_eat == input_instance()->n_philo)
			input_instance()->to_continue = 0;
		philo = philo->next;
	}
}

int	main(int argc, char **argv)
{
	if (input_validation(argc, argv) == 0)
	{
		input_helper();
		return (1);
	}
	input_load(argc, argv);
	if (input_instance()->n_philo > 0)
	{
		philo_load();
		ft_sleep(500);
		loop();
		ft_sleep(500);
		philo_join();
		ft_sleep(1000);
		philo_clear();
	}
	return (0);
}
