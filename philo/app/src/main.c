/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:18:52 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 16:05:17 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/philo.h"
#include "../includes/input.h"
#include "../includes/print.h"
#include <unistd.h>
#include <stdlib.h>

static void	clear_philo(void)
{
	unsigned int	i;
	t_philo			*philo;
	t_input			*input;

	i = 0;
	input = input_instance();
	while (i < input->n_philos)
	{
		philo = *philo_instance();
		*philo_instance() = philo->next;
		pthread_mutex_destroy(&philo->fork);
		free(philo);
		i++;
	}
}

static void	init_last_eat(t_philo *philo)
{
	unsigned int	i;
	unsigned int	last_eat;
	t_input			*input;

	i = 0;
	last_eat = ph_get_time(0);
	input = input_instance();
	while (i < input->n_philos)
	{
		philo->last_eat = last_eat;
		philo = philo->next;
		i++;
	}
}

static void	supervisor(void)
{
	t_philo			*philo;
	unsigned int	max_eat;

	max_eat = 0;
	philo = *philo_instance();
	init_last_eat(philo);
	input_instance()->start = ph_get_time(0);
	while (input_instance()->to_continue)
	{
		if (ph_get_time(philo->last_eat) > input_instance()->t_die)
		{
			input_instance()->to_continue = 0;
			print_philo_die(philo);
		}
		if (philo->n_eat == input_instance()->n_eat
			&& input_instance()->n_eat >= 0
			&& !philo->checked)
		{
			max_eat++;
			philo->checked = 1;
		}
		if (max_eat == input_instance()->n_philos)
			input_instance()->to_continue = 0;
		philo = philo->next;
	}
}

int	main(int argc, char **argv)
{
	if (!input_valid_and_load(argc, argv))
		return (0);
	if (input_instance()->n_philos > 0)
	{
		philo_load();
		ph_sleep(500);
		supervisor();
		ph_sleep(500);
		philo_join();
		clear_philo();
	}
	return (0);
}
